//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to read the questions from a file */
void read_questions(int num_questions, char *filename, char **questions) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int i = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (i >= num_questions) {
            break;
        }
        questions[i] = strdup(line);
        i++;
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

/* Function to display a question and accept an answer */
int ask_question(char *question, char *answer) {
    printf("%s", question);
    fflush(stdout);

    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    if (strcmp(input, answer) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The answer is %s.\n", answer);
        return 0;
    }
}

int main() {
    int num_questions = 10;
    char *filename = "questions.txt";
    char *questions[num_questions];
    char *answers[num_questions];

    read_questions(num_questions, filename, questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Question #%d\n", i + 1);
        ask_question(questions[i], answers[i]);
    }

    printf("Exam complete! Thanks for taking the test.\n");
    return 0;
}