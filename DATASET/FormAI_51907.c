//FormAI DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a struct for storing happy messages
typedef struct {
    int id;
    char message[50];
} HappyMessage;

// Define an array of happy messages
HappyMessage messages[] = {
    {1, "You are amazing!"},
    {2, "Keep it up!"},
    {3, "You make the world a better place!"},
    {4, "You are a champion!"},
    {5, "You've got this!"},
    {6, "You deserve all the happiness in the world!"},
    {7, "You are a ray of sunshine!"},
    {8, "Way to go!"},
    {9, "You are an inspiration!"},
    {10, "You are loved!"},
};

// Define a function for comparing two happy messages
int compare_messages(const void *a, const void *b) {
    HappyMessage *message_a = (HappyMessage*)a;
    HappyMessage *message_b = (HappyMessage*)b;
    return message_a->id - message_b->id;
}

int main() {
    // Print a happy message
    printf("Hello there! It's time to sort some happy messages!\n");

    // Determine the length of the messages array
    int count = sizeof(messages) / sizeof(messages[0]);

    // Print the unsorted array of happy messages
    printf("\nHere are the unsorted messages:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", messages[i].id, messages[i].message);
    }

    // Use qsort to sort the array of happy messages by id
    qsort(messages, count, sizeof(HappyMessage), compare_messages);

    // Print the sorted array of happy messages
    printf("\nHere are the sorted messages:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", messages[i].id, messages[i].message);
    }

    // Print a final happy message
    printf("\nCongrats! You successfully sorted some happy messages!\n");

    return 0;
}