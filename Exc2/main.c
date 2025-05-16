//
// Created by liperasz on 15/05/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "exc2.h"


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

    Remove_Element(list,4);
    printf("Tamanho: %d\n\n\n\n", List_Length(list));
    Print_List(list);

    List *list2 = Create_List();
    for(i=0; i < 4; i++)
        Insert_Order_List(list2,a[i]);

    printf("Tamanho: %d\n\n\n\n", List_Length(list));
    Print_List(list);

    if (Verify_Equality_List(list,list2)) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }

    Free_List(list);
    list = Create_List();
    for(i=0; i < 4; i++)
        Insert_Order_List(list,a[i]);

    printf("Tamanho: %d\n\n\n\n", List_Length(list));
    Print_List(list);

    if (Verify_Equality_List(list,list2)) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }

    Free_List(list2);
    Free_List(list);

    return 0;
}