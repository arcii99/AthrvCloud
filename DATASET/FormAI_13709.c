//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    srand(time(NULL)); // for random number generation

    int invasion_prob, n;
    char name[20];

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, let's get started.\n\n", name);

    printf("Enter the number of times you want to calculate: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        invasion_prob = rand() % 101; // generates a random number between 0 and 100, inclusive
        printf("Probability of Alien Invasion attempt #%d: %d%%\n", i, invasion_prob);
        if(invasion_prob >= 50) {
            printf("Houston, we have a problem! The probability is greater than or equal to 50.\n");
        }
        else {
            printf("Phew! We are safe for now.\n");
        }
        printf("--------------------------------------------\n");
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}