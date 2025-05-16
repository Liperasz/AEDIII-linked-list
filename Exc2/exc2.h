//
// Created by liperasz on 15/05/25.
//

#ifndef EXC2_H
#define EXC2_H

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

int Remove_Element(List* list, int id);
int Verify_Equality_List(List* list1, List* list2);


#endif //EXC2_H
