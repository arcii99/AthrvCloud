//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define NUM_OF_ELEMENTS 118 //total number of elements in the periodic table
#define NUM_OF_QUESTIONS 10 //number of questions in the quiz

void initialize_elements_array(char** elements_array) {
    //initialize the array with the names of the elements
    elements_array[0] = "Hydrogen";
    elements_array[1] = "Helium";
    elements_array[2] = "Lithium";
    elements_array[3] = "Beryllium";
    elements_array[4] = "Boron";
    elements_array[5] = "Carbon";
    elements_array[6] = "Nitrogen";
    elements_array[7] = "Oxygen";
    elements_array[8] = "Fluorine";
    elements_array[9] = "Neon";
    //... and so on for the other 109 elements
}

void shuffle(int* array, int n) {
    //shuffle array of element indices to randomize order of questions
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int check_answer(char* user_answer, char* correct_answer) {
    //check if user's answer matches the correct answer
    if (strcmp(user_answer, correct_answer) == 0) {
        printf("Correct!\n");
        return 1;
    }
    else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer);
        return 0;
    }
}

int main() {
    char* elements_array[NUM_OF_ELEMENTS];
    initialize_elements_array(elements_array);

    int element_indices_array[NUM_OF_ELEMENTS];
    for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
        element_indices_array[i] = i;
    }

    //shuffle array of element indices
    shuffle(element_indices_array, NUM_OF_ELEMENTS);

    printf("*** Welcome to the Periodic Table Quiz! ***\n"
           "You will be presented with %d questions.\n"
           "For each question, guess the element symbol corresponding to the name provided.\n"
           "Enter 'quit' or 'exit' to end the quiz early.\n\n", NUM_OF_QUESTIONS);

    int score = 0;
    char answer[3];
    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        char* element_name = elements_array[element_indices_array[i]];
        char element_initial = toupper(element_name[0]); //get initial letter of element symbol
        printf("Question %d: What is the symbol for %s? ", i+1, element_name);
        scanf("%s", answer);

        if (strcmp(answer, "quit") == 0 || strcmp(answer, "exit") == 0) {
            break;
        }

        if (strlen(answer) != 2) {
            printf("Invalid input. Enter a two-letter element symbol.\n");
            i--; //redo this question
            continue;
        }

        if (!isupper(answer[0]) || !islower(answer[1])) {
            printf("Invalid input. Enter a two-letter element symbol.\n");
            i--; //redo this question
            continue;
        }

        if (answer[0] == element_initial && answer[1] == tolower(element_name[1])) {
            score++;
            printf("Correct!\n");
        }
        else {
            printf("Incorrect. The correct symbol is %c%c.\n", element_initial, tolower(element_name[1]));
        }
    }

    printf("\nQuiz completed. Final score: %d / %d.\n", score, NUM_OF_QUESTIONS);
    return 0;
}