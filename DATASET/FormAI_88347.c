//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"Government", "Illuminati", "Aliens", "Zombies", "Big Pharma", "Flat Earth Society", "Reptilian Elite", "Time Travellers", "Clones", "Artificial Intelligence"};
char* actions[] = {"Control", "Manipulate", "Experiment on", "Brainwash", "Destroy", "Invade", "Infiltrate", "Conquer", "Subdue", "Devour"};
char* targets[] = {"Humanity", "The Environment", "The Economy", "Religion", "Science", "Education", "Technology", "Culture", "Healthcare", "Entertainment"};

void generate_conspiracy() {
    char* subject = subjects[rand() % 10];
    char* action = actions[rand() % 10];
    char* target = targets[rand() % 10];

    printf("%s wants to %s %s.\n", subject, action, target);

    int continue_choice;
    printf("Continue? 1 for yes, 0 for no: ");
    scanf("%d", &continue_choice);

    if (continue_choice == 1) {
        generate_conspiracy();
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    generate_conspiracy();

    printf("Thanks for using the Random Conspiracy Theory Generator!\n");

    return 0;
}