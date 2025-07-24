//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max values
int random_number(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Array of fortunes to randomly select from
    char *fortunes[] = {
        "You will have a great day today!",
        "Good news is coming your way!",
        "Be patient, good things are coming!",
        "A new opportunity is on the horizon!",
        "You will meet someone new today!",
        "Your hard work will pay off soon!",
        "Surprises are in store for you!",
        "Your dreams are within reach!",
        "A loved one will bring you joy today!",
        "You will be successful in your endeavors!"
    };

    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]); // Total number of fortunes in array

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name: ");

    char name[50];
    scanf("%s", name); // Reads name input from user

    printf("Hello %s! Here is your fortune for today:\n", name);
    int random_index = random_number(0, num_fortunes-1); // Randomly select an index for the fortune array
    printf("%s\n", fortunes[random_index]); // Prints randomly selected fortune

    return 0;
}