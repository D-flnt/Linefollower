# H-Bridge proof of concept

Minimale hard- & software die aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.

### Stappen:
1. Sluit de motoren aan volgens schema (OUT1, OUT2 voor motor 1, OUT3, OUT4 voor motor 2).
2. Sluit de ingangen van de H-brug volgens het schema voorzien in deze repository.
3. Sluit de **STBY** pin aan op de 3.3 V pin van de ESP-32.
4. Sluit **VCC**, **GND**, en **VM** aan volgens het schema.
5. Upload het programma en kijk of de motoren op verschillende sneleden en richtingen draaien.
