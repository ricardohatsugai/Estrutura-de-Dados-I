#include <stdio.h>
#include <stdlib.h>
typedef struct no {
                  int   val;
         struct   no  *  prox;                      
                  }no;
 
 
 
 void init(no ** l)
 { 
   *l=NULL;
   }
                                    
int insere(no **l, int val)
{
   no *p,*q;
   no *aux;
   
   aux=malloc(sizeof(no));
   if (aux==NULL)       /* erro alocacao*/
      return 0; 
    /* guarda valor */
    aux->val=val;
    if(*l==NULL) /*vazio*/
      {aux->prox=NULL;
       *l=aux;
       return 1;
     } 
     /* nao vazia - acha o local */
      p=*l;
      q=p;
      while (p!= NULL) {
       if (val <= p->val) 
        {/* achou o local */ 
        if (p==q) /* no inicio */
          { 
	  *l=aux;
	  aux->prox=p;
          }
         else{ /*meio  entre p e q */    
              aux->prox=p;
              q->prox=aux;
              }
         return 1;
         }
         else{ /*nao achaou local */
              q=p;       
              p=p->prox;
              }
         } /* while */
         /*final */
         q->prox=aux;
         aux->prox=NULL;
         return 1;                
}
  /*-----------------------------------------------*/
  
int consulta(no *lista, int val)
{
 no *p;
    p=lista;
    while (p!=NULL){
        if (val==p->val)
	     return 1;
         else
           if (val < p->val)
                return 0; 
            else 
               p=p->prox;
      } /* while */
 return 0;
}

/*-----------------------------------------------
 */  
 int remover(no **l, int val)
	 
 {
   no *p,*q;
   int suc;
   p=*l;
   q=p;

   while (p!=NULL)
    {
           if (val==p->val)
           { /* inicio, fim, meio, vazia */
            if (p==q) 
	           *l=p->prox; //INICIO 
            else
                  q->prox=p->prox;
            free(p);
            return 1;
           }
           else
              if (val < p->val)
                     return 0;
               else 
                    {q=p;
                      p=p->prox;
                     }
          }/*while*/ 
 }

 int deletex( no ** l)
 {
  no *p,*q;
  p=*l;
  *l=NULL;
  while (p!=NULL)
     {q=p;
      p=p->prox;
      free(q);
      }   
 return 1;
 }
 
void main()
{
 no * lista, *p;                                          
 int opcao;
 int val;
 int suc;
 
 while (opcao != 7){
  printf("digite opcao 1 - init 2insere 3consulta 4remocao 5-distroilista 6-print 7sai");
  scanf("%d",&opcao);
  switch (opcao){
    case 1: /* init */
          init (&lista);
          break;
    case 2: /* insere */
              printf("valor a inserir->");
              scanf("%d",&val);
              /* insere ordenado */
              suc=insere(&lista,val);
          break;
    case 3: /* consulta */
	      printf("numero a ser consultado->");
	      scanf("%d",&val);
	      suc=consulta(lista,val);
	     
	       if (suc )
		       printf("encontrado na lista\n");
	       else 
		       printf("nao encontrado o valor %d\n",val);
         break;
    case 4: /* remocao */
	      printf("numero a ser removido->");
	      scanf("%d",&val);
	       suc=remover(&lista,val);
	       if (suc)
		       printf("removido da lista\n");
	       else 
		       printf("nao encontrado o valor %d\n",val);
     	       break;
    case 5: /* delete */
               suc=deletex(&lista);
               break;
    case 6: /* print*/
               p=lista;
               while (p!=NULL){
                   printf("%d - ",p->val);
                   p=p->prox;
               }
               printf("\n");
          break;
          default:break;
  }       
}
}