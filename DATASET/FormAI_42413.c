//FormAI DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int id;
    char name[30];
    float gpa;
    struct node *next;
};

struct indexNode{
    int id;
    struct node *student;
    struct indexNode *next;
};

struct indexNode *indexTable[100];
int indexSize = 100;

int hash(int id){  // generate hash function
    return id%indexSize;
}

void insert(struct node *student){ // insert a student record into the database
    int index = hash(student->id);
    struct indexNode *newIndexNode = malloc(sizeof(struct indexNode));
    newIndexNode->id = student->id;
    newIndexNode->student = student;
    newIndexNode->next = NULL;

    if(indexTable[index] == NULL){
        indexTable[index] = newIndexNode;
    }
    else{
        struct indexNode *temp = indexTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newIndexNode;
    }
}

void display(struct indexNode *index){ // display student records
    struct node *tempStudent = index->student;
    printf("Student ID: %d, Name: %s, GPA: %f \n", tempStudent->id, tempStudent->name, tempStudent->gpa);
}

void search(int id){ // search for a student record
    int index = hash(id);
    struct indexNode *tempIndex = indexTable[index];
    while(tempIndex != NULL){
        if(tempIndex->id == id){
            display(tempIndex);
            return;
        }
        tempIndex = tempIndex->next;
    }
    printf("Student with ID %d does not exist in the database. \n", id);
}

int main(){
    // initialize index table
    for(int i = 0; i < indexSize; i++){
        indexTable[i] = NULL;
    }

    // insert sample student records
    struct node *student1 = malloc(sizeof(struct node));
    student1->id = 1001;
    strcpy(student1->name, "John");
    student1->gpa = 3.5;
    insert(student1);

    struct node *student2 = malloc(sizeof(struct node));
    student2->id = 1002;
    strcpy(student2->name, "Mary");
    student2->gpa = 3.8;
    insert(student2);

    struct node *student3 = malloc(sizeof(struct node));
    student3->id = 1003;
    strcpy(student3->name, "Bob");
    student3->gpa = 3.2;
    insert(student3);

    // search for a student record
    search(1002);
    search(1005); // student with ID 1005 does not exist in the database

    return 0;
}