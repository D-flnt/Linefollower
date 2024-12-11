# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### Stap 1
bestel alle componenten uit de bill of materials 

### Stap 2
Test de sensoren, Gebruik de POC testcode in de repository om te controleren of de QTR-8A-sensorarray correcte waarden geeft voor zwart en wit. Controleer ook de motoren. Upload de  POC testcode om ervoor te zorgen dat beide motoren in beide richtingen correct draaien met een verschillende snelheid.

### Stap 3: Monteer de motoren en wielen
Bevestig de Micro Metal Gear Motors stevig aan het chassis.
Klik de D-gat wielen op de assen van de motoren.

### Stap 4: Plaats de batterijen en houder
Monteer de 18650 batterijhouder op het chassis.
Plaats de 18650 Li-Ion batterijen in de houder.

### Stap 5: Installeer de QTR-8A Reflectance Sensor Array
Bevestig de QTR-8A sensorarray aan de onderkant van het chassis (zie foto), zodat deze ongeveer een paar mm boven de grond hangt.

### Stap 6: Bedrading en Breadboard
Plaats het breadboard op de geschikte plaats chassis. Maak alle verbindingen tussen de batterijhouder, schakelaar, ESP32, DRV8833, en sensoren volgens het elektrisch schema te vinden in deze repository.

Tuimelschakelaar: Gebruik een bistabiele tuimelschakelaar om de stroom van de batterijhouder naar het breadboard te onderbreken. De schakelaar wordt in serie geplaatst met de positieve voedingslijn van de batterijen (tussen de + van de batterijhouder en de VCC van het breadboard). Hierdoor kun je de robot gemakkelijk in- en uitschakelen zonder de batterijen handmatig te verwijderen.

### Stap 7: Code uploaden
Download de Arduino IDE en installeer de ESP32-bibliotheek.
Compileer de code en upload deze naar de ESP32 via een USB-kabel.
