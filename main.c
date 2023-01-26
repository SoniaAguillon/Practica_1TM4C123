
#include "lib/include.h"

typedef struct ElementoLista {
char *dato;
struct ElementoLista *siguiente;
}Elemento;

typedef struct ListaIdentificar {
Elemento *inicio;
Elemento *fin;
int tamaño;
}Lista;

unsigned long Led;

void Delay(void){unsigned long volatile time;
  time = 1600000;
  while(time){
		time--;
  }
}

int main(void){

  SYSCTL->RCGCGPIO |=(1<<5); // 1) activate clock for Port F
  GPIOF->LOCK = 0x4C4F434B;  // 2) unlock GPIO Port F
  GPIOF->CR = (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);  // allow changes to PF4-0 **Es lo mismo que 1F**
  GPIOF->AMSEL = 0x00; // 3) disable analog on PF
  GPIOF->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIOF->DIR = 0x0E; // 5) PF4,PF0 in, PF3-1 out
  GPIOF->AFSEL = 0x00;        // 6) disable alt funct on PF7-0
  GPIOF->PUR = 0x11;          // enable pull-up on PF0*Estado 1* and PF4*Estado0*
  GPIOF->DEN = 0x1F;          // 7) enable digital I/O on PF4-0  **SE ESTA TRABAJANDO COMO DIGITAL PAG1351
  //SYSCTL->RCGC2 |= 0x00000020;
 // SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
  //GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  //GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  //GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  //GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  //GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  //GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  //GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  //GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
  while(1){
   //if(PF4 == 0x0){
    Led = 0x02;            // reverse value of LED
    GPIOF->DATA = Led;   // write value to PORTF DATA register,toggle led
    Delay();
    Led = 0x04;            // reverse value of LED
    GPIOF->DATA = Led;   // write value to PORTF DATA register,toggle led
    Delay();
    Led = 0x08;            // reverse value of LED
    GPIOF->DATA = Led;   // write value to PORTF DATA register,toggle led
    Delay();
    Led = 0x0A;            // reverse value of LED
    GPIOF->DATA = Led;   // write value to PORTF DATA register,toggle led
    Delay();
   // }
  }
}
