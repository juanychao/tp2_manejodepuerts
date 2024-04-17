#include "MKL25Z4.h"
int main(){
 SIM->SCGCS|=SIM_SCGCS_PORTA_MASK|=SIM_SCGCS_PORTB_MASK;
 
for(i=0; i<32; i++){
    PORTB->PCR[i]|=PORT_PCR_MUX(0);

 PORTA->PCR[i]|=PORT_PCR_MUX(1);
}
    while (1){
        int PuertoB = PTB -> PDIR;
        int Operacion = PuertoB | 0x23;
        PTA -> PDOR |= Operacion; 
    }
return 0;

}
