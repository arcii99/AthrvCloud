//FormAI DATASET v1.0 Category: Queue ; Style: bold
/*
* This is a program to implement Circular Queue in C language. This is based on the famous data structure concept of Queue.
* A Queue is a data structure which follows First In First Out (FIFO) approach. In other words, the element which is inserted
* first will come out first. But as we discuss Circular Queue, which is an advanced and efficient form of Queue, it uses the
* circular concept. The index pointer wraps around the array or the buffer to occupy vacant spaces in the queue. In other words,
* it will avoid the wastage of the circular queue at the front end and fill the vacant space at the end of the queue.
*/

// Including the Standard header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining fixed buffer size
#define BufferSize 6

// Defining the Circular Queue structure
typedef struct
{
    int buffer[BufferSize];         // An integer array buffer to maintain the queue
    int front, rear;                // Front and Rear pointer markers
    bool QueueFull, QueueEmpty;     // Flags to check Queue status using the condition's verification
} Queue;

// Function declaration
void InitializeQueue(Queue *CQ);
void Enqueue(Queue *CQ, int element);
void Dequeue(Queue *CQ);
void ShowQueue(Queue *CQ);

// Main Function
int main()
{
    Queue CQ;                   // Creating a circular queue structure instance (Object) named CQ

    InitializeQueue(&CQ);          // Initializing the queue

    // Adding an element into the queue
    Enqueue(&CQ, 10);
    Enqueue(&CQ, 20);
    Enqueue(&CQ, 30);
    Enqueue(&CQ, 40);

    ShowQueue(&CQ);            // Showing the queue

    Dequeue(&CQ);              // removing an element from the queue

    ShowQueue(&CQ);            // Showing the queue again after removing the form the queue

    Enqueue(&CQ, 50);              // Adding another element at the end of the queue
    Enqueue(&CQ, 60);              // Adding another element at the end of the queue
    Enqueue(&CQ, 70);              // Adding another element at the end of the queue

    ShowQueue(&CQ);            // showing the queue after addition of the new elements to the queue

    return 0;
}

/*
 * Function Definition (InitializeQueue) - Responsible to initialize the Queue
 * Parameters :
 * Queue *CQ : Address of Queue instance to which we want to initialize.
 */
void InitializeQueue(Queue *CQ)
{
    CQ->front = 0;
    CQ->rear = -1;
    CQ->QueueFull = false;
    CQ->QueueEmpty = true;
}

/*
 * Function Definition (Enqueue) - Function to insert an element into the queue
 * Parameters :
 * Queue *CQ : Address of Circular Queue instance into which we want to enter the element
 * int element : Element to be entered into the queue
 */
void Enqueue(Queue *CQ, int element)
{
    if (CQ->QueueFull == true)              // Checking whether the queue is already full or not
    {
        printf("\n Circular Queue is full. Cannot Enqueue.");
        return;
    }
    else
    {
        // Incrementing Rear pointer
        CQ->rear = (CQ->rear + 1) % BufferSize;     

        // Inserting an element at the rear end of Circular Queue
        CQ->buffer[CQ->rear] = element;        

        // Setting the flag to true if the rear and front pointer match, always has one element in the queue
        if (CQ->rear == 0 && CQ->front == BufferSize - 1)
            CQ->QueueFull = true;
        else if (CQ->rear == (CQ->front - 1) % (BufferSize - 1))
            CQ->QueueFull = true;

        // Setting the flag to false if an element exists into the Circular Queue
        CQ->QueueEmpty = false;
    }
}

/*
* Function Definition (Dequeue) - Function to remove an element from the queue
* Parameters :
* Queue *CQ : Address of the Circular Queue instance from which we want to remove the element
*/
void Dequeue(Queue *CQ)
{
    if (CQ->QueueEmpty == true)            // Checking whether the queue is already empty or not
    {
        printf("\n Circular Queue is empty. Cannot Dequeue.");
        return;
    }
    else
    {
        // Printing the removed element from the queue
        printf("\n Dequeue Operation: Element removed from Circular Queue is : %d", CQ->buffer[CQ->front]);

        // Incrementing front pointer
        CQ->front = (CQ->front + 1) % BufferSize;

        // Setting the flag to true if the rear and front pointer match, always has one element in the queue
        if (CQ->rear == (BufferSize - 1) && CQ->front == 0)
            CQ->QueueFull = true;
        else
            CQ->QueueFull = false;

        if (CQ->front == CQ->rear)
            CQ->QueueEmpty = true;
    }
}

/*
* Function Definition (ShowQueue) - Function to show the Queue element
* Parameters :
* Queue *CQ : Address of the Circular Queue instance, which we want to show
*/
void ShowQueue(Queue *CQ)
{
    if (CQ->QueueEmpty == true)            // Checking whether the queue is already empty or not
    {
        printf("\n Circular Queue is empty. Cannot Show Queue. ");
    }
    else
    {
        int i;
        printf("\n Circular Queue Elements are as follows: ");

        // Element Traverse using index manipulation approach for Circular Queue
        for (i = CQ->front; i != CQ->rear; i = (i + 1) % BufferSize)
        {
            printf("%d ", CQ->buffer[i]);
        }
        printf("%d", CQ->buffer[i]);
    }
}