# Gebruiksaanwijzing

### opladen / vervangen batterijen
Ik heb hiervoor een oplader gekocht van aliexpress speciaal voor het type 18650 batterijen.
Maakt gebruik van een USB micro aansluitng.

### draadloze communicatie
#### verbinding maken **!ALLEEN MOGELIJK MET ANDROID** 
Ik gebruik de app "serial bluetooth" met 10k reviews in de play store.
Je moet eerst in het programma declareren dat de bluetooth wordt opgestart. Hier zal je ook een naam geven aan je bluetooth module.
Als dit gebeurt is dan voorzie je de ESP-32 van stroom.
Dan verbindt je via instellingen van je android met de gegeven naam van de ESP-32.
Dan open je de APP serial bluetooth en druk je op new connection, hier duidt je weer je esp 32 aan.
Normaal gezien komt er in de terminal "connected" te staan.
Je kan nu commandos doorsturen.

#### commando's
getPID: Vraag de huidige P, I en D waarde op.
start: Laat de robot gaan rijden.
stop: stopt de robot.
baseSpeed[0..255]: Pas de basissnelheid aan (bij een rechte lijn)
maxSpeed[0..255]: Pas de maximale snelheid aan (Om bij te sturen)
kp[0..]: Pas de Proportionele waarde aan.
Ki[0..]: Pas de Integrerende waarde aan.
Kd[0..]: Pas de Differentiërende waarde aan.

### settings
De robot rijdt stabiel met volgende parameters:
Base speed: 95
Max speed: 140
Kp: 19
Ki: 0
Kd: 10
