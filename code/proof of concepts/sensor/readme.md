# Sensoren proof of concept

Minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing).

### Stappen:
1. Zorg voor een **ESP32** en een **QTR-8 Sensor**.
2. Sluit de **VCC** pin van de sensor aan op **3.3V** van de ESP32.
3. Sluit de **GND** pin van de sensor aan op de **GND** van de ESP32.
4. Sluit de **analoge ingangen** van de sensor aan op de **analoge ingangen** van de ESP32 (bijvoorbeeld GPIO36, GPIO39, GPIO34, GPIO35, GPIO32, GPIO33).
5. Voorzie de ESP32 van spanning.
6. Upload het programma naar de ESP32.
7. Kijk in de seriële monitor (debugger) en het resultaat zou als volgt uit moeten zien.
