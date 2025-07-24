//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
/* 
* Romeo and Juliet: A Tale of C RAM Usage
*
* Written by: a Chatbot
*
* This program monitors the RAM usage of a C program in a unique manner,
* showcasing the love and tragedy of Romeo and Juliet.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int memory_usage = 0;

    while(1){

        printf("\nRomeo: My love, my sweet Juliet! (Current RAM usage: %d MB)\n", memory_usage);
        printf("Juliet: What is it, my Romeo? (Current RAM usage: %d MB)\n", memory_usage);

        // Update Memory Usage
        int random_num = rand() % 10;
        if(random_num % 2 == 0){
            memory_usage += random_num;
        } else {
            memory_usage -= random_num;
        }

        // Check for Tragedy
        if(memory_usage >= 90){
            printf("\nRomeo: Oh, my sweet Juliet! Our program has died!\n");
            printf("Juliet: No! How could this have happened!\n");
            printf("Romeo: Our love was too great, it consumed all available memory...\n");
            exit(0);
        }

        // Sleep for Dramatic Effect
        sleep(2);
    }

    return 0;
}