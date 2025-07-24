//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char questions[5][50] = {"What will my future hold?", "Will I be successful?", "Am I going to be rich?", "Will I find true love?", "Is there happiness in my future?"};
    char answers[5][100] = {"The future looks bright for you.", "With hard work and dedication, success is in your future.", "Money isn't everything, focus on what truly makes you happy.", "Love is in the air, keep an open mind and heart.", "Happiness is within your reach."};
    char name[50];
    char question[50];
    int random_index;
    
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    
    printf("Hello %s, what question do you have for me?\n", name);
    scanf("%s", question);
    
    srand(time(0));
    random_index = rand() % 5;
    
    printf("\nLet me consult the spirits...\n");
    printf("\n%s\n\n", answers[random_index]);
    
    return 0;
}