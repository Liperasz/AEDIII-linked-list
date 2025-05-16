//
// Created by liperasz on 15/05/25.
//

#include "exc2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int Insert_First_List(List* list, Student data) {

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

int Insert_Last_List(List* list, Student data) {

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

int Insert_Order_List(List* list, Student data) {

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

    while (current != NULL && current->data.id < data.id) {
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

int Remove_List(List* list, int id) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    Element *before = NULL;
    Element *current = *list;

    while (current != NULL && current->data.id != id) {
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
            printf("ID = %d\n", element->data.id);
            printf("Name: %s\n", element->data.name);
            printf("Grades: %.1f, %.1f, %.1f\n", element->data.g1, element->data.g2, element->data.g3);
            element = element->next;
        }
    }

}

int Remove_Element(List* list, int id) {

    if (list == NULL || (*list) == NULL) {
        return 0;
    }

    if ((*list)->data.id == id) {

        Element *element = *list;
        *list = (*list)->next;
        free(element);
        return 1;

    }

    return Remove_Element(&(*list)->next, id);

}


int Verify_Equality_List(List* list1, List* list2) {

    if (list1 == NULL || list2 == NULL) {
        return 0;
    }

    if ((*list1) == NULL && (*list2) == NULL) {
        return 1;
    }

    if ((*list1) == NULL || (*list2) == NULL) {
        return 0;
    }

    if (((*list1)->data.id != (*list2)->data.id)
        || (strcmp((*list1)->data.name, (*list2)->data.name) != 0)
        || ((*list1)->data.g1 != (*list2)->data.g1)
        || ((*list1)->data.g2 != (*list2)->data.g2)
        || ((*list1)->data.g3 != (*list2)->data.g3)) {


        return 0;
    }

    return Verify_Equality_List(&(*list1)->next, &(*list2)->next);

}
/*
 * A lógica é passar como parametro da função recursiva um novo ponteiro, esse novo ponteiro nada mais é do que o o ponteiro que aponta para o próximo elemento da onde
 * a lista está apontando atualmente, dessa forma, percorrendo a lista sem utilizar while, e sem perder o encadeamento, já que é um novo
 * ponteiro que é passado a cada função recursiva. Além disso, ele já garante a exclusão do elemento sem ter que linkar diretamente o elemento anterior com o próximo,
 * pelo mesmo motivo de o ponteiro "lista" já ser o ponteiro próximo do elemento anterior.
 */