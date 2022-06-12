#include <stdio.h>
#define  MAX 1000
typedef struct {
	  int lista[MAX];
	  int p;
          }list;

int main()
{
 char  op;
 int i;
int j;
int valor,retorno;
 list l1;
 do 
 { 
 printf("\n------LISTA ESTATICA VETOR NAO ORD --------\n");
 printf("i-Inicializar\n");
 printf("2-insercao\n");
 printf("3-consultar\n");
 printf("4-remocao\n"); 
 printf("5-saida\n");
 printf("6-print\n");
 printf("d-apagar\n");
 scanf("%c",&op);
 switch (op) {
 case 'i': /* inicializa lista */
           l1.p=-1;
           break;
 case '2': 
	  printf("valor a inserir");
	  scanf("%d",&valor);
	  if ((l1.p+1)==MAX)
            printf("cheio\n");
	  else
             {
		l1.p++;
		l1.lista[l1.p]=valor;
	        printf("insere ok\n");
	     }break;
 case '3':
	  printf("valor a consultar");
	  scanf("%d",&valor);
	  if(l1.p== -1)
            retorno=0;
	  else{
	      i=0;
            retorno=0;
	      while((i<=l1.p) && !(retorno))
	        if (valor==l1.lista[i])
	       	  retorno=1;
                 else i++;
	      }
          if(retorno)
		   printf("achou\n");
	    else
		    printf("nao achou\n");
          break;
 case '4': 
	  printf("valor a removerr");
	  scanf("%d",&valor);
	  if(l1.p== -1)
            retorno=0;
	  else{
	      retorno=0;
            i=0;
	      while((i<=l1.p) && !(retorno))
	        if (valor==l1.lista[i])
		   { while (i<l1.p)
			{
			l1.lista[i]=l1.lista[i+1];
			i++;
			}
			l1.p--;
			retorno=1;
                }
                 else i++;
	      }
          if(retorno)
		   printf("achou\n");
	    else
		    printf("nao achou\n");
	    break;

 case '6': 
          i=0;
	  while(i<=l1.p)
           {
           printf("%d -- ",l1.lista[i]);
           i++;
	   }
	  printf("\n"); break;
 case 'd': 
        l1.p=-1;
       break;
 default:
          break;     
          }
 }
  while (op !='5') ;
}