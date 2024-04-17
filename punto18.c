/*Diseñar una solución programable de manera tal que las salidas A0, A1, A2 y A3 se
activen si B0 está activo; y las salidas A4, A5, A6 y A7 se activen si B0 está inactivo.*/
#include "MKL25Z4.h"

int pines0  []{0,1,2,3}
int pines4 []{4,5,6,7};

int main(){
 SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|=SIM_SCGCS_PORTB_MASK;
    PORTB->PCR[0]|=PORT_PCR_MUX(0);

for(i=0; i<8; i++){
    PORTA->PCR[pines0]|=PORT_PCR_MUX(1);
    PORTA->PCR[pines4]|=PORT_PCR_MUX(1);
} 
while (1)
{
 int ETADO = (PTB-> PDIR &(1<<0));
 if(ETADO==0){
    for(i=0;i<4; i++)
    PORTA-> PSOR|= (1u<<pines0[i]);
    PORTA-> PSOR|=(0u<<pinesi4[i]);
    } 
 else if(ETADO==1){
    for(i=0;i<4; i++){
        PORTA-> PSOR|= (1u<<pines0[i]);
        PORTA-> PSOR|= (0u<<pines4[i]);
    }
 }
}
return 0;
}