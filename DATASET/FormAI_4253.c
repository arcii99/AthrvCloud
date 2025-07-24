//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

#define MAX_SIZE 10

int arr[MAX_SIZE]; // Data structure - array

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // mutex lock

// Function to print the array
void display()
{
    int i;
    printf("Current array: ");
    for(i=0;i<MAX_SIZE;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Function to insert item into array
void insert_item(int item)
{
    int i, index = -1;
    for(i=0;i<MAX_SIZE;i++)
    {
        if(arr[i] == -1)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        printf("Cannot insert, array is full\n");
    }
    else
    {
        arr[index] = item;
        printf("Item %d inserted at index %d\n", item, index);
    }
}

// Function to delete item from array
void delete_item(int item)
{
    int i, index = -1;
    for(i=0;i<MAX_SIZE;i++)
    {
        if(arr[i] == item)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        printf("Item not found\n");
    }
    else
    {
        arr[index] = -1;
        printf("Item %d deleted from index: %d\n", item, index);
    }
}

// Function executed by the first thread
void* thread1_func(void* arg)
{
    int choice, item;
    while(1)
    {
        printf("\n-------Thread 1--------\n");
        printf("1. Insert item\n");
        printf("2. Delete item\n");
        printf("3. Display array\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        pthread_mutex_lock(&lock);
        switch(choice)
        {
            case 1: 
                printf("Enter the item to be inserted: ");
                scanf("%d",&item);
                insert_item(item);
                break;
            case 2:
                printf("Enter the item to be deleted: ");
                scanf("%d",&item);
                delete_item(item);
                break;
            case 3:
                display();
                break;    
            default :
                printf("Invalid choice\n");
                break;
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

// Function executed by the second thread
void* thread2_func(void* arg)
{
    while(1)
    {
        printf("\n-------Thread 2--------\n");
        printf("Array elements: \n");
        int i;
        for(i=0;i<MAX_SIZE;i++)
        {
            printf("%d ",arr[i]);
        }
        sleep(2);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int i;
    //initialize array with default value of -1
    for(i=0;i<MAX_SIZE;i++)
    {
        arr[i] = -1;
    }
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}