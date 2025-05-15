//
// Created by Felipe Fonseca on 12/05/2025.
//
#include <stdio.h>
#include <stdlib.h>

#include "exc1.h"

int main() {

    Student student, a[4] = {{2,"Andre",9.5,7.8,8.5},
                     {4,"Ricardo",7.5,8.7,6.8},
                     {1,"Bianca",9.7,6.7,8.4},
                     {3,"Ana",5.7,6.1,7.4}};
    List* list = Create_List();
    printf("Tamanho: %d\n\n\n\n", List_Length(list));

    int i;
    for(i=0; i < 4; i++)
        Insert_Order_List(list,a[i]);

    Print_List(list);
    printf("\n\n\n\n Tamanho: %d\n", List_Length(list));

    for(i=0; i < 4; i++){
        Remove_Last_List(list);
        Print_List(list);
        printf("\n Tamanho: %d\n\n\n", List_Length(list));
    }

    for(i=0; i < 4; i++)
        Insert_Order_List(list,a[i]);
    Print_List(list);

    Free_List(list);
    system("pause");
    return 0;

}