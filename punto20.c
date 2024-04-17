/* 20. Diseñar una solución programable de manera tal que las salidas A0 y A1 se activen si
B0 está activo, las salidas A2 y A3 se activen si B1 está activo, las salidas A4 y A5 se activen
si B2 está activo, las salidas A6 y A7 se activen si B3 está activo.*/
#include "MKL25Z4.h"
int pines0 []{0,1}
int pines2 []{2,3}
int pines4 []{4,5}
int pines6 []{6,7};

int main(){
 SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|=SIM_SCGCS_PORTB_MASK;
    PORTB-> PCR[0]|=PORT_PCR_MUX(0);
    PORTB-> PCR[1]|=PORT_PCR_MUX(0);
    PORTB-> PCR[2]|=PORT_PCR_MUX(0);
    PORTB-> PCR[3]|=PORT_PCR_MUX(0);

for(i=0; i<8; i++){
    PORTA->PCR[pines0]|=PORT_PCR_MUX(1);
    PORTA->PCR[pines2]|=PORT_PCR_MUX(1);
    PORTA->PCR[pines4]|=PORT_PCR_MUX(1);
    PORTA->PCR[pines6]|=PORT_PCR_MUX(1);
} 
while (1)
{
 int ETADO0 = (PTB-> PDIR &(1<<0));
 int ETADO1 = (PTB-> PDIR &(1<<1));
 int ETADO2 = (PTB-> PDIR &(1<<2));
 int ETADO3 = (PTB-> PDIR &(1<<3));
 if((ETADO0==1) && (ETADO1==0) && (ETADO2==0) && (ETADO3==0)){
     for(i=0;i<8; i++){
        PORTA-> PSOR|= (1u<<pines0[i]);
        PORTA-> PSOR|= (0u<<pines2[i]);
        PORTA-> PSOR|= (0u<<pines4[i]);
        PORTA-> PSOR|= (0u<<pines6[i]);
    }
 else if((ETADO1==1) && (ETADO0==0) && (ETADO2==0) && (ETADO3==0)){
   for(i=0;i<8; i++)
    PORTA-> PSOR|= (0u<<pines0[i]);
    PORTA-> PSOR|= (1u<<pines2[i]);
    PORTA-> PSOR|= (0u<<pines4[i]);
    PORTA-> PSOR|=(0u<<pines6[i]);
    } 
    else if((ETADO2==1) && (ETADO1==0) && (ETADO0==0) && (ETADO3==0)){
   for(i=0;i<8; i++)
    PORTA-> PSOR|= (0u<<pines0[i]);
    PORTA-> PSOR|= (0u<<pines2[i]);
    PORTA-> PSOR|= (1u<<pines4[i]);
    PORTA-> PSOR|=(0u<<pines6[i]);
    } 
    else if((ETADO3==1) && (ETADO1==0) && (ETADO2==0) && (ETADO0==0)){
   for(i=0;i<8; i++)
    PORTA-> PSOR|= (0u<<pines0[i]);
    PORTA-> PSOR|= (0u<<pines2[i]);
    PORTA-> PSOR|= (0u<<pines4[i]);
    PORTA-> PSOR|=(1u<<pines6[i]);
    } 
 }
}
return 0;
}
