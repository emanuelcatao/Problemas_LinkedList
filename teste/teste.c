#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int qnt;
    int vetor[N];
} Lista;

void colocar_numero(int i, Lista *l1); 
void remover_numero(int i, Lista *l1);
void print_lista(int i, Lista *l1);
void procurar_numero(int i, Lista *l1);

int main(){
    char c; int i;
    Lista lista1;
    lista1.qnt=0;

    do{
        scanf("%c %i", &c, &i);

        while (getchar() != '\n');

        switch(c){
            case 'i': {
                colocar_numero(i,&lista1);    
                break;
            }
            case 'r': {
                remover_numero(i,&lista1);    
                break;
            }
            case 'p': {
                print_lista(i,&lista1);
                break;
            }
            case 's': {
                procurar_numero(i,&lista1);
                break;
            }
        }


    } while(c!='q' || i!=0);

    return 0;
}

void colocar_numero(int i, Lista* l1)
{
    if(l1->qnt<5){
        l1->vetor[l1->qnt]=i;
        printf("success\n");
        l1->qnt++;
    }
    else
        printf("fail\n");

}

void remover_numero(int i, Lista* l1)
{
    int j=0, aux=0,sucesso=0;
    int tam=l1->qnt;
    if(tam<=0)
        printf("fail\n");
    for(j=0;j<tam;j++){
        if(l1->vetor[j]==i){
            sucesso++;
            for(aux=j;aux<tam;aux++){
                l1->vetor[aux]=l1->vetor[aux+1];
            }
            l1->qnt--;
        }
    }
    if(sucesso>=1)
        printf("success\n");
    else
        printf("not found\n");
}
void print_lista(int i, Lista* l1) 
{
  if(i!=0)
    printf("fail\n");
  else{
    int j;
    for(j=0;j<l1->qnt;j++)
        printf("%d, ",l1->vetor[j]);
    putchar('\n');
  }
}

void procurar_numero(int i, Lista* l1)
{
  int j, sucesso=0;
  for(j=0;j<l1->qnt;j++){
    if(l1->vetor[j]==i){
      printf("%d\n",j);
      sucesso++;
    }
  }
  if(sucesso<=0)
    printf("not found\n");
}