#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int roll;
    char name[30];
    float marks;
    struct st *next;
} SLL;

int count(SLL* hptr);
void show(SLL* hptr);
void add_end(SLL** hptr);
void delete1(SLL** hptr);
void modify(SLL** hptr);
void save(SLL** hptr);
void sort(SLL** hptr);
void delete_all(SLL** hptr);

#endif // HEADER_H
