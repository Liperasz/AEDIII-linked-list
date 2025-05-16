//
// Created by liperasz on 15/05/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "exc6.h"

int main() {

    int vet[18] = {1, 5, 2, 5, 3, 5, 4, 5, 6, 5, 7, 5, 8, 5, 9, 5, 10, 5};
    int vet2[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    List *list = Create_List();
    List *list2 = Create_List();

    for (int i = 0; i < 18; i++) {
        Insert_Last_List(list, vet[i]);
    }

    Print_List(list);
    printf("\n\n\n\n\n");

    for (int i = 0; i < 15; i++) {
        Insert_First_List(list2, vet2[i]);
    }
    Print_List(list2);
    printf("\n\n\n\n\n");


    Concatenate_List(list, list2);
    Print_List(list);

    Free_List(list);

    return 0;
}