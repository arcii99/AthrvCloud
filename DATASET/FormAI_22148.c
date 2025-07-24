//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>

/* This program generates a series of peaceful harmonies by allowing the user to input a sequence of notes */
int main()
{
    int num_notes, i;
    float tempo;

    printf("Welcome to the Peaceful Harmony Generator.\nHow many notes would you like to input? ");
    scanf("%d", &num_notes);

    // allocate memory for note array
    float *notes = malloc(sizeof(float) * num_notes);

    // prompt user for note sequence
    printf("Please enter your note sequence (separate with spaces): ");
    for (i=0; i<num_notes; i++) {
        scanf("%f", &notes[i]);
    }

    // prompt user for tempo
    printf("Please enter the tempo in beats per minute (BPM): ");
    scanf("%f", &tempo);
    float delay = 60 / tempo;

    // generate and play melody
    printf("\nPlaying melody...\n");
    for (i=0; i<num_notes; i++) {
        printf("Note %d: %.2f Hz\n", i+1, notes[i]);
        float duration = delay * 0.75; // play note for 75% of delay time
        if (i == num_notes-1) {
            duration *= 1.5; // extend last note for peaceful resolution
        }
        usleep(duration * 1000000); // pause for note duration
    }
    printf("\nMelody complete.\n");

    free(notes);
    return 0;
}