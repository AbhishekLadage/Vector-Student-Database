// student_data_base

#include "header.h"
#include <string.h>

int count(SLL* hptr)
{
    int c = 0;
    SLL* temp = hptr;
    while (temp)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

void add_end(SLL** hptr)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    SLL* new_node, *temp;
    new_node = (SLL*)malloc(sizeof(SLL));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return;
    }
    int c = count(*hptr);
    new_node->roll = c + 1;
    printf("Enter name and percentage\n");
    scanf(" %[^\n]", new_node->name);
    scanf("%f", &new_node->marks);
    new_node->next = NULL;

    if (*hptr == NULL)
    {
        *hptr = new_node;
    }
    else
    {
        temp = *hptr;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void show(SLL* hptr)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    if (hptr == NULL)
    {
        printf("no records found\n");
        return;
    }
    while (hptr)
    {
        printf("%d\t%s\t%.2f\n", hptr->roll, hptr->name, hptr->marks);
        hptr = hptr->next;
    }
    printf("\n**************************\n");
}

void delete1(SLL** hptr)
{
    SLL *prev = NULL, *del, *temp;
    int a;
    printf("enter roll no\n");
    scanf("%d", &a);

    if (*hptr == NULL)
    {
        printf("no record found\n");
        return;
    }

    del = *hptr;
    while (del)
    {
        if (del->roll == a)
        {
            if (del == *hptr)
                *hptr = (*hptr)->next;
            else
                prev->next = del->next;
            free(del);
            printf("Record deleted.\n");
            return; // Stop after deleting
        }
        prev = del;
        del = del->next;
    }
    printf("Record not found.\n");
}

void modify(SLL **hptr) {
    int roll;
    SLL *temp = *hptr;
    printf("Enter roll number to modify: ");
    scanf("%d", &roll);
    while (temp) {
        if (temp->roll == roll) {
            printf("Enter new name: ");
            scanf(" %[^\n]", temp->name);
            printf("Enter new percentage: ");
            scanf("%f", &temp->marks);
            printf("Record updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

void save(SLL **hptr) {
    FILE *fp = fopen("student_db.txt", "w");
    if (!fp) {
        printf("Failed to open file for writing.\n");
        return;
    }
    SLL *temp = *hptr;
    while (temp) {
        fprintf(fp, "%d,%s,%.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
    fclose(fp);
    printf("Records saved to student_db.txt\n");
}

void sort(SLL **hptr) {
    if (*hptr == NULL || (*hptr)->next == NULL) {
        printf("List is too short to sort.\n");
        return;
    }
    SLL *i, *j;
    for (i = *hptr; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->roll > j->roll) {
                // Swap data
                int t_roll = i->roll;
                char t_name[100];
                float t_marks = i->marks;
                strcpy(t_name, i->name);

                i->roll = j->roll;
                strcpy(i->name, j->name);
                i->marks = j->marks;

                j->roll = t_roll;
                strcpy(j->name, t_name);
                j->marks = t_marks;
            }
        }
    }
    printf("List sorted by roll number.\n");
}

void delete_all(SLL **hptr) {
    SLL *temp;
    while (*hptr) {
        temp = *hptr;
        *hptr = (*hptr)->next;
        free(temp);
    }
    printf("All records deleted.\n");
}