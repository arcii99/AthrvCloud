//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

// List of possible conspiracy theories
char *theories[] = {
    "The moon landing was faked by the government.",
    "The Earth is really flat.",
    "The Illuminati control the world.",
    "9/11 was an inside job.",
    "The government is hiding evidence of extraterrestrial life.",
    "The world is controlled by lizard people.",
    "Chemtrails are being used to control the population.",
    "COVID-19 was created in a lab.",
    "The vaccine is used to implant microchips in people.",
    "Global warming is a hoax created by the government."
};

// Function to generate a random number
int rand_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random theory
char* get_theory() {
    srand(time(NULL));
    int index = rand_num(0, 9);
    char* theory = malloc(strlen(theories[index]) + 1);
    strcpy(theory, theories[index]);
    return theory;
}

// Function to display the theory
void display_theory(char* theory) {
    printf("CONSPIRACY THEORY: %s\n", theory);
}

// Asynchronous function to generate conspiracy theories
void* generate_theories(void* arg) {
    int* num_theories = (int*) arg;
    for (int i = 1; i <= *num_theories; i++) {
        sleep(1);
        char* theory = get_theory();
        printf("Theory %d: ", i);
        display_theory(theory);
        free(theory);
    }
    pthread_exit(NULL);
}

int main() {
    int num_threads = 3;
    pthread_t threads[num_threads];
    int num_theories = 10;

    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d started.\n", i+1);
        pthread_create(&(threads[i]), NULL, generate_theories, (void*)&num_theories);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d finished.\n", i+1);
    }

    return 0;
}