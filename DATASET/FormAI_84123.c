//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#define SIZE 5

// A struct defining each element in the queue
struct Element {
    int value;
};

// An array of elements that represents the queue
struct Element Queue[SIZE];

// Initialize variables to represent the front and rear of the queue
int Front = -1, Rear = -1;

// Function to add an element to the queue
void Enqueue(int value) {
    // Check if the queue is full
    if (Rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    // Create a new instance of Element
    struct Element element;

    // Set the value of the Element to the given value
    element.value = value;

    // If the queue is currently empty, set Front to 0
    if (Front == -1) {
        Front = 0;
    }

    // Increment the value of Rear
    Rear++;

    // Add the new element to the queue
    Queue[Rear] = element;

    printf("Element with value %d added to the queue.\n", value);
}

// Function to remove an element from the queue
int Dequeue() {
    // Check if the queue is empty
    if (Front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Get the element at the front of the queue
    struct Element frontElement = Queue[Front];

    // Remove the element from the front of the queue
    Front++;

    // If there are no elements left in the queue, reset the values of Front and Rear
    if (Front > Rear) {
        Front = -1;
        Rear = -1;
    }

    printf("Element with value %d removed from the queue.\n", frontElement.value);

    return frontElement.value;
}

// Function to display the elements in the queue
void DisplayQueue() {
    // Check if the queue is empty
    if (Front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    // Loop through the elements in the queue
    for (int i = Front; i <= Rear; i++) {
        printf("%d ", Queue[i].value);
    }

    printf("\n");
}

int main() {
    printf("Welcome to the Queue!\n");

    // Add elements to the queue
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);

    // Display the elements in the queue
    DisplayQueue();

    // Remove elements from the queue
    Dequeue();
    Dequeue();
    Dequeue();

    // Display the elements in the queue
    DisplayQueue();

    return 0;
}