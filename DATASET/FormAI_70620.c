//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Size of the question bank.
#define MAX_QSN_BANK_SIZE 20

// Size of each question.
#define MAX_QSN_SIZE 100

// Main function to run the application.
int main() {
    char qsnBank[MAX_QSN_BANK_SIZE][MAX_QSN_SIZE];
    char ansOptions[MAX_QSN_BANK_SIZE][4][MAX_QSN_SIZE];
    int ansIndex[MAX_QSN_BANK_SIZE];
    char optStr[] = {'A', 'B', 'C', 'D'};
    int chosenAns[MAX_QSN_BANK_SIZE];
    int numOfQsn = 0;

    printf("Welcome to the Online Examination System!\n");

    // Read questions from file and populate question bank.
    FILE* fp = fopen("questions.txt", "r");
    if(fp == NULL) {
        printf("Error reading from file.");
        return -1;
    }
    char line[MAX_QSN_SIZE];
    int lineCount = 0;
    while(fgets(line, MAX_QSN_SIZE, fp) != NULL) {
        if(lineCount % 5 == 0) {
            strcpy(qsnBank[numOfQsn], line);
        }
        else {
            int optIndex = (lineCount % 5) - 1;
            strcpy(ansOptions[numOfQsn][optIndex], line);
            // Check if this is the correct answer.
            if(line[0] == '*') {
                ansIndex[numOfQsn] = optIndex;
            }
        }
        lineCount++;
        // If all options have been added, then increase the number of questions counter.
        if(lineCount % 5 == 0) {
            numOfQsn++;
        }
    }
    fclose(fp);

    // Shuffle Questions.
    srand(time(NULL));
    for(int i=0; i<numOfQsn; i++) {
        int r = rand() % numOfQsn;
        char temp[MAX_QSN_SIZE];
        strcpy(temp, qsnBank[i]);
        strcpy(qsnBank[i], qsnBank[r]);
        strcpy(qsnBank[r], temp);

        for(int j=0; j<4; j++) {
            strcpy(temp, ansOptions[i][j]);
            strcpy(ansOptions[i][j], ansOptions[r][j]);
            strcpy(ansOptions[r][j], temp);
        }

        int t = ansIndex[i];
        ansIndex[i] = ansIndex[r];
        ansIndex[r] = t;
    }

    // Start exam.
    printf("\nYou have %d questions to answer. Best of luck!\n\n", numOfQsn);
    int score = 0;
    for(int i=0; i<numOfQsn; i++) {
        printf("%d) %s", i+1, qsnBank[i]);
        for(int j=0; j<4; j++) {
            printf("%c) %s", optStr[j], ansOptions[i][j]+1);
        }
        printf("Enter your answer: ");
        char ch;
        scanf("%c", &ch);
        // Check if user has entered valid input and update score.
        if(ch >= 'A' && ch <= 'D') {
            int ans = (int)ch - 'A';
            chosenAns[i] = ans;
            if(ans == ansIndex[i]) {
                score++;
            }
        }
        else {
            printf("Invalid input. Skipping the question.\n");
            chosenAns[i] = -1;
        }
        // Consume the newline character.
        getchar();
    }

    // Display the result.
    printf("\n\nYour score is %d out of %d.\n\n", score, numOfQsn);
    printf("The correct answers are:\n");
    for(int i=0; i<numOfQsn; i++) {
        printf("%d) %c\n", i+1, optStr[ansIndex[i]]);
    }
    printf("\n\nYour answers were:\n");
    for(int i=0; i<numOfQsn; i++) {
        if(chosenAns[i] == -1) {
            printf("%d) Skipped\n", i+1);
        }
        else {
            printf("%d) %c\n", i+1, optStr[chosenAns[i]]);
        }
    }
    return 0;
}