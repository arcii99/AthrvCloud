//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"The government", "Aliens", "Big Pharma", "Illuminati",
                    "The Deep State", "Reptilians", "The Freemasons", "The New World Order",
                    "The CIA", "The FBI", "The NSA", "Elites", "Multinational Corporations", "The Vatican"};

char* verbs[] = {"has created", "is controlling", "is hiding", "is manipulating",
                 "is poisoning", "is experimenting with", "is brainwashing", "is suppressing"};

char* objects[] = {"the weather", "the economy", "aliens", "the media", "our minds",
                   "the internet", "the medical industry", "our food and water", "the entertainment industry"};


int main() {
    srand(time(NULL));
    int num_subjects = sizeof(subjects)/sizeof(subjects[0]);
    int num_verbs = sizeof(verbs)/sizeof(verbs[0]);
    int num_objects = sizeof(objects)/sizeof(objects[0]);

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("--------------------------------------------------\n\n");

    while(1) {
        printf("Did you know that %s %s %s?\n", subjects[rand()%num_subjects], verbs[rand()%num_verbs], objects[rand()%num_objects]);
        printf("It's all part of the grand scheme to control us all!\n\n");
        printf("Press enter to generate another conspiracy theory, or type 'exit' to quit.\n");
        char input[5];
        fgets(input, 5, stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }
    }

    printf("Thanks for using the Random Conspiracy Theory Generator!\n");
    return 0;
}