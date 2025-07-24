//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include<stdio.h>

// Linus Torvalds Style Periodic table quiz program

int main(){

    char prTable[7][17] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl"};
    int elementN[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    char choice[3];
    char answer = 'n';
    int points = 0;

    printf("Welcome to the Periodic Table Quiz\n");
    printf("Let's test your knowledge on the first 17 elements.\n");

    for(int i = 0; i < 17; i++){

        printf("\nWhat is the symbol for element number %d?\n", elementN[i]);
        printf("Your answer: ");
        scanf("%2s", &choice); // Not letting user input more than 2 characters

        if(prTable[i][0] == choice[0]){ // Checking if first character matches
            if(prTable[i][1] == choice[1]){ // Checking if second character matches
                answer = 'y';
                points++;
            }
        }

        if(answer == 'y'){
            printf("\nCorrect!");
        }
        else{
            printf("\nIncorrect. The symbol for element number %d is %s.", elementN[i], prTable[i]);
        }

        answer = 'n'; // Resetting answer variable
    }

    printf("\n\nYou scored %d out of 17 points.", points);

    return 0;
}