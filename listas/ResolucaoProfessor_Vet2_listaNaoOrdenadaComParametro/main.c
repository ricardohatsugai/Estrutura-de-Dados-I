#include <stdio.h>
#define  MAX 1000
#define OK  1 

typedef struct lista {
	  int  v[MAX];
	  int fim;
          } lista;
struct lista l;
int init(struct lista *l)
 {
	 l->fim=-1;
	 return OK;
 }
int inserir(int v,struct lista *l)
{
	if (l->fim==MAX-1)
		 return -1;
	else{
	    l->fim++;
	    l->v[l->fim]=v;
            return OK;
	}
}

int consulta(int v, struct lista l)
{int i;
 if (l.fim==-1)
   return -1;
i=0;
while (i<=l.fim)
{
 if (l.v[i]==v)
	return i;
 else 
     i++;
}
return -1;
}


int apaga(int v,struct lista *l)
{int i;
 if (l->fim==-1)
    return -1;
 i=0;
 while (i<=l->fim)
 {
  if (l->v[i]==v)
  {//remove
   while (i<l->fim)
     {l->v[i]=l->v[i+1];
      i++;
     }
     (l->fim)--;
     return OK;
    }
   else
     i++;
 }
return -1;
}
int main()
{
 char  op;
 int i;
 int j;
 int valor,res;
 struct lista l1;
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
           init(&l1);
           break;
 case '2': 
	  printf("valor a inserir");
	  scanf("%d",&valor);
	  res=inserir(valor,&l1);
	  if (res !=OK)
            printf("cheio\n");
	  else
            printf("OK\n");
	  break;
 case '3':
	  printf("valor a consultar");
	  scanf("%d",&valor);
	  res=consulta(valor,l1);
          if(res!=-1)
		   printf("achou\n");
	    else
		    printf("nao achou\n");
          break;
 case '4': 
	  printf("valor a removerr");
	  scanf("%d",&valor);
	  res=apaga(valor,&l1);
          if(res==OK)
		   printf("achou e removeu\n");
	    else
		    printf("nao achou\n");
	    break;

 case '6': 
          i=0;
	  while(i<=l1.fim)
           {
           printf("%d -- ",l1.v[i]);
           i++;
	   }
	  printf("\n"); break;
 case 'd': 
        l1.fim=-1;
       break;
 default:
          break;     
          }
 }
  while (op !='5') ;
}