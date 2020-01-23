/*  Baudinopeus 230400 
 */

const unsigned long SAMPLE_RATE = 10000;  //Näytteenottotaajuus (Hz)

unsigned long time;
double multip = 3.3 / 1024;

void setup() {
    pinMode(A0, INPUT);
    pinMode(13, INPUT);
    Serial.begin(230400);
}

void loop() {
    
    while (digitalRead(13)==HIGH){        
        time=micros();
        if ((time % (1000000/SAMPLE_RATE)==0)){
          Serial.println(analogRead(A0)*multip);
        }
    }
} 
