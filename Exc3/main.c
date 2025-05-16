//
// Created by liperasz on 15/05/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "exc3.h"

int main () {

    Student student, a[4] = {{2,"Andre",9.5,7.8,8.5},
                     {4,"Ricardo",7.5,8.7,6.8},
                     {1,"Bianca",9.7,6.7,8.4},
                     {3,"Ana",5.7,6.1,7.4}};
    List* list = Create_List();
    printf("Tamanho: %d\n\n\n\n", List_Length(list));

    int i;
    for(i=0; i < 4; i++)
        Insert_Order_List(list,a[i]);

    printf("Tamanho: %d\n\n\n\n", List_Length(list));
    Print_List(list);

    Insert_in_second_List(list, a[1]);
    Insert_in_second_List(list, a[1]);
    Insert_in_second_List(list, a[2]);
    Insert_in_second_List(list, a[2]);

    printf("Tamanho: %d\n\n\n\n", List_Length(list));
    Print_List(list);

    Free_List(list);

    return 0;
}