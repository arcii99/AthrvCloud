//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define QUESTION_LEN 50
#define MAX_ANSWERS 4
#define ANSWER_LEN 20

// struct to hold a periodic table element
struct Element {
    char symbol[3];
    char name[20];
};

// struct to hold a quiz question
struct Question {
    char question[QUESTION_LEN];
    char answers[MAX_ANSWERS][ANSWER_LEN];
    int correct_answer;
};

// function to shuffle an array of integers
void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // array of periodic table elements
    struct Element elements[] = {
        {"H", "Hydrogen"},
        {"He", "Helium"},
        {"Li", "Lithium"},
        {"Be", "Beryllium"},
        {"B", "Boron"},
        {"C", "Carbon"},
        {"N", "Nitrogen"},
        {"O", "Oxygen"},
        {"F", "Fluorine"},
        {"Ne", "Neon"},
        {"Na", "Sodium"},
        {"Mg", "Magnesium"},
        {"Al", "Aluminum"},
        {"Si", "Silicon"},
        {"P", "Phosphorus"},
        {"S", "Sulfur"},
        {"Cl", "Chlorine"},
        {"Ar", "Argon"},
        {"K", "Potassium"},
        {"Ca", "Calcium"}
    };

    // array of quiz questions
    struct Question questions[MAX_QUESTIONS] = {
        {"What is the symbol for Carbon?", {"A. H", "B. He", "C. C", "D. O"}, 2},
        {"What is the name for Na?", {"A. Neon", "B. Nitrogen", "C. Sodium", "D. Oxygen"}, 2},
        {"What is the symbol for Oxygen?", {"A. O", "B. Si", "C. Mg", "D. Cl"}, 0},
        {"What is the name for B?", {"A. Boron", "B. Beryllium", "C. Carbon", "D. Aluminum"}, 0},
        {"What is the symbol for Sulfur?", {"A. Ti", "B. Kr", "C. S", "D. Ag"}, 2},
        {"What is the name for Mg?", {"A. Magnesium", "B. Manganese", "C. Mercury", "D. Molybdenum"}, 0},
        {"What is the symbol for Neon?", {"A. Ar", "B. Na", "C. He", "D. Ne"}, 3},
        {"What is the name for Cl?", {"A. Calcium", "B. Chlorine", "C. Cobalt", "D. Chromium"}, 1},
        {"What is the symbol for Potassium?", {"A. Pu", "B. Pr", "C. Pd", "D. K"}, 3},
        {"What is the name for Silicon?", {"A. Sulfur", "B. Silicon", "C. Silver", "D. Sodium"}, 1},
        {"What is the symbol for Calcium?", {"A. Ca", "B. Cm", "C. Cd", "D. Cl"}, 0},
        {"What is the name for Nitrogen?", {"A. Neon", "B. Nitrogen", "C. Nickel", "D. Nobelium"}, 1},
        {"What is the symbol for Helium?", {"A. He", "B. H", "C. Li", "D. Be"}, 0},
        {"What is the name for Aluminum?", {"A. Aluminum", "B. Actinium", "C. Arsenic", "D. Astatine"}, 0},
        {"What is the symbol for Chlorine?", {"A. Cm", "B. Cr", "C. Cl", "D. Cd"}, 2},
        {"What is the name for Potassium?", {"A. Potassium", "B. Palladium", "C. Platinum", "D. Phosphorus"}, 0},
        {"What is the symbol for Lithium?", {"A. Li", "B. H", "C. He", "D. Be"}, 0},
        {"What is the name for Oxygen?", {"A. Oxygen", "B. Osmium", "C. Oganesson", "D. Osmium"}, 0},
        {"What is the symbol for Nitrogen?", {"A. Ni", "B. N", "C. Na", "D. Nb"}, 1},
        {"What is the name for Helium?", {"A. Hydrogen", "B. Helium", "C. Hafnium", "D. Hassium"}, 1}
    };

    // generate a shuffled array of question indices
    int question_indices[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        question_indices[i] = i;
    }
    shuffle(question_indices, MAX_QUESTIONS);

    // start the quiz
    int score = 0;
    printf("Welcome to the Periodic Table Quiz!\n\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int index = question_indices[i];
        struct Question question = questions[index];
        printf("%d. %s\n", i + 1, question.question);
        // generate a shuffled array of answer indices
        int answer_indices[MAX_ANSWERS];
        for (int j = 0; j < MAX_ANSWERS; j++) {
            answer_indices[j] = j;
        }
        shuffle(answer_indices, MAX_ANSWERS);
        // print the shuffled answer choices
        for (int j = 0; j < MAX_ANSWERS; j++) {
            int answer_index = answer_indices[j];
            printf("    %s\n", question.answers[answer_index]);
        }
        // get user input for the answer
        char input;
        printf("Enter your answer (A, B, C, D): ");
        scanf("%c%*c", &input);
        // check if the answer is correct
        int selection = input - 'A';
        if (selection == question.correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c. %s\n\n", question.correct_answer + 'A', question.answers[question.correct_answer]);
        }
    }
    // print the final score
    printf("Quiz complete! You scored %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}