//
// Created by liperasz on 16/05/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "exc9.h"

int main () {

    Student a[4] = {{2,"Andre",9.5,7.8,8.5},
                 {4,"Ricardo",7.5,8.7,6.8},
                 {1,"Bianca",9.7,6.7,8.4},
                 {3,"Ana",5.7,6.1,7.4}};
    List* list = Create_List();

    for (int i = 0; i < 4; i++) {
        Insert_Order_List(list, a[i]);
    }

    printf("List size: %d\n", List_Length(list));
    Print_List(list);
    printf("\n\n\n\n\n");

    Change_Element_List(list, Search_Student_ID(list, 2));

    printf("List size: %d\n", List_Length(list));
    Print_List(list);
    printf("\n\n\n\n\n");

    Change_Element_List(list, Search_Student_ID(list, 1));

    printf("List size: %d\n", List_Length(list));
    Print_List(list);
    printf("\n\n\n\n\n");

    Change_Element_List(list, Search_Student_ID(list, 4));

    printf("List size: %d\n", List_Length(list));
    Print_List(list);
    printf("\n\n\n\n\n");

    Change_Element_List(list, Search_Student_ID(list, 3));

    printf("List size: %d\n", List_Length(list));
    Print_List(list);
    printf("\n\n\n\n\n");

    Free_List(list);

    return 0;
}