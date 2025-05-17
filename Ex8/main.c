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

    Lista* lista1 = cria_lista();
    Lista* lista2 = cria_lista();

    insere_lista_ordenada(lista1, (struct aluno){1, "A", 7,7,7});
    insere_lista_ordenada(lista1, (struct aluno){3, "B", 8,8,8});

    insere_lista_ordenada(lista2, (struct aluno){2, "C", 6,6,6});
    insere_lista_ordenada(lista2, (struct aluno){4, "D", 9,9,9});

    printf("Lista 1:\n");
    imprime_lista(lista1);
    printf("Lista 2:\n");
    imprime_lista(lista2);

    fusao_listas_ordenadas(lista1, lista2);

    printf("Lista fundida:\n");
    imprime_lista(lista1); // Lista1 agora contém os 4 elementos ordenados

}
