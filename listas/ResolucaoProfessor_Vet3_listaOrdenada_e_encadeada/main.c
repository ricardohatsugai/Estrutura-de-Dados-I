#include <stdio.h>
#define  MAX 1000
#define OK  1 

typedef struct no {
	  int  v;
	  int  prox;
          } no;
typedef  struct lista{
       int i;
       int f;
       struct no s[MAX];} lista;
       
struct lista l;

int init()
 {
	 l.f=-1;
     l.i=-1;
	 return OK;
 }
int inserir(int v)
{   int p,q;
    if ((l.i)==-1)
     {
      l.i=0;
      l.f=0;
      l.s[0].v=v;
      l.s[0].prox=-1;
      return OK;
      }
      //cheio 
    if (l.f==MAX-1)
		 return -1;    // cheio 

   //guarda valor 
    l.f++;
    l.s[l.f].v=v;   
    //achar o local para inserir 
	p=l.i;
    q=p;
    while (p!=-1) 
    {
     if (v<=l.s[p].v)
         {//achou local 
          if (p==l.i) //inserir antes do incio
            {
             l.s[l.f].prox=l.i;
             l.i=l.f;
            }
            else //meio 
             {
              l.s[l.f].prox=p;
              l.s[q].prox=l.f;} 
            return OK; 
         } //achou local
     else
         {//proximo 
         q=p;
         p=l.s[p].prox;}
    
    }//p!=-1
    
    // fim 
    l.s[q].prox=l.f;
    l.s[l.f].prox=-1;
    return OK; 
} //insere

int consulta(int v)
{int i;
 i=l.i; //inicio lista 
 while (i != -1 )
 {
  if (v == l.s[i].v) 
   return i;    //achou 
  else 
    if (v < l.s[i].v)
      return -1;
    else 
       i=l.s[i].prox;
 }  //while 
 // nao pertence 
return -1;
}

int apaga(int v)
{int p,q;
 p=l.i; //inicio lista 
 q=p;
 while (p != -1 )
 {
  if (v == l.s[p].v) 
   { // remove 
     if (p==l.i)  // remover o no do inicio 
        l.i=l.s[l.i].prox;
      else 
        l.s[q].prox=l.s[p].prox;    //meio final 
    return OK;
   }  
  else 
    if (v < l.s[p].v)
      return -1;
    else 
       p=l.s[p].prox;
 }  //while 
 
return -1;  // nao achou para remocao 
}

int main()
{
 char  op;
 int i;
 int j;
 int valor,res;
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
           init();
           break;
 case '2': 
	  printf("valor a inserir");
	  scanf("%d",&valor);
	  res=inserir(valor);
	  if (res !=OK)
            printf("cheio\n");
	  else
            printf("OK\n");
	  break;
 case '3':
	  printf("valor a consultar");
	  scanf("%d",&valor);
	  res=consulta(valor);
          if(res!=-1)
		   printf("achou\n");
	    else
		    printf("nao achou\n");
          break;
 case '4': 
	  printf("valor a removerr");
	  scanf("%d",&valor);
	  res=apaga(valor);
          if(res==OK)
		   printf("achou e removeu\n");
	    else
		    printf("nao achou\n");
	    break;

 case '6': 
        i=l.i;
	    while(i != -1 )
           {
           printf("%d -- ",l.s[i].v);
           i=l.s[i].prox;
	   }
	  printf("\n"); break;
 case 'd': 
        l.f=-1;
        l.i=-1;
       break;
 default:
          break;     
          }
 }
  while (op !='5') ;
}