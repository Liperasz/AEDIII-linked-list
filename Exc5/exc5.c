//
// Created by liperasz on 15/05/25.
//

#include "exc5.h"
#include <stdio.h>
#include <stdlib.h>

List* Create_List() {

    List* list = malloc(sizeof(List));
    if (list != NULL) {
        *list = NULL;
    }

    return list;
}

void Free_List(List* list) {

    if (list != NULL) {
        while ((*list) != NULL) {

            Element *element = *list;
            *list = (*list)->next;
            free(element);
        }
        free(list);
    }

}

int Insert_First_List(List* list, int data) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;
    element->next = (*list);
    *list = element;

    return 1;
}

int Insert_Last_List(List* list, int data) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;
    element->next = NULL;

    if (*list == NULL) {
        *list = element;
    }
    else {
        Element* last = *list;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = element;
    }

    return 1;
}

int Insert_Order_List(List* list, int data) {

    if (list == NULL) {
        return 0;
    }

    Element *element = malloc(sizeof(Element));
    if (element == NULL) {
        return 0;
    }

    element->data = data;

    if (*list == NULL) {
        element->next = NULL;
        *list = element;
        return 1;
    }

    Element* before = NULL;
    Element* current = *list;

    while (current != NULL && current->data < data) {
        before = current;
        current = current->next;
    }

    if (current == *list) {
        element->next = *list;
        *list = element;
        return 1;
    }

    if (before != NULL) {
        element->next = current;
        before->next = element;
        return 1;
    }

    return 0;
}

int Remove_First_List(List* list) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    Element *first = *list;
    *list = (*list)->next;
    free(first);

    return 1;
}

int Remove_Last_List(List* list) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    Element *before = NULL;
    Element *current = *list;

    while (current->next != NULL) {
        before = current;
        current = current->next;
    }

    if (current == *list) {
        *list = current->next;
        free(current);
        return 1;
    }

    if (before != NULL) {
        before->next = current->next;
        free(current);
        return 1;
    }

    return 0;

}

int Remove_List(List* list, int data) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    Element *before = NULL;
    Element *current = *list;

    while (current != NULL && current->data != data) {
        before = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    if (current == *list) {
        *list = current->next;
        free(current);
        return 1;
    }

    if (before != NULL) {
        before->next = current->next;
        free(current);
        return 1;
    }

    return 0;
}

int List_Length(List* list) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    int cont = 0;
    Element *element = *list;

    while (element != NULL) {
        cont += 1;
        element = element->next;
    }

    return cont;
}

int List_Is_Empty(List* list) {

    if (list == NULL || (*list) == NULL) {
        return 1;
    }

    return 0;
}

int List_Is_Full(List* list) {

    return 0;

}

void Print_List(List* list) {

    if (list != NULL) {
        Element *element = *list;
        while (element != NULL) {
            printf("Data = %d\n", element->data);
            element = element->next;
        }
    }

}

int Remove_All_Equals_List(List* list, int data) {

    if (list == NULL || (*list) == NULL) {

        return 0;
    }

    Element *previous = NULL;
    Element *current = *list;

    while (current != NULL) { //Verifica até o final da lista

        Element *next = current->next; //Faz um novo ponteiro next apontando para o próximo do current

        if (current->data == data) { //Se o valor for igual

            if (previous == NULL) { //Primeira mente verifica se é o primeiro elemento da lista
                *list = next; //Se for, faz a lista apontar para o próximo

            } else {

                previous->next = next; //Se não for o primeiro, faz o anterior apontar para o próximo
            }

            free(current); //Libera o elemento atual

        } else {
            previous = current; //Se o valor não for igual, o ponteiro do anterior passa a ser o do atual, pois o ponteiro anterior altera
                                //Caso o elemento não tenha sido eliminado.
        }

        current = next; //Avança o ponteiro do atual para o do próximo
    }

    return 1;
}
