//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    char group[5];
    char period[3];
} Element;

const Element periodic_table[] = {
        {"H", "Hydrogen", 1, "1", "1"},
        {"He", "Helium", 2, "18", "1"},
        {"Li", "Lithium", 3, "1", "2"},
        {"Be", "Beryllium", 4, "2", "2"},
        {"B", "Boron", 5, "13", "2"},
        {"C", "Carbon", 6, "14", "2"},
        {"N", "Nitrogen", 7, "15", "2"},
        {"O", "Oxygen", 8, "16", "2"},
        {"F", "Fluorine", 9, "17", "2"},
        {"Ne", "Neon", 10, "18", "2"},
        {"Na", "Sodium", 11, "1", "3"},
        {"Mg", "Magnesium", 12, "2", "3"},
        {"Al", "Aluminium", 13, "13", "3"},
        {"Si", "Silicon", 14, "14", "3"},
        {"P", "Phosphorus", 15, "15", "3"},
        {"S", "Sulfur", 16, "16", "3"},
        {"Cl", "Chlorine", 17, "17", "3"},
        {"Ar", "Argon", 18, "18", "3"},
        {"K", "Potassium", 19, "1", "4"},
        {"Ca", "Calcium", 20, "2", "4"}
};

void shuffle_questions(int *questions) {
    srand(time(NULL));
    int i, j, temp;
    for (i = MAX_QUESTIONS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    int questions[MAX_QUESTIONS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle_questions(questions);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer 10 multiple choice questions to test your knowledge of the elements.\n\n");

    int i, score = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        int question_num = questions[i];
        Element element = periodic_table[question_num];

        printf("Question %d: What is the symbol for %s?\n", i + 1, element.name);
        printf("A) %s\n", element.symbol);
        printf("B) %s\n", periodic_table[(question_num + 1) % MAX_QUESTIONS].symbol);
        printf("C) %s\n", periodic_table[(question_num + 2) % MAX_QUESTIONS].symbol);

        char user_choice;
        printf("Enter your choice (A, B, or C): ");
        scanf(" %c", &user_choice);

        if (user_choice == 'A') {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", element.symbol);
        }

        printf("Press enter to continue.\n");
        getchar();
    }

    printf("\nCongratulations, you completed the quiz!\n");
    printf("Final score: %d/10\n", score);

    return 0;
}