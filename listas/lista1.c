#include <stdio.h>
#include <string.h>
#define alturaMaxima 255

typedef struct{
   int peso; // peso em quilogramas
   int altura; // altura em centimetros
} PesoAltura;

int main(){
    PesoAltura pessoa1;
    pessoa1.peso = 85;
    pessoa1.altura = 175;

    printf("O peso é %i, Altura %i.\n", pessoa1.peso, pessoa1.altura);

    if (pessoa1.altura > alturaMaxima)
	printf("Altura acima da máxima.\n");
    else 
	printf("Altura abaixo da máxima.\n");

    return 0;
}
