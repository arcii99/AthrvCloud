//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SIZE 100
#define MAX_TIME 60

void displayInstructions();
void generateText(char *text);
int calculateTypingSpeed(int time, char *userInput, char *generatedText);

int main() {
    char text[SIZE], userInput[SIZE];
    int timeElapsed, typingSpeed;

    displayInstructions();
    generateText(text);

    clock_t start = clock();

    printf("%s\n", text);
    printf("Type the above text as fast as you can...\n");

    fgets(userInput, SIZE, stdin);

    clock_t end = clock();
    timeElapsed = (end - start) / CLOCKS_PER_SEC;

    typingSpeed = calculateTypingSpeed(timeElapsed, userInput, text);

    printf("Total time taken: %d seconds\n", timeElapsed);
    printf("Typing speed: %d words per minute\n", typingSpeed);

    return 0;
}

void displayInstructions() {
    printf("==============================================\n");
    printf("\tWelcome to the Typing Speed Test\n");
    printf("==============================================\n");
    printf("Instructions:\n");
    printf("1. You will be given a random text to type.\n");
    printf("2. Your task is to type the whole text as fast as\n   you can.\n");
    printf("3. Your typing speed will be calculated in words\n   per minute.\n");
    printf("4. You have maximum %d seconds to complete the test.\n", MAX_TIME);
    printf("5. Press ENTER to start the test.\n");
    printf("==============================================\n");

    getchar();
}

void generateText(char *text) {
    char *words[] = {"apple", "banana", "cherry", "orange", "grapes", "kiwi", "mango", "pear", "pineapple", "watermelon"};
    int randomIndex, i;

    srand(time(NULL));
    for(i = 0; i < SIZE - 1; i++) {
        randomIndex = (rand() % 10);
        strcat(text, words[randomIndex]);
        if(i != SIZE - 2) {
            strcat(text, " ");
        }
    }

    text[SIZE - 1] = '\0';
}

int calculateTypingSpeed(int timeElapsed, char *userInput, char *generatedText) {
    int i, words = 0, correctWords = 0;
    char *word;

    word = strtok(generatedText, " ");

    while(word != NULL) {
        words++;

        if(strstr(userInput, word) != NULL) {
            correctWords++;
        }

        word = strtok(NULL, " ");
    }

    for(i = 0; userInput[i] != '\0'; i++) {
        if(userInput[i] == ' ') {
            words++;
        }
    }

    return (int)((double)correctWords / (double)timeElapsed) * 60;
}