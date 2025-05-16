//
// Created by liperasz on 15/05/25.
//
#include "exc5.h"
#include <stdio.h>
#include <stdlib.h>

int main () {

    int vet[18] = {1, 5, 2, 5, 3, 5, 4, 5, 6, 5, 7, 5, 8, 5, 9, 5, 10, 5};

    List *list = Create_List();

    for (int i = 0; i < 18; i++) {
        Insert_Last_List(list, vet[i]);
    }

    Print_List(list);

    printf("\n");

    Remove_All_Equals_List(list, 5);
    Print_List(list);

    Free_List(list);

    return 0;
}