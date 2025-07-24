//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_ANS_LEN 50

// Structure to hold the question data
struct question {
    char text[1000];
    char options[4][100];
    int correct_option;
};

// Helper function to clear the terminal screen
void clear_screen() {
    printf("\033[2J\033[1;1H");
}

// Helper function to print a separator line
void print_separator() {
    printf("----------------------------------------\n");
}

// Helper function to shuffle an array of integers
void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Helper function to read a single line of input from the user
void read_line(char buffer[], int max_len) {
    fgets(buffer, max_len, stdin);
    buffer[strlen(buffer)-1] = '\0';
}

// Function to load questions from a file
int load_questions(struct question *questions, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    int num_questions = 0;
    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        // Parse the question text
        strcpy(questions[num_questions].text, line);

        // Parse the answer options
        for (int i = 0; i < 4; i++) {
            fgets(line, 1000, file);
            strcpy(questions[num_questions].options[i], line);
        }

        // Parse the correct answer index
        fgets(line, 1000, file);
        questions[num_questions].correct_option = atoi(line);

        num_questions++;
        if (num_questions == MAX_QUESTIONS) {
            break;
        }
    }

    fclose(file);
    return num_questions;
}

// Function to print a single question
void print_question(struct question q) {
    printf("%s\n", q.text);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s", i+1, q.options[i]);
    }
}

// Function to administer a single question
int administer_question(struct question q) {
    int answer;
    do {
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
    } while (answer < 1 || answer > 4);

    if (answer == q.correct_option) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer was %d.\n", q.correct_option);
        return 0;
    }
}

// Function to administer the entire exam
void administer_exam(struct question *questions, int num_questions) {
    // Shuffle the question order
    int question_order[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        question_order[i] = i;
    }
    shuffle(question_order, num_questions);

    // Administer each question in turn
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        clear_screen();
        print_separator();
        printf("Question %d/%d:\n", i+1, num_questions);
        print_question(questions[question_order[i]]);
        score += administer_question(questions[question_order[i]]);
        sleep(2);
    }

    // Print the final score
    clear_screen();
    print_separator();
    printf("Exam complete. Final score: %d/%d\n", score, num_questions);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <question_file>\n", argv[0]);
        return 0;
    }

    struct question questions[MAX_QUESTIONS];
    int num_questions = load_questions(questions, argv[1]);
    if (!num_questions) {
        return 1;
    }

    administer_exam(questions, num_questions);

    return 0;
}