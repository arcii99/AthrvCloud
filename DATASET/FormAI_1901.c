//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *fortunes[] = {
        "Your future looks bright!",
        "Beware of strangers bearing gifts.",
        "You will travel to distant lands.",
        "Good things come to those who wait.",
        "A long forgotten friend will soon reach out to you.",
        "Your hard work will pay off in the end.",
        "Love is just around the corner.",
        "You will receive unexpected news.",
        "Opportunities are endless today.",
        "Trust yourself and your instincts.",
        "Your creativity will bring you success.",
        "A change of scenery will do you good.",
        "Luck is on your side today.",
        "You will find a solution to a long-standing problem.",
        "The future is looking bright.",
        "You will soon overcome a great challenge."
    };

    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press enter to receive your fortune.\n");

    while (getchar() == '\n') {
        int random_index = rand() % (sizeof(fortunes)/sizeof(fortunes[0]));  // Generate a random index within the size of the array
        printf("\n%s\n", fortunes[random_index]);  // Print a random fortune from the array
        printf("\nPress enter to receive another fortune or type 'q' to quit.\n");
    }

    printf("\nGoodbye!\n");

    return 0;
}