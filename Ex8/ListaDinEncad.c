#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Prot?tipos

//Defini??o do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in?cio
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere in?cio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere in?cio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n?o encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

void remove_duplicatas(Lista* li) {
    if (li == NULL || *li == NULL)
        return;

    Elemento *atual = *li;

    while (atual != NULL) {
        int mat_atual = atual->dados.matricula;
        Elemento *anterior = atual;
        Elemento *verificador = atual->prox;

        while (verificador != NULL) {
            if (verificador->dados.matricula == mat_atual) {
                // Remove diretamente o verificador
                anterior->prox = verificador->prox;
                free(verificador);
                verificador = anterior->prox;
            } else {
                anterior = verificador;
                verificador = verificador->prox;
            }
        }

        atual = atual->prox;
    }
}
void fusao_listas_ordenadas(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL) return;

    Elemento* p1 = *l1;
    Elemento* p2 = *l2;
    Elemento* nova_cabeca = NULL;
    Elemento* atual = NULL;

    // Define o primeiro nó da nova lista
    if (p1 == NULL) {
        *l1 = p2;
        *l2 = NULL;
        return;
    }
    if (p2 == NULL) {
        return;
    }

    // Escolhe o primeiro nó com menor matrícula
    if (p1->dados.matricula <= p2->dados.matricula) {
        nova_cabeca = p1;
        p1 = p1->prox;
    } else {
        nova_cabeca = p2;
        p2 = p2->prox;
    }

    atual = nova_cabeca;

    // Percorre as duas listas comparando os elementos
    while (p1 != NULL && p2 != NULL) {
        if (p1->dados.matricula <= p2->dados.matricula) {
            atual->prox = p1;
            p1 = p1->prox;
        } else {
            atual->prox = p2;
            p2 = p2->prox;
        }
        atual = atual->prox;
    }

    // Liga o restante da lista não vazia
    if (p1 != NULL)
        atual->prox = p1;
    else
        atual->prox = p2;

    // Atualiza l1 para apontar para a nova lista fundida
    *l1 = nova_cabeca;

    // l2 agora está vazia
    *l2 = NULL;
}
/* Se um dos ponteiros das listas for inválido (nulo), a função retorna.
p1 aponta para o início de l1, e p2 para o de l2.
nova_cabeca será o início da nova lista fundida.
atual será usado para andar pela nova lista.
Casos especiais, se l2 estiver vazia, nao faz nada, pq já vai juntar tudo em l1
se l1 estiver vazio, basta apontar l1 para l2 e esvaziar o l2.
Após isso ele escolhe o primeiro nó e vai percorrendo ambas as listas e ordenando e
fundindo na lista nova.
Por fim ele conecta o restante de alguma das listas, caso já não tenham entrado
na comparação e finaliza apontando a nova cabeça para l1 e esvaziando l2. */