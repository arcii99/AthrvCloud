//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining array of chemical element's symbols 
char elementSymbol[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar"};
    
//Defining array of chemical element's names
char elementName[][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon"};

//Defining array of chemical element's atomic numbers
int elementNumber[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

int main()
{
    int score = 0;
    char answer[3];
    int elementIndex;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Type in the symbol of the element whose name is shown\n");
    printf("You have to score 10 correct answers to win the game\n\n");
    
    while(score < 10)
    {
        //Generating random index number for the element
        elementIndex = rand() % 18;
        
        printf("What is the symbol of element %d: %s?\n", elementNumber[elementIndex], elementName[elementIndex]);
        scanf("%s", answer);
        
        if(strcmp(answer, elementSymbol[elementIndex]) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The answer is %s\n", elementSymbol[elementIndex]);
        }
    }
    
    printf("Congratulations! You scored %d out of 10!\n", score);
    
    return 0;
}