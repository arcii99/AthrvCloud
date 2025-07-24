//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    char name[20];
    int age; 
    char question[100];

    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("What is your name?\n"); 
    scanf("%s", name); 
    printf("\nHi, %s! How old are you?\n", name); 
    scanf("%d", &age);
    if (age <= 0) {
        printf("\nThat can't be right!\n");
        return 0;
    }
    else if (age <= 18) {
        printf("\nYou're still young, %s.\n", name);
    }
    else if (age <= 30) {
        printf("\nYou've still got time, %s!\n", name);
    }
    else if (age <= 50) {
        printf("\nYou're only as old as you feel, %s.\n", name);
    }
    else {
        printf("\nYou're only getting better with age, %s.\n", name);
    }

    printf("\nAsk me a yes or no question, %s:\n", name);
    scanf(" %[^\n]", question);

    // Generate random response
    srand(time(NULL));
    int r = rand() % 2;

    if (r == 0) {
        printf("\nIt is unlikely, %s.\n", name);
    } else {
        printf("\nAbsolutely, %s!\n", name);
    }

    printf("\nGoodbye, %s. Enjoy the rest of your day!\n", name); 

    return 0; 
}