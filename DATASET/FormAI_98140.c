//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
// C Automated Fortune Teller
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

const char *fortunes[] = { "You will find happiness soon.",
                       "Luck is on your side today.",
                       "A big change is coming your way.",
                       "Your hard work will pay off soon.",
                       "You will meet someone special in your life.",
                       "An unexpected opportunity is coming your way.",
                       "Do not be afraid to take risks.",
                       "You will be surrounded by good people soon.",
                       "Your life is about to get better than ever before.",
                       "Trust your instincts and go for it." };
int num_fortunes = 10;

void *get_fortune(void *args){
    // Generate a random fortune
    int r = rand() % num_fortunes;
    const char *fortune = fortunes[r];

    // Print the fortune
    printf("\nFortune: %s\n", fortune);

    return NULL;
}

int main(){
    // Initialize random number generator
    srand(time(NULL));

    // Display welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Initialize the threads
    pthread_t fortune_teller[3];

    // Create the threads to get the fortunes
    for(int i = 0; i < 3; i++){
        pthread_create(&fortune_teller[i], NULL, get_fortune, NULL);
    }

    // Wait for the threads to finish
    for(int i = 0; i < 3; i++){
        pthread_join(fortune_teller[i], NULL);
    }

    // Display final message
    printf("\nThank you for visiting. Goodbye!\n");

    return 0;
}