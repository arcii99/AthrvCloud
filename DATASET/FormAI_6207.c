//FormAI DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Welcome message
    printf("Welcome to the Love Game!\n\n");
    printf("This game is designed to help you express your love to your significant other in a fun and unique way.\n\n");

    // Input their names
    char name1[20], name2[20];
    printf("Please enter your name, Player 1: ");
    scanf("%s", name1);
    printf("Please enter your name, Player 2: ");
    scanf("%s", name2);

    // Randomize the love score
    srand(time(NULL));
    int loveScore = rand() % 101;

    // Display the love score and a romantic message
    printf("\n\n**************************************************\n\n");
    printf("Congratulations! %s and %s, your love score is %d%%!\n\n", name1, name2, loveScore);
    if (loveScore >= 80){
        printf("Wow, you two are meant to be together forever!");
    } else if (loveScore >= 50){
        printf("You two have good chemistry. Keep the love burning!");
    } else {
        printf("Don't worry too much. Love takes time and it will come!");
    }
    printf("\n\n**************************************************\n\n");

    return 0;
}