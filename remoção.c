struct node {
   int valor;
   struct node *esquerda;
   struct node *direita;
};

struct node* remover_folha(struct node* raiz, int valor) {
   if (raiz == NULL) return raiz; // árvore vazia
   if (raiz->esquerda == NULL && raiz->direita == NULL && raiz->valor == valor) {
      free(raiz);
      return NULL;
   }
   if (valor < raiz->valor) raiz->esquerda = remover_folha(raiz->esquerda, valor);
   else if (valor > raiz->valor) raiz->direita = remover_folha(raiz->direita, valor);
   return raiz;
}


struct node* remover_um_filho(struct node* raiz, int valor) {
   if (raiz == NULL) return raiz; // árvore vazia
   if (valor < raiz->valor) raiz->esquerda = remover_um_filho(raiz->esquerda, valor);
   else if (valor > raiz->valor) raiz->direita = remover_um_filho(raiz->direita, valor);
   else {
      if (raiz->esquerda == NULL) {
         struct node* temp = raiz->direita;
         free(raiz);
         return temp;
      }
      else if (raiz->direita == NULL) {
         struct node* temp = raiz->esquerda;
         free(raiz);
         return temp;
      }
   }
   return raiz;
}


struct node* remover_dois_filhos(struct node* raiz, int valor) {
   if (raiz == NULL) return raiz; // árvore vazia
   if (valor < raiz->valor) raiz->esquerda = remover_dois_filhos(raiz->esquerda, valor);
   else if (valor > raiz->valor) raiz->direita = remover_dois_filhos(raiz->direita, valor);
   else {
      if (raiz->esquerda == NULL) {
         struct node* temp = raiz->direita;
         free(raiz);
         return temp;
      }
      else if (raiz->direita == NULL) {
         struct node* temp = raiz->esquerda;
         free(raiz);
         return temp;
      }
      struct node* temp = min_valor(raiz->direita);
      raiz->valor = temp->valor;
      raiz->direita = remover_dois_filhos(raiz->direita, temp->valor);
   }
   return raiz;
}

struct node* min_valor(struct node* raiz) {
   struct node* atual = raiz;
