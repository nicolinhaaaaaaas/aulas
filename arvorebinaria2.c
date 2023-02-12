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

int tamanho(No *raiz){ //pra ver o tamanho da arvore
    if(raiz == NULL)
        return 0;
    else    
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
}

int buscar(No *raiz, int chave){
    if(raiz == NULL){
        return 0; //se retornar 0 é pq n tem na arvore
    }
    else{
        if(raiz->conteudo == chave)
            return 1; // se retornar 1 é pq tem na arvore
        else{
            if(chave < raiz->conteudo)
                return buscar(raiz->esquerda, chave);
            else
                return buscar(raiz->direita, chave);
        }
    }
}

void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf(" %d", raiz->conteudo); 
        imprimir(raiz->direita);
        
    }
}

No* remover(No *raiz, int chave){
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else{
        if(raiz->conteudo == chave){
            //remove nos folhas (nos sem filhos)
            if(raiz->esquerda ==NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else{
            // remover nós que possuem apenas 1 filho, na direita ou na esquerda
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else    
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;            
                }
            }
        }
        else{
            if(chave < raiz->conteudo)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL; //quando se está manipulando o objeto se usa Ponto, no lugar de seta

    No *raiz = NULL;

    do{
        printf("\n 0 - Sair \n 1 - inserir \n 2 - imprimir\n 3 - Buscar\n 4 - remover\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("\n Saindo... \n");
                break;
            case 1:
                printf("\n Digite um valor:");
                scanf("%d", &valor);
                raiz = inserirNovaVersao(raiz, valor);
                break;
            case 2:
                printf("\n Impressao da arvore binaria: \n");
                imprimir(raiz);
                printf("\n");
                printf("Tamanho: %d\n", tamanho(raiz));
                break;
            case 3:
                printf("\n Qual valor deseja buscar?");
                scanf("%d", &valor);
                printf("Resultado da busca: %d\n", buscar(raiz, valor));
                break;
            case 4:
                printf("\n Digite um valor a ser removido:");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                printf("\n Valor removido.");
                break;
            default:
                printf("\n Opcao invalida... \n");
        }
    }while(op != 0 );

} 
