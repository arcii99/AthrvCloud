//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

pthread_mutex_t mutex;

void *InsertNode(void *data)
{
    pthread_mutex_lock(&mutex);
    int *value = (int*) data;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = *value;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
    }
    else {
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
    printf("Node %d has been inserted!\n", *value);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *DeleteNode(void *data)
{
    pthread_mutex_lock(&mutex);
    int *value = (int*) data;

    if(head == NULL) {
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    Node* current = head;
    Node* prev = NULL;

    while(current != NULL && current->data != *value){
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        printf("Node %d not found!\n", *value);
        pthread_mutex_unlock(&mutex);
        return NULL;
    }

    if(prev == NULL){
        head = head->next;
    }
    else{
        prev->next = current->next;
    }

    free(current);
    printf("Node %d has been deleted!\n", *value);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void PrintList()
{
    pthread_mutex_lock(&mutex);
    printf("List contents: ");
    Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4, thread5;
    int data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 5;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads for various operations
    pthread_create(&thread1, NULL, InsertNode, &data1);
    pthread_create(&thread2, NULL, InsertNode, &data2);
    pthread_create(&thread3, NULL, InsertNode, &data3);
    pthread_create(&thread4, NULL, InsertNode, &data4);
    pthread_create(&thread5, NULL, DeleteNode, &data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    PrintList();
    pthread_mutex_destroy(&mutex);
    return 0;
}