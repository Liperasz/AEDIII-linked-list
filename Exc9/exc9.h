//
// Created by liperasz on 16/05/2025.
//

#ifndef EXC9_H
#define EXC9_H

typedef struct {

    int id;
    char name[35];
    float g1, g2, g3;

} Student;

typedef struct element {

    Student data;
    struct element *next;

} Element;

typedef Element* List;

List* Create_List();
void Free_List(List* list);
int Insert_First_List(List* list, Student data);
int Insert_Last_List(List* list, Student data);
int Insert_Order_List(List* list, Student data);
int Remove_First_List(List* list);
int Remove_Last_List(List* list);
int Remove_List(List* list, int id);
int List_Length(List* list);
int List_Is_Empty(List* list);
int List_Is_Full(List* list);
void Print_List(List* list);

int Change_Element_List(List* list, Element *pointer);
Element* Search_Student_ID(List *list, int id);

#endif //EXC9_H
