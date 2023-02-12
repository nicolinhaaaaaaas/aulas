#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;

}No;

typedef struct{
    No *raiz;
}ArvB;

No* inserirNovaVersao(No *raiz, int valor){
    if(raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else{
        if(valor < raiz->conteudo)
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        if(valor > raiz->conteudo)
            raiz->direita = inserirNovaVersao(raiz->direita, valor);
        return raiz;
    }
}

int tamanho(No *raiz){
    if(raiz == NULL)
        return 0;
    else    
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf(" %d", raiz->conteudo); 
        imprimir(raiz->direita);
        
    }
}

int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL; //quando se está manipulando o objeto se usa Ponto, no lugar de seta

    No *raiz = NULL;

    do{
        printf("\n 0 - Sair \n 1 - inserir \n 2 - imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("\n Saindo... \n");
                break;
            case 1:
                printf("Digite um valor:");
                scanf("%d", &valor);
                raiz = inserirNovaVersao(raiz, valor);
                //inserir(&arv, valor);
                break;
            case 2:
                printf("\n Impressao da arvore binaria: \n");
                imprimir(raiz);
                printf("\n");
                printf("Tamanho: %d\n", tamanho(raiz));
                break;
                
            default:
                printf("\n Opcao invalida... \n");
        }
    }while(op != 0 );

}
