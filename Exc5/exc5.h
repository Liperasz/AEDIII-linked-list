//
// Created by liperasz on 15/05/25.
//

#ifndef EXC5_H
#define EXC5_H

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

int Remove_All_Equals_List(List* list, int data);

#endif //EXC5_H
