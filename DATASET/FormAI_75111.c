//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Conspiracy theories */
char *theories[] = {
    "The moon landing was faked",
    "9/11 was an inside job",
    "The government is controlling our minds with chemtrails",
    "The earth is actually flat",
    "The Illuminati is controlling everything",
    "Aliens built the ancient pyramids",
    "Area 51 is hiding evidence of extraterrestrial life",
    "Vaccines are causing autism",
    "Bigfoot is real and the government is covering it up",
    "The New World Order is coming",
    "The Mandela Effect is proof of alternate realities",
    "The government is hiding the cure for cancer",
    "The Illuminati controls the music industry",
    "The government is putting fluoride in our water to control us"
};

int main() {
    srand(time(NULL)); // Initialize the random number generator
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("Press enter to generate a new conspiracy theory, or 'q' to quit.\n");
    
    char input;
    while (1) {
        input = getchar();
        if (input == 'q') {
            break;
        }
        
        int index = generate_random_int(0, sizeof(theories)/sizeof(theories[0]) - 1); // Generate a random index for the conspiracy theory array
        
        printf("\n%s\n\n", theories[index]); // Print the conspiracy theory
    }
    
    return 0;
}