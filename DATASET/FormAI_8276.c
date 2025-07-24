//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the futuristic Typing Speed Test program!\n\n");
    printf("You will now be given a sequence of random words to type. Press enter when you are ready to begin.\n");
    getchar();
    printf("\n");

    char* words[] = {"galactic", "cyberpunk", "neon", "dystopian", "cyborg", "android", "robotic", "quantum", "cosmic", "virtual", "augmented", "holographic", "interstellar", "exoplanet", "space-time", "futuristic", "hyper-reality", "nanotech", "synthetic", "transhuman", "biometric", "brain-computer", "cyber-army", "cyberspace", "hyperloop", "infinite", "interplanetary", "metaverse", "machine-learning", "neuroprosthetics", "oceanic", "plasma", "quantum-computing", "radical", "singularity", "smart-city", "superhuman", "terraforming", "time-travel", "universe", "warp-drive", "xenobiology", "zero-gravity", "cybernetic", "digital", "electric", "fusion"};
    int word_count = sizeof(words) / sizeof(words[0]);

    srand(time(0)); // seed random number generator

    int correct_count = 0;
    int total_count = 0;
    time_t start_time, end_time;
    double time_elapsed;
    int i;
    for(i = 0; i < 10; i++) { // loop through 10 words
        int random_index = rand() % word_count;
        printf("Type the word: %s\n", words[random_index]);

        start_time = time(NULL); // start timing
        char input[100];
        fgets(input, 100, stdin); // get user input
        end_time = time(NULL); // stop timing

        total_count++; // increment total count

        if(strcmp(input, words[random_index]) == 0) { // compare user input with generated word
            correct_count++; // increment correct count if input is correct
            printf("Correct!\n\n");
        } else {
            printf("Incorrect. The correct word was: %s\n\n", words[random_index]);
        }
    }

    time_elapsed = difftime(end_time, start_time); // calculate time elapsed
    printf("Test complete! You typed %d words correctly out of %d in %.0f seconds.\n", correct_count, total_count, time_elapsed);
  
    return 0;
}