//FormAI DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int id;
    char name[100];
    float salary;
    struct Node* next;
};

int hashFunction(int id){
    return id%100;
}

struct Node* createNode(int id, char *name, float salary){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node* hashTable[], int id, char *name, float salary){
    struct Node* newNode = createNode(id, name, salary);
    int index = hashFunction(id);
    if(hashTable[index] == NULL) hashTable[index] = newNode;
    else{
        struct Node* head = hashTable[index];
        while(head->next!=NULL) head=head->next;
        head->next=newNode;
    }
}

struct Node* searchNode(struct Node* hashTable[], int id){
    int index = hashFunction(id);
    struct Node* head = hashTable[index];
    while(head!=NULL){
        if(head->id==id) return head;
        head = head->next;
    }
    return NULL;
}

void printNode(struct Node* node){
    printf("ID: %d, Name: %s, Salary: %0.2f\n",node->id, node->name, node->salary);
}

void printTable(struct Node* hashTable[]){
    for(int i=0; i<100; i++){
        struct Node* head = hashTable[i];
        if(head!=NULL){
            printf("[%d]", i);
            while(head!=NULL){
                printNode(head);
                head=head->next;
            }
            printf("\n");
        }
    }
}

int main(){
    struct Node* hashTable[100];
    for(int i=0; i<100; i++) hashTable[i]=NULL;
    
    insertNode(hashTable, 101, "John Smith", 50000);
    insertNode(hashTable, 102, "Mary Johnson", 60000);
    insertNode(hashTable, 103, "David Chen", 80000);
    insertNode(hashTable, 104, "Karen Lee", 75000);
    insertNode(hashTable, 105, "Jose Rodriguez", 65000);
    insertNode(hashTable, 106, "Jessica Wong", 70000);
    insertNode(hashTable, 107, "Ryan Kim", 55000);
    insertNode(hashTable, 108, "Samantha Brown", 90000);
    insertNode(hashTable, 109, "Michael Davis", 100000);
    
    printf("Hash Table before querying:\n");
    printTable(hashTable);
    
    int queryId = 108;
    struct Node* queryResult = searchNode(hashTable, queryId);
    if(queryResult==NULL){
        printf("No employee found with ID %d\n",queryId);
    }else{
        printf("Results for the query 'SELECT * FROM employees where id=%d':\n",queryId);
        printNode(queryResult);
    }

    return 0;
}