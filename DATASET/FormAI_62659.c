//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    char name[50];
    int choice, age, invasionProbability;
    srand(time(0));
    printf("Hello there! I am your friendly Alien Invasion Probability Calculator.\n");
    printf("Before we begin, what should I call you?\n");
    scanf("%s", name);
    printf("\nHi %s! Nice to meet you. Are you ready to find out the probability of an alien invasion?\n", name);
    printf("1 - Yes, I am ready!\n");
    printf("2 - No, I am not ready yet.\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nGreat! Let's get started.\n");
        printf("First, please tell me how old you are: ");
        scanf("%d", &age);

        if(age < 18) {
            printf("\nSorry %s, but I cannot continue as you need to be at least 18 years old.\n", name);
        }
        else {
            printf("\nAlright %s! Based on my calculations, the probability of an alien invasion within the next year is...\n", name);
            invasionProbability = rand() % 101; // Generating random number between 0-100
            printf("%d percent!\n", invasionProbability);
            if(invasionProbability < 50) {
                printf("Don't worry %s, the probability is low. We are safe for now!\n", name);
            }
            else {
                printf("Uh oh %s, the probability is high. We better start preparing for the worst!\n", name);
            }
        }
    }
    else if(choice == 2) {
        printf("\nNo problem %s, take your time. You can always come back later if you change your mind.\n", name);
    }
    else {
        printf("\nSorry %s, that is an invalid choice. Please try again.\n", name);
    }

    return 0;
}