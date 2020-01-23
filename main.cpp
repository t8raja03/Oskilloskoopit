#include "mbed.h"
#define SAMPLES_CNT 1000
#define PERIOD_CNT 33
#define PI 3.141592653589793238462
AnalogOut dac(PA_4); //PA_4 alias A2
AnalogIn adc(A0);
DigitalInOut sig(D2);
void calculate_sinewave(void); //sine generation function
uint16_t dac_buffer[SAMPLES_CNT];
float adc_buffer[SAMPLES_CNT];
int main()
{
 sig.output();
 sig = 0;
 //printf("Sine generation");
 calculate_sinewave();
 sig = 1;
 for (int i = 0; i < SAMPLES_CNT; i++)
 {
 dac.write_u16(dac_buffer[i]);
 adc_buffer[i]=(float)3.3*adc.read();
 wait_us(1000);
 }
 sig = 0;
 //printf("ADC sampling done\n\r");
 //for (int i = 0; i < SAMPLES_CNT; i++) printf("%f\n\r", adc_buffer[i]);

}
void calculate_sinewave(void) //sine generation
{
 for (int i = 0; i < SAMPLES_CNT; i++)
 {
 dac_buffer[i]=32768*cos(2*PI*i/PERIOD_CNT)+32767; //
 }
}
