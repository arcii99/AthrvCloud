//FormAI DATASET v1.0 Category: Queue ; Style: creative
/* Welcome to our quirky C Queue example program!
 * Prepare to be amazed, as this isn't your average Queue. 
 * We've added some unique twists to this classic data structure, 
 * resulting in a program that's both useful and entertaining.
 * In this Queue, you can store any type of data you want, from integers and strings to structs and arrays.
 * Plus, we've added some fun features like a "queue shaking" animation and a "queue singing" function.
 * So sit back, relax, and enjoy the ride!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

// Queue definition
typedef struct Queue
{
    void **data;  // Pointer to an array
    size_t size;  // Maximum size of the array
    size_t front;  // Index of the front element
    size_t rear;  // Index of the rear element
    size_t count;  // Number of elements in the queue
} Queue;

// Helper function: create an empty queue
Queue* createQueue(size_t size)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->data = malloc(size * sizeof(void *));
    memset(queue->data, 0, size * sizeof(void *));
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
    return queue;
}

// Helper function: destroy a queue and free its memory
void destroyQueue(Queue *queue)
{
    if (queue != NULL) {  // Make sure queue is not NULL
        free(queue->data);
        free(queue);
    }
}

// Helper function: display the current contents of the queue
void displayQueue(Queue *queue)
{
    if (queue == NULL) {  // Make sure queue is not NULL
        printf("Queue is not initialized.\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < queue->count; i++) {
        size_t index = (queue->front + i) % queue->size;
        printf("%p", queue->data[index]);  // Display each element's memory address
        if (i < queue->count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Helper function: add an element to the rear of the queue
void enqueue(Queue *queue, void *data)
{
    if (queue == NULL) {  // Make sure queue is not NULL
        printf("Queue is not initialized.\n");
        return;
    }

    if (queue->count == queue->size) {  // Make sure queue is not full
        printf("Queue is full.\n");
        return;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->size;
    queue->count++;
}

// Helper function: remove and return the front element of the queue
void* dequeue(Queue *queue)
{
    if (queue == NULL) {  // Make sure queue is not NULL
        printf("Queue is not initialized.\n");
        return NULL;
    }

    if (queue->count == 0) {  // Make sure queue is not empty
        printf("Queue is empty.\n");
        return NULL;
    }

    void *data = queue->data[queue->front];
    queue->data[queue->front] = NULL;  // Set the front element to NULL
    queue->front = (queue->front + 1) % queue->size;
    queue->count--;
    return data;
}

// Helper function: shake the queue by randomly swapping elements
void shakeQueue(Queue *queue)
{
    if (queue == NULL) {  // Make sure queue is not NULL
        printf("Queue is not initialized.\n");
        return;
    }

    srand(time(NULL));  // Seed the random number generator

    printf("Shaking the queue...\n");
    for (size_t i = 0; i < queue->count; i++) {
        size_t index1 = (queue->front + i) % queue->size;
        size_t index2 = (queue->front + rand() % queue->count) % queue->size;
        void *temp = queue->data[index1];
        queue->data[index1] = queue->data[index2];
        queue->data[index2] = temp;
    }
}

// Helper function: sing a song using the elements in the queue
void singQueue(Queue *queue)
{
    if (queue == NULL) {  // Make sure queue is not NULL
        printf("Queue is not initialized.\n");
        return;
    }

    printf("Singing a song using the queue elements...\n");

    for (size_t i = 0; i < queue->count; i++) {
        size_t index = (queue->front + i) % queue->size;
        void *data = queue->data[index];

        if (data == NULL) {  // Skip NULL elements
            continue;
        }

        // Determine the type of the element and sing accordingly
        if (isdigit(*(char *) data)) {  // Element is a number
            printf("Do-Re-Mi-Fa-So-La-Ti-");
            for (int j = 0; j < atoi(data); j++) {
                printf("Do");
                if (j < atoi(data) - 1) {
                    printf("-");
                }
            }
            printf("\n");
        } else if (isalpha(*(char *) data)) {  // Element is a letter
            printf("%c, ", toupper(*(char *) data));
        } else {  // Element is something else
            printf("Bop ");
        }
    }
    printf("!\n");  // End the song
}

// Main function
int main()
{
    Queue *myQueue = createQueue(5);  // Create a queue of size 5
    int intData = 42;
    char *strData = "Hello";
    double doubleData = 3.14;
    int intArrayData[3] = {1, 2, 3};
    void *structData = malloc(sizeof(struct { int x; char *y; }));
    ((struct { int x; char *y; } *) structData)->x = 123;
    ((struct { int x; char *y; } *) structData)->y = "World";

    // Add some elements to the queue
    enqueue(myQueue, &intData);
    enqueue(myQueue, strData);
    enqueue(myQueue, &doubleData);
    enqueue(myQueue, intArrayData);
    enqueue(myQueue, structData);

    // Display the queue and shake it
    displayQueue(myQueue);
    shakeQueue(myQueue);
    displayQueue(myQueue);

    // Sing a song using the queue elements
    singQueue(myQueue);

    // Remove some elements from the queue
    printf("Removed %d from the queue.\n", *(int *) dequeue(myQueue));
    printf("Removed %s from the queue.\n", (char *) dequeue(myQueue));
    printf("Removed %f from the queue.\n", *(double *) dequeue(myQueue));

    // Display the queue and sing again
    displayQueue(myQueue);
    singQueue(myQueue);

    // Destroy the queue and free its memory
    destroyQueue(myQueue);
    free(structData);

    return 0;  // End of program
}