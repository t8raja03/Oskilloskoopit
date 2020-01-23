/*    Tämä sketsi käyttää keskeytyksiä näytteenotossa hyväksi, ainakin 1000Hz taajuudella toimii oikein.
 *    Isommista taajuuksista ei ole varmuutta, koska ei ole ihan varmaa mitä taajuutta lähetetään.
 *    Kerää 900 näytettä muistiin ja tulostaa Serial Plotterille/Monitorille 9600 baudin nopeudella.
 */



uint16_t samples[900];
uint16_t i = 0;
bool print = false;
unsigned int f = 1000;   //1000, 2000, 5000, 25000, 50000 tai 250000, Näytteenottotaajuus (Hz)
                          // ei mitään varmuutta toimiiko oikeasti esim 250kHz

void setup() {
  
  cli();//stop interrupts

//set timer0 interrupt
  uint8_t ocra = ((16*10^6) / (f*64) - 1);
  
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0  = 0;
  OCR0A = ocra;
  TCCR0A |= (1 << WGM01);
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  TIMSK0 |= (1 << OCIE0A);


  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  if (digitalRead(13)==HIGH)
    sei();
  if (print==true)
    printf();
}

ISR(TIMER0_COMPA_vect){

  samples[i] = analogRead(A0);
   i++;
   if (i>899) {
      i = 899;
      print = true;    
   }

}

void printf() {
  cli();
  for (int j=0; j<900; j++){
    Serial.println(samples[j]);
  }
  i=0;
  print=false;
}
