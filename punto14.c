//Diseñar una solución programable de manera tal que en el Puerto A se refleje el valor
//del Puerto B con un desplazamiento lógico a la derecha. Utilizar el operador >>.
#include "MKL25Z4.h"
int main(){
 SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|=SIM_SCGCS_PORTB_MASK;
 
for(i=0; i<32; i++){
    PORTB->PCR[i]|=PORT_PCR_MUX(0);

 PORTA->PCR[i]|=PORT_PCR_MUX(1);
} 

while(1){
for(i=0; i<32; i++){

int ETADO =PTB->PDIR&(1<<i);
int DESDERECHA = (ETADO >>1);
PTA-> PDOR |= DESDERECHA;
} 
} 
return 0;
}   