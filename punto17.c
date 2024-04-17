/* 17. Diseñar una solución programable de manera tal que las salidas A0, A2, A4 y A6 se
activen si B0 está inactivo; y las salidas A1, A3, A5 y A7 se activen si B0 está activo. */
#include "MKL25Z4.h"

int pinesp  []{0,2,4,6}
int pinesip []{1,3,5,7};

int main(){
 SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|=SIM_SCGCS_PORTB_MASK;
    PORTB->PCR[0]|=PORT_PCR_MUX(0);

for(i=0; i<8; i++){
    PORTA->PCR[pinesp]|=PORT_PCR_MUX(1);
    PORTA->PCR[pinesip]|=PORT_PCR_MUX(1);
} 
while (1)
{
 int ETADO = (PTB-> PDIR &(1<<0));
 if(ETADO==0){
    for(i=0;i<4; i++)
    PORTA-> PSOR|= (1u<<pinesp[i]);
    PORTA-> PSOR|=(0u<<pinesip[i]);
    } 
 else if(ETADO==1){
    for(i=0;i<4; i++){
        PORTA-> PSOR|= (1u<<pinesip[i]);
        PORTA-> PSOR|= (0u<<pinesp[i]);
    }
 }
}
return 0;
}
   