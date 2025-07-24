//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

int score = 0;

typedef struct 
{
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
} Question;

// Sample questions
Question questions[MAX_QUESTIONS] = {
    {"What is the symbol for Sodium?", {"Na", "No", "Sa", "So"}, 0},
    {"What is the atomic number of Iron?", {"23", "24", "25", "26"}, 3},
    {"What is the symbol for Helium?", {"H", "He", "Hl", "Hee"}, 1},
    {"What is the atomic number of Carbon?", {"5", "6", "7", "8"}, 1},
    {"What is the symbol for Oxygen?", {"O", "Om", "Ox", "Oy"}, 0},
    {"What is the atomic number of Neon?", {"8", "9", "10", "11"}, 2},
    {"What is the symbol for Zinc?", {"Zc", "Zn", "Zd", "Zl"}, 1},
    {"What is the atomic number of Silver?", {"46", "47", "48", "49"}, 1},
    {"What is the symbol for Neon?", {"Ne", "Na", "Ni", "No"}, 0},
    {"What is the atomic number of Magnesium?", {"11", "12", "13", "14"}, 1},
    {"What is the symbol for Carbon?", {"Ca", "Ci", "Cn", "C"}, 3},
    {"What is the atomic number of Oxygen?", {"6", "7", "8", "9"}, 2},
    {"What is the symbol for Zinc?", {"Zc", "Zn", "Zd", "Zl"}, 1},
    {"What is the atomic number of Silver?", {"46", "47", "48", "49"}, 1},
    {"What is the symbol for Neon?", {"Ne", "Na", "Ni", "No"}, 0},
    {"What is the atomic number of Magnesium?", {"11", "12", "13", "14"}, 1},
    {"What is the symbol for Carbon?", {"Ca", "Ci", "Cn", "C"}, 3},
    {"What is the atomic number of Oxygen?", {"6", "7", "8", "9"}, 2},
    {"What is the symbol for Zinc?", {"Zc", "Zn", "Zd", "Zl"}, 1},
    {"What is the atomic number of Silver?", {"46", "47", "48", "49"}, 1},
};

void shuffle(int arr[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int check_answer(int answer, int correct_option)
{
    if(answer == correct_option)
    {
        printf("Correct answer!\n");
        score++;
        return 1;
    }
    else
    {
        printf("Incorrect answer.\n");
        return 0;
    }
}

void ask_question(Question question)
{
    printf("%s\n", question.question);
    int option_indices[MAX_OPTIONS] = {0, 1, 2, 3};
    shuffle(option_indices, MAX_OPTIONS);

    for(int i = 0; i < MAX_OPTIONS; i++)
    {
        int index = option_indices[i];
        printf("%d) %s\n", i+1, question.options[index]);
    }

    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    check_answer(answer-1, question.correct_option);
}

int main()
{   
    int question_indices[MAX_QUESTIONS];
    for(int i = 0; i < MAX_QUESTIONS; i++)
    {
        question_indices[i] = i;
    }
    shuffle(question_indices, MAX_QUESTIONS);

    printf("Welcome to the Periodic Table Quiz!\n");

    for(int i = 0; i < MAX_QUESTIONS; i++)
    {
        Question question = questions[question_indices[i]];
        ask_question(question);
    }

    printf("Quiz complete! Your final score is: %d/%d\n", score, MAX_QUESTIONS);
    return 0;
}