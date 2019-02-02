#include <16F877A.h>
#fuses XT,NOWDT,PUT,NOWRT
#use delay(clock= 4000000)
#use fast_io(B)
#include <LCD_2.C>
#byte puerto_B = 0x06 // Identificador para el puERTO B

int n=0;

#INT_EXT         //Atención a interrupción por cambio en RB0
ext_isr()
{             //Función de interrupción
   n++;
   if (input(PIN_B0)==0) { //Possibly just slightly 'clearer' than using not 
      EXT_INT_EDGE(L_TO_H); 
   } 
   else { 
      EXT_INT_EDGE(H_TO_L); 

   } 
}
void main(void)
{
set_tris_B(0x01);  // B0 como entrada, B7 como salida   
port_b_pullups(TRUE);   //Pull-up para RB0
enable_interrupts(int_ext);          //Habilita int. RB0…
enable_interrupts(GLOBAL);    //Habilita int. general
lcd_init();
while(1){
printf(lcd_putc, "\f n = %d  ", n);
delay_ms(1000);
}
}

