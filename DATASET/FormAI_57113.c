//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_CATEGORY 3
#define MAX_OPTIONS 4

// Category Struct
typedef struct Category {
    char name[20];
    int num_questions;
} Category;

// Question Struct
typedef struct Question {
    char text[256];
    char options[MAX_OPTIONS][64];
    int answer;
} Question;

// Function to create categories array
void create_categories(Category categories[]) {
    strcpy(categories[0].name, "Element Symbol");
    categories[0].num_questions = 5;
    strcpy(categories[1].name, "Atomic Number");
    categories[1].num_questions = 3;
    strcpy(categories[2].name, "Element Name");
    categories[2].num_questions = 2;
}

// Function to create questions array
void create_questions(Question questions[]) {
    strcpy(questions[0].text, "What is the symbol for Carbon?");
    strcpy(questions[0].options[0], "Ca");
    strcpy(questions[0].options[1], "C");
    strcpy(questions[0].options[2], "Co");
    strcpy(questions[0].options[3], "Cu");
    questions[0].answer = 1;
    strcpy(questions[1].text, "What is the atomic number for Oxygen?");
    strcpy(questions[1].options[0], "6");
    strcpy(questions[1].options[1], "8");
    strcpy(questions[1].options[2], "10");
    strcpy(questions[1].options[3], "12");
    questions[1].answer = 2;
    strcpy(questions[2].text, "What is the name of element 'Fe'?");
    strcpy(questions[2].options[0], "Iron");
    strcpy(questions[2].options[1], "Gold");
    strcpy(questions[2].options[2], "Lead");
    strcpy(questions[2].options[3], "Tin");
    questions[2].answer = 0;
    strcpy(questions[3].text, "What is the symbol for Potassium?");
    strcpy(questions[3].options[0], "K");
    strcpy(questions[3].options[1], "P");
    strcpy(questions[3].options[2], "Pa");
    strcpy(questions[3].options[3], "Kr");
    questions[3].answer = 0;
    strcpy(questions[4].text, "What is the symbol for Helium?");
    strcpy(questions[4].options[0], "He");
    strcpy(questions[4].options[1], "H");
    strcpy(questions[4].options[2], "Ne");
    strcpy(questions[4].options[3], "Be");
    questions[4].answer = 0;
    strcpy(questions[5].text, "What is the atomic number for Hydrogen?");
    strcpy(questions[5].options[0], "2");
    strcpy(questions[5].options[1], "3");
    strcpy(questions[5].options[2], "5");
    strcpy(questions[5].options[3], "7");
    questions[5].answer = 1;
    strcpy(questions[6].text, "What is the symbol for Sodium?");
    strcpy(questions[6].options[0], "Na");
    strcpy(questions[6].options[1], "N");
    strcpy(questions[6].options[2], "Ni");
    strcpy(questions[6].options[3], "Nb");
    questions[6].answer = 0;
    strcpy(questions[7].text, "What is the atomic number for Chlorine?");
    strcpy(questions[7].options[0], "12");
    strcpy(questions[7].options[1], "16");
    strcpy(questions[7].options[2], "20");
    strcpy(questions[7].options[3], "24");
    questions[7].answer = 1;
    strcpy(questions[8].text, "What is the name of element 'Na'?");
    strcpy(questions[8].options[0], "Sodium");
    strcpy(questions[8].options[1], "Chlorine");
    strcpy(questions[8].options[2], "Phosphorus");
    strcpy(questions[8].options[3], "Calcium");
    questions[8].answer = 0;
    strcpy(questions[9].text, "What is the symbol for Zinc?");
    strcpy(questions[9].options[0], "Z");
    strcpy(questions[9].options[1], "Zn");
    strcpy(questions[9].options[2], "Ni");
    strcpy(questions[9].options[3], "Zr");
    questions[9].answer = 1;
}

// Function to shuffle array
void shuffle_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Create categories array
    Category categories[MAX_CATEGORY];
    create_categories(categories);

    // Create questions array
    Question questions[MAX_QUESTIONS];
    create_questions(questions);

    // Prepare question order array for each category
    int category_questions[MAX_CATEGORY][MAX_QUESTIONS];
    for (int i = 0; i < MAX_CATEGORY; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            category_questions[i][j] = j;
        }
        shuffle_array(category_questions[i], categories[i].num_questions);
    }

    // Play the quiz
    int score = 0;
    for (int i = 0; i < MAX_CATEGORY; i++) {
        printf("\n----------------\n");
        printf("Category %s\n", categories[i].name);
        printf("----------------\n");

        for (int j = 0; j < categories[i].num_questions; j++) {
            int question_index = category_questions[i][j];

            printf("\n%s\n", questions[question_index].text);
            for (int k = 0; k < MAX_OPTIONS; k++) {
                printf("%d. %s\n", k+1, questions[question_index].options[k]);
            }

            int user_answer;
            printf("Enter your answer (1-4): ");
            scanf("%d", &user_answer);

            if (user_answer == questions[question_index].answer+1) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer was %s.\n", questions[question_index].options[questions[question_index].answer]);
            }
        }
    }

    printf("\n----------------\n");
    printf("Quiz complete!\n");
    printf("Final score: %d/%d\n", score, MAX_QUESTIONS);
    printf("----------------\n");
    
    return 0;
}