//
// Created by liperasz on 15/05/25.
//
#include <stdio.h>
#include <stdlib.h>
#include "exc4.h"

int main() {

    float vet[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

    List *list = Construct_List(&vet[0], 5);

    Print_List(list);

    Free_List(list);

    return 0;
}