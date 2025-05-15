//
// Created by Felipe Fonseca on 12/05/2025.
//

#include "exc1.h"
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

Student* Search_Student_ID(List *list, int id) {
    if (list == NULL || (*list) == NULL) {
        return NULL;
    }

    Element *element = *list;

    while (element != NULL && element->data.id != id) {
        element = element->next;
    }

    if (element == NULL) {
        return NULL;
    }

    Student* student = &(element->data);
    return student;
}

Student* Search_Student_Position(List *list, int position) {

    if (list == NULL || (*list) == NULL) {
        return NULL;
    }

    Element *element = *list;

    int current_position = 0;

    while (element != NULL && current_position != position) {
        element = element->next;
        current_position += 1;
    }

    if (element == NULL) {
        return NULL;
    }

    Student* student = &(element->data);
    return student;

}

/*
 * A lógica é avançar na lista até que seja encontrada o elemento desejado que seja igual, se encontrado, ele retorna
 * um ponteiro para o aluno em questão, se não for encontrado, retorna nulo
 */