#include <WiFi.h>
#include <esp_wifi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inicializa o Wi-Fi no modo Station
  WiFi.mode(WIFI_STA);
  WiFi.begin(); // Garante inicialização da pilha de rede

  Serial.println("\n--- MAC PARA ESP-NOW ---");
  
  // Forma direta e segura de pegar o MAC do Wi-Fi Station
  uint8_t mac[6];
  esp_wifi_get_mac(WIFI_IF_STA, mac);
  
  char macStr[18];
  sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
  
  Serial.print("MAC Wi-Fi (Use este no ESP-NOW): ");
  Serial.println(macStr);
  Serial.println("------------------------");
}

void loop() {
  // Nada aqui
}