//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between two values
int random_int(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to print a string with emphatic punctuation
void energetic_print(char* str){
    printf("%s!!!\n", str);
}

int main(){
    char messages[5][50] = {"Hello", "How are you?", "I love C programming", "Let's have some fun", "Coding is life"};
    int num_messages = 5;

    // Seed the random number generator
    srand(time(NULL));

    energetic_print("Welcome to the energetic C program!");

    // Loop through and print random messages
    for(int i = 0; i < num_messages; i++){
        int rand_delay = random_int(1, 3); // random delay between 1-3 seconds
        printf("\nMessage %d: ", i+1);
        energetic_print(messages[i]);
        printf("Waiting %d seconds before next message...\n", rand_delay);
        sleep(rand_delay); // wait for random amount of time before proceeding
    }

    energetic_print("That was fun!");

    return 0;
}