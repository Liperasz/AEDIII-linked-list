//
// Created by liperasz on 15/05/25.
//

#ifndef EXC6_H
#define EXC6_H

typedef struct element {

    int data;
    struct element *next;

} Element;

typedef Element* List;

List* Create_List();
void Free_List(List* list);
int Insert_First_List(List* list, int data);
int Insert_Last_List(List* list, int data);
int Insert_Order_List(List* list, int data);
int Remove_First_List(List* list);
int Remove_Last_List(List* list);
int Remove_List(List* list, int data);
int List_Length(List* list);
int List_Is_Empty(List* list);
int List_Is_Full(List* list);
void Print_List(List* list);

int Concatenate_List(List* list1, List* list2);

#endif //EXC6_H
