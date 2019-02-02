#include <16F876.h>
#device adc=10
#fuses  XT
#use    delay( clock = 4000000 )


int32 adc=512,i;
void main(void){

//SET_TRIS_A (0xff);      /* 0xff --> TRISA */
SET_TRIS_B (0x00);      /* 0x00 --> TRISB */
SET_TRIS_C (0x00);      /* 0x00 --> TRISB */
output_low(PIN_C7); 
setup_adc_ports(ALL_ANALOG);  //Se ,configuran todas las entradas del puerto a como analógicas
setup_adc(ADC_CLOCK_INTERNAL);  //Se activa el reloj interno del PIC
   
    for(i = 1;i<=adc;i++)
      {
      output_toggle(PIN_C7);
      delay_us(50);
      }
}
