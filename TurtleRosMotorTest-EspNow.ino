// === TRANSMISSOR - JOYSTICK (ESP32-WROOM) ===
#include <WiFi.h>
#include <esp_now.h>

// MAC DO RECEPTOR (ESP32-S3)
uint8_t macReceptor[] = {0x80, 0xB5, 0x4E, 0xC5, 0xE8, 0x20};

#define PIN_VRX  34
#define PIN_VRY  35
#define PIN_SW   32

typedef struct struct_mensagem {
  int8_t eixoY;
  int8_t eixoX;
  bool   botao;
} struct_mensagem;

struct_mensagem dados;
esp_now_peer_info_t peerInfo;

// ====== CALLBACK CORRIGIDO (Core 3.x) ======
void aoEnviar(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  Serial.print("Envio: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "OK" : "FALHOU");
}

int lerEixo(int pino) {
  int valor = analogRead(pino);
  valor = map(valor, 0, 4095, -100, 100);
  if (valor > -15 && valor < 15) valor = 0;
  return constrain(valor, -100, 100);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_SW, INPUT_PULLUP);
  analogReadResolution(12);

  WiFi.mode(WIFI_STA);
  Serial.print("MAC deste ESP: ");
  Serial.println(WiFi.macAddress());

  if (esp_now_init() != ESP_OK) {
    Serial.println("Falha ao iniciar ESP-NOW");
    while (true) delay(100);
  }

  esp_now_register_send_cb(aoEnviar);

  memcpy(peerInfo.peer_addr, macReceptor, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Falha ao adicionar receptor");
    while (true) delay(100);
  }

  Serial.println("Transmissor pronto!");
}

void loop() {
  dados.eixoY = -lerEixo(PIN_VRY);
  dados.eixoX = lerEixo(PIN_VRX);
  dados.botao = (digitalRead(PIN_SW) == LOW);

  esp_now_send(macReceptor, (uint8_t *)&dados, sizeof(dados));

  Serial.printf("Y: %d | X: %d | Botao: %d\n",
                dados.eixoY, dados.eixoX, dados.botao);

  delay(50);
}