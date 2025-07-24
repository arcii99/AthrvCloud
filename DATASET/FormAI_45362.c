//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
This program gives a quiz on the elements of the periodic table in order.
*/

int main(){
    int num_correct = 0;
    int num_quiz = 10; //Number of questions in the quiz
    int i, ans, guess;
    int elements[] = {1, 3, 11, 19, 37, 55, 87, 4, 12, 20, 38, 56, 88, 2, 10, 18, 36, 54, 86, 5, 13, 31, 49, 81, 6, 14, 32, 50, 82, 7, 15, 33, 51, 83, 8, 16, 34, 52, 84, 9, 17, 35, 53, 85};
    char* element_names[] = {"hydrogen", "lithium", "sodium", "potassium", "rubidium", "cesium", "francium", "beryllium", "magnesium", "calcium", "strontium", "barium", "radium", "helium", "neon", "argon", "krypton", "xenon", "radon", "boron", "carbon", "nitrogen", "oxygen", "fluorine", "boron", "carbon", "nitrogen", "oxygen", "fluorine", "nitrogen", "phosphorus", "arsenic", "antimony", "bismuth", "oxygen", "sulfur", "selenium", "tellurium", "polonium", "fluorine", "chlorine", "bromine", "iodine", "astatine"};
    srand(time(NULL)); //Seeding the random generator with current time

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given %d questions to answer.\n", num_quiz);
    printf("To answer, simply enter the atomic number of the element.\n");

    for(i=0; i<num_quiz; i++){
        ans = elements[rand()%50]; //Selecting a random element from the list of 50 elements
        printf("\nQuestion %d:\n", i+1);
        printf("What is the atomic number of %s? ", element_names[ans-1]);
        scanf("%d", &guess);
        if(guess == ans){
            printf("Correct!\n");
            num_correct++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n", ans);
        }
    }

    printf("\nYou have completed the quiz!\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, num_quiz);
    if(num_correct == num_quiz){
        printf("Excellent work! You really know your elements!\n");
    }
    else if(num_correct >= num_quiz/2){
        printf("Not bad! You have a decent knowledge of the elements.\n");
    }
    else{
        printf("Looks like you could use some more practice. Keep studying the periodic table!\n");
    }

    return 0;
}