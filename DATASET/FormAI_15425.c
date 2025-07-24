//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>

#define NUM_QUESTIONS 10
#define QUESTION_SIZE 200
#define ANSWER_SIZE 20

typedef struct {
    char question[QUESTION_SIZE];
    char answer[ANSWER_SIZE];
} Question;

int questionIndex = 0;
int correctAnswers = 0;
Question questions[NUM_QUESTIONS];

void sigintHandler(int signal) {
    printf("\nExam Terminated.\n");
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, NUM_QUESTIONS);
    exit(0);
}

void loadQuestions() {
    int fd = open("questions.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error: Can't open questions.txt file\n");
        exit(1);
    }

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char buffer[QUESTION_SIZE + ANSWER_SIZE + 2];
        int offset = i * (QUESTION_SIZE + ANSWER_SIZE + 2);
        lseek(fd, offset, SEEK_SET);
        read(fd, buffer, QUESTION_SIZE + ANSWER_SIZE + 2);
        sscanf(buffer, "%[^?]?%[^,],", questions[i].question, questions[i].answer);
    }

    close(fd);
}

void askQuestion() {
    printf("\nQuestion %d: %s?\n", questionIndex + 1, questions[questionIndex].question);
    char answer[ANSWER_SIZE];
    fgets(answer, ANSWER_SIZE, stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(questions[questionIndex].answer, answer) == 0) {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", questions[questionIndex].answer);
    }

    questionIndex++;
}

void timer() {
    sleep(120);
    printf("\n\nTime is up!\n");
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, NUM_QUESTIONS);
    exit(0);
}

int main() {
    printf("Welcome to the C Exam.\n");
    loadQuestions();
    signal(SIGINT, sigintHandler);
    signal(SIGALRM, timer);
    alarm(120);

    while (questionIndex != NUM_QUESTIONS) {
        askQuestion();
    }

    printf("\nCongratulations! You answered all questions correctly.\n");
    return 0;
}