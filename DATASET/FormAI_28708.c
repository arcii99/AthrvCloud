//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char elements[20][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                            "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};
    int atomic_numbers[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int correct_answers = 0;
    int question_number = 1;

    printf("Welcome to the Cryptic C Periodic Table Quiz!\n\n");
    printf("Please answer the following questions with the atomic symbol of each element.\n\n");

    while (question_number <= 10){

        int element_random_index = rand() % 20;
        char element_random[3];
        strcpy(element_random, elements[element_random_index]);

        printf("Question %d: What is the atomic symbol for %s?\n", question_number, element_random);

        char user_answer[3];
        scanf("%s", user_answer);
        int user_answer_is_correct = strcmp(user_answer, element_random);

        if (user_answer_is_correct == 0){
            printf("Correct!\n\n");
            correct_answers++;
        }
        else{
            printf("Incorrect. The correct answer is %s\n\n", element_random);
        }

        question_number++;

    }

    printf("You answered %d out of 10 questions correctly!\n\n", correct_answers);

    return 0;

}