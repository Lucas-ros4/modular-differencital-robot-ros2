# Modular Differential Robot (ROS 2 Humble & ESP32)

<img width="1600" height="1200" alt="turtleRos" src="https://github.com/user-attachments/assets/ca434f45-f667-44f8-9a16-518134940a63" />



Um robô móvel diferencial de baixo custo, altamente modular e de fácil fabricação. Este projeto foi projetado para servir como uma plataforma robusta de desenvolvimento para robótica educacional, pesquisa e experimentação prática com ROS 2.

**Modelos 3D (Thingiverse):** https://www.thingiverse.com/thing:7404548

---

## Sobre o Projeto

A ideia central deste projeto é oferecer uma alternativa acessível e maleável para quem deseja estudar e aplicar robótica móvel sem depender de kits comerciais caros e fechados. O design mecânico foi inspirado e remixado a partir de outros modelos da comunidade, priorizando a facilidade de impressão 3D e montagem.

A arquitetura foi pensada para crescer junto com o desenvolvedor:
- **Fase atual:** Focada em controle de baixo nível, atuação com motores DC, aquisição de odometria via encoders (controle PID) e integração com o microcontrolador ESP32-S3.
- **Evolução futura:** Expansão para computação de bordo com **Raspberry Pi 4**, integração de **LiDAR** para mapeamento e navegação (SLAM/Nav2) e experimentação avançada com **Aprendizado por Reforço (Reinforcement Learning)**.

---

## Especificações Técnicas (Hardware Atual)

| Componente | Especificação / Modelo | Função Principal |
| :--- | :--- | :--- |
| **Microcontrolador** | ESP32-S3 | Processamento de baixo nível, leitura de encoders e controle PID |
| **Atuação** | 2x Motores JGA25-370 (com encoders) | Tração diferencial e feedback preciso de velocidade |
| **Driver de Motor** | TB6612FNG | Ponte H para controle de direção e potência dos motores |
| **Alimentação** | Pack 18650 (3S3P) + BMS 3S | Gerenciamento de energia e autonomia prolongada |
| **Regulação** | Regulador de Tensão | Estabilização dos níveis lógicos e de potência para os circuitos |
| **Estrutura** | Impressa em 3D | Chassi modular e suporte para a eletrônica (Remix) |

---

## Eletrônica e Esquemático

Abaixo está o diagrama de ligações elétricas detalhando a conexão entre o ESP32-S3, o driver de motor, os encoders e o sistema de alimentação.

<img width="1122" height="629" alt="turtleRos" src="https://github.com/user-attachments/assets/4f84507b-f76a-45b6-81af-dfd4b04b1a30" />

[TurtleRos.pdf](https://github.com/user-attachments/files/31802662/TurtleRos.pdf)

---

## Roadmap e Expansões Futuras

- [ ] Ajuste fino do controle PID dos motores JGA25-370 usando os encoders.
- [ ] Integração com **Raspberry Pi 4** para processamento de alto nível (ROS 2 Humble).
- [ ] Adição de sensor **LiDAR** 2D para mapeamento de ambientes.
- [ ] Implementação da stack de navegação autônoma (Nav2 / SLAM).
- [ ] Treinamento e deploy de agentes de **Aprendizado por Reforço (RL)**.
- [ ] Adição de novos suportes modulares para sensores extras (câmeras, IMU, etc).

---

## Organização do Repositório

```text
Atualmente, o código no GitHub é voltado para testes dos motores e da eletrônica. Ele inclui um script para descobrir o endereço MAC do ESP32-S3, um código para o ESP32 com joystick duplo controlar o robô, e o código embarcado no robô para receber esses comandos via ESP-NOW.
