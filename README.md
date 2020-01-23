# Oskilloskoopit

Kytkennät:

- Nucleon GND -> Arduinon GND
- Nucleo A2 -> Arduino A0
- Nucleo D2 -> Arduino 13

Laita main.cpp SineExample-kansioon, sitten puske koodi Nucleoon

Paina reset Nucleosta, Arduinon Serial Plotterille tulostuu käyrää. Lähettää D2 pinnistä HIGH arduinon 13-pinniin, mitattava signaali kulkee analogipinnien välillä.

Oskilloskooppi_ISR käyttää keskeytyksiä, ja ottaa puskuriin talteen 900 näytettä, tulostaa ne sitten näytölle. Taajuus pitäisi olla valittavissa tietyistä arvoista, en ole varma toimiiko. (f) Tämän pitäisi olla tarkka.

Oskilloskooppi live tulostaa "suorana" määrätyllä näytteenottotaajuudella (SAMPLE_RATE), kun 13-pinniin tulee HIGH.
