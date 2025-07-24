//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Defining the detective and his assistant
#define DETECTIVE "Sherlock Holmes"
#define ASSISTANT "Dr. John Watson"

// Struct to hold the clues
typedef struct clue_t {
    char *location;
    char *suspect;
    char *weapon;
} Clue;

// Function to create a new clue
Clue* create_clue(char *location, char *suspect, char *weapon) {
    Clue *clue = malloc(sizeof(Clue));
    clue->location = location;
    clue->suspect = suspect;
    clue->weapon = weapon;
    return clue;
}

// Function for the detective to investigate the clues
void* investigate_clues(void *args) {
    Clue *clue = (Clue*) args;
    printf("%s and %s started investigating the clue at %s...\n", DETECTIVE, ASSISTANT, clue->location);
    // Logic to investigate the clue related to the suspect and the weapon
    printf("%s and %s discovered that the murder was probably committed by %s using a %s at %s.\n",
            DETECTIVE, ASSISTANT, clue->suspect, clue->weapon, clue->location);
    free(clue);
    pthread_exit(NULL);
}

// Main function to start the investigation
int main() {
    pthread_t thread1, thread2;
    Clue *clue1 = create_clue("221B Baker Street", "Colonel Moran", "Revolver");
    Clue *clue2 = create_clue("Reichenbach Falls", "Professor Moriarty", "Falls");
    printf("%s and %s started the investigation...\n", DETECTIVE, ASSISTANT);
    pthread_create(&thread1, NULL, investigate_clues, (void*) clue1);
    pthread_create(&thread2, NULL, investigate_clues, (void*) clue2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("%s and %s solved the case and brought justice to the victim...\n", DETECTIVE, ASSISTANT);
    return 0;
}