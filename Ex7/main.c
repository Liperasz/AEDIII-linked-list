#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

void remove_duplicatas(Lista* li);

int main(){
    struct aluno al, a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));

    int i;
    // Inserindo elementos originais
    for(i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);

    imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n", tamanho_lista(li));

    // Removendo todos
    for(i = 0; i < 4; i++) {
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n", tamanho_lista(li));
    }

    // Inserindo novamente + Duplicatas
    insere_lista_ordenada(li, a[0]); // Andre - 2
    insere_lista_ordenada(li, a[1]); // Ricardo - 4
    insere_lista_ordenada(li, a[2]); // Bianca - 1
    insere_lista_ordenada(li, a[3]); // Ana - 3
    insere_lista_ordenada(li, a[0]); // Andre duplicado - 2
    insere_lista_ordenada(li, a[2]); // Bianca duplicada - 1

    printf("\nLista com duplicatas:\n");
    imprime_lista(li);

    // Removendo duplicatas
    remove_duplicatas(li);

    printf("\nLista após remover duplicatas:\n");
    imprime_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}
