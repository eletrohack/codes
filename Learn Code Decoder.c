#define RFIn PIN_B0 //entrada do sinal de RF
#define NBIT 28 // numero de bits


INT32 DATA=0;

int1 decoder(void)
{
  byte x=0;
  int16 time_aux=0;
  DATA=0;

   while(!input_state(RFIn)){
    time_aux++;
    delay_us(10);
   }

if((time_aux>1149) || (time_aux<=1151)){

  for(x=0;x<NBIT;x++){

   while(input_state(RFin));
   delay_us(250);

   if(input_state(RFIn)){
    return FALSE;
    }

   delay_us(500);
   if(!input_state(RFIn)){
    data|=0x8000000;
    data>>=1;
}
else data>>=1;

 delay_us(500);
 if(!input_state(RFin)){
   return FALSE;
  }


 }
return TRUE;
}
else return FALSE;

}