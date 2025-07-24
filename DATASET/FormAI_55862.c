//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice, score=0, i;
    char symbol[12][3] = {"H", "Li", "Na", "K", "Rb", "Cs", "Fr", "Be", "Mg", "Ca", "Sr", "Ba"};
    char name[12][30] = {"Hydrogen", "Lithium", "Sodium", "Potassium", "Rubidium", "Cesium", "Francium", "Beryllium", "Magnesium", "Calcium", "Strontium", "Barium"};

    // Introduction to the Quiz
    printf("************ Welcome to the Periodic Table Quiz! ************\n\n");
    printf("Instructions:\nChoose the correct symbol for the given element name.\n");
    printf("There are a total of 12 questions. Good Luck!\n\n");

    // Questions
    for(i=0; i<12; i++){
        srand(time(0));
        int random = rand() % 12; // Generates a random number from 0 to 11
        printf("%d. What is the symbol for the element %s?\n", i+1, name[random]);
        printf("  1. %s\n  2. %s\n  3. %s\nEnter your choice: ", symbol[(random-1+12)%12], symbol[random], symbol[(random+1)%12]);
        scanf("%d", &choice);
        if(choice==2){
            printf("Correct!\n\n");
            score++;
        }
        else{
            printf("Wrong! The correct answer is %s\n\n", symbol[random]);
        }
    }

    // Results
    printf("************ Results ************\n");
    printf("Total Score: %d out of 12\n", score);
    if(score>=9){
        printf("Congratulations! You have an excellent knowledge of the Periodic Table.\n");
    }
    else if(score>=6){
        printf("Good Job! You have a decent knowledge of the Periodic Table.\n");
    }
    else{
        printf("Better luck next time. You need to study more about the Periodic Table.\n");
    }

    return 0;
}