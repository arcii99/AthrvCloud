//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define NUM_THEORIES 10

char* theories[] = {
    "The moon landing was faked by the government.",
    "The Illuminati control the world's governments.",
    "The earth is flat and NASA is lying to us.",
    "The government is secretly controlled by aliens.",
    "The JFK assassination was orchestrated by the CIA.",
    "9/11 was an inside job by the US government.",
    "The Bermuda Triangle is a portal to another dimension.",
    "The Holocaust was a hoax created by Jewish people.",
    "Chemtrails are a government conspiracy to control our minds.",
    "The Denver airport is a secret underground military base."
};

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random conspiracy theory
char* generate_theory() {
    int index = random_range(0, NUM_THEORIES - 1);
    return theories[index];
}

// Function to randomly capitalize letters in a string
char* random_capitalize(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (rand() % 2 == 0) {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

// Function to add a randomly generated conspiracy theory to a file
void add_theory_to_file(char* filename) {
    char* theory = generate_theory();
    theory = random_capitalize(theory);

    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s\n", theory);
    fclose(fp);
}

// Asynchronous function to continuously add theories to a file
void* add_theories(void* arg) {
    char* filename = (char*) arg;
    while (true) {
        add_theory_to_file(filename);
        int sleep_time = random_range(1, 10);
        sleep(sleep_time);
    }
    return NULL;
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char* filename = "conspiracy_theories.txt";
    FILE* fp = fopen(filename, "w");  // Create an empty file
    fclose(fp);

    // Create multiple threads to continuously add theories to the file
    int i;
    pthread_t threads[10];
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, add_theories, filename);
    }

    // Wait for the threads to finish
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}