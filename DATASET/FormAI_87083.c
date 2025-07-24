//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include<stdio.h>
#include<string.h>

struct Element{
    char symbol[3];
    char name[25];
    int atomic_number;
    char category[15];
};

int main(){
    struct Element periodic_table[118];
    int i = 0, j, score = 0;
    char answer[3];
    
    //filling periodic table data
    strcpy(periodic_table[0].name, "Hydrogen");
    strcpy(periodic_table[0].symbol, "H");
    periodic_table[0].atomic_number = 1;
    strcpy(periodic_table[0].category, "Non-metal");

    strcpy(periodic_table[1].name, "Helium");
    strcpy(periodic_table[1].symbol, "He");
    periodic_table[1].atomic_number = 2;
    strcpy(periodic_table[1].category, "Noble gas");
    
    //filling data for other elements
    
    //taking user input for quiz
    printf("Welcome to the periodic table quiz!\n");
    printf("How many questions would you like to answer? (maximum 10)\n");
    scanf("%d", &j);
    if(j>10){
        printf("Sorry, maximum questions limit is 10.\n");
        return 0;
    }
    
    printf("Let's begin!\n");
    while(i<j){
        int random_number = rand() % 118;
        printf("What element has the symbol %s? ", periodic_table[random_number].symbol);
        scanf("%s", answer);
        if(strcmp(answer, periodic_table[random_number].symbol) == 0){
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. Correct answer is %s.\n", periodic_table[random_number].symbol);
        }
        i++;
    }
    
    printf("Quiz is complete. You scored %d out of %d.\n", score, j);
    
    return 0;
}