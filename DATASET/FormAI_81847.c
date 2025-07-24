//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
/* Romeo and Juliet: A Tale of Data Structures */
#include <stdio.h>

/* Define the struct for the characters in the story */
typedef struct {
    char *name;
    int age;
    char *status;
} character;

/* Declare the function to print character info */
void printCharacter(character c);

int main() {
    /* Initialize the characters */
    character romeo = {"Romeo", 18, "in love with Juliet"};
    character juliet = {"Juliet", 14, "in love with Romeo"};

    /* Create an array of 3 integers to be used as a stack */
    int stack[3];
    int top = -1;   // Initialize the top index to -1

    /* Add Romeo's age to the stack */
    top++;  // Increment the top index
    stack[top] = romeo.age;

    /* Add Juliet's age to the stack */
    top++;
    stack[top] = juliet.age;

    /* Add the sum of Romeo and Juliet's ages to the stack */
    top++;
    stack[top] = romeo.age + juliet.age;

    /* Pop the 2nd value from the stack, which is Juliet's age */
    int popped_value = stack[top];
    top--;
    printf("%s is %d years old.\n", juliet.name, popped_value);

    /* Create a queue for the messages */
    char *queue[5];
    int front = 0;  // Initialize the front and rear indices to 0
    int rear = 0;

    /* Add a message from Juliet to the queue */
    queue[rear] = "Romeo, Romeo, wherefore art thou Romeo?";
    rear++; // Increment the rear index

    /* Add a message from Romeo to the queue */
    queue[rear] = "Here I am, my love.";
    rear++;

    /* Print all the messages from the queue */
    printf("%s says: %s\n", juliet.name, queue[front]); // First in, first out
    front++;    // Increment the front index
    printf("%s says: %s\n", romeo.name, queue[front]);
    front++;

    /* Print the characters' information using the printCharacter() function */
    printCharacter(romeo);
    printCharacter(juliet);

    return 0;
}

/* Define the function to print character info */
void printCharacter(character c) {
    printf("%s is %d years old and %s.\n", c.name, c.age, c.status);
}