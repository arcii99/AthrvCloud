//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
} element;

element periodic_table[118]; // an array of elements

void initialize_periodic_table()
{
    strcpy(periodic_table[0].symbol, "H");
    strcpy(periodic_table[0].name, "Hydrogen");
    periodic_table[0].atomic_number = 1;
    periodic_table[0].atomic_weight = 1.008;
    /* ... */
    // add all 118 elements to the array
}

int main()
{
    initialize_periodic_table();

    int score = 0; // initialize the score to 0 
    int num_questions = 5; // ask the user 5 questions 
    int i, j, k;
    int used_symbols[118] = { 0 }; // keep track of used symbols 
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions. Good luck!\n\n", num_questions);
    
    for (i = 0; i < num_questions; i++)
    {
        int random_number = rand() % 118; // generate a random number between 0 and 117
        
        // make sure the symbol hasn't been used before
        while (used_symbols[random_number] == 1)
        {
            random_number = rand() % 118;
        }
        used_symbols[random_number] = 1;
        
        printf("Question %d: What is the full name for symbol %s?\n", i+1, periodic_table[random_number].symbol);
        
        char answer[20];
        scanf("%s", answer);
        
        // convert answer to lowercase
        for (j = 0; j < strlen(answer); j++)
        {
            answer[j] = tolower(answer[j]);
        }
        
        // compare answer to the actual name
        char actual_name[20];
        strcpy(actual_name, periodic_table[random_number].name);
        for (k = 0; k < strlen(actual_name); k++)
        {
            actual_name[k] = tolower(actual_name[k]);
        }
        
        if (strcmp(answer, actual_name) == 0)
        {
            printf("Great job! That is correct.\n");
            score++;
        }
        else
        {
            printf("I'm sorry, that is incorrect. The correct answer is %s.\n", periodic_table[random_number].name);
        }
        
        printf("Your current score is %d out of %d.\n\n", score, i+1);
    }
    
    printf("Thanks for playing the Periodic Table Quiz! Your final score is %d out of %d.\n", score, num_questions);
    
    return 0;
}