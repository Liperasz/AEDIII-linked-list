//
// Created by liperasz on 15/05/25.
//

#ifndef EXC4_H
#define EXC4_H

typedef struct element {

    float data;
    struct element *next;

} Element;

typedef Element* List;

List* Create_List();
void Free_List(List* list);
int Insert_First_List(List* list, float data);
int Insert_Last_List(List* list, float data);
int Insert_Order_List(List* list, float data);
int Remove_First_List(List* list);
int Remove_Last_List(List* list);
int Remove_List(List* list, float data);
int List_Length(List* list);
int List_Is_Empty(List* list);
int List_Is_Full(List* list);
void Print_List(List* list);

List* Construct_List(float* data, int size);

#endif //EXC4_H
