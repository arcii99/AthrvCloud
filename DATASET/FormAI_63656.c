//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Random fortunes
char *fortunes[] = {"You will achieve great success.", 
                    "Luck will be on your side today.",
                    "Be wary of making hasty decisions.",
                    "The best is yet to come.",
                    "Your hard work will pay off soon."};

bool is_done = false; // Used for threading

void *fortune_teller(void *arg){
    srand((unsigned int)time(NULL)); // For random number generation
    int i = 0;

    while(!is_done){ // While not done
        i = rand() % 5; // Get a random index for the fortune array
        printf("Here is your fortune: %s\n", fortunes[i]); // Print the fortune
        sleep(5); // Wait 5 seconds before giving another fortune
    }
    pthread_exit(NULL); // Exit thread when done
}

int main(void){
    int i;
    pthread_t tid;

    pthread_create(&tid, NULL, fortune_teller, NULL); // Create thread

    printf("Welcome to Automated Fortune Teller\n");
    printf("Press ENTER to exit...\n");

    getchar(); // Wait for user to input ENTER
    is_done = true; // Set done flag to true
    pthread_join(tid, NULL); // Wait for thread to finish executing

    return 0;
}