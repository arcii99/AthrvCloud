//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random words for typing test
char* randomWords(){
    char* words[10] = {"hello", "world", "technology", "computer", "science", "programming", "internet", "keyboard", "software", "algorithm"};
    int randomIndex = rand() % 10;
    return words[randomIndex];
}

//function to calculate typing speed and accuracy
void calculateTypingSpeed(char userInput[], char* randomString, int timeTaken){
    float accuracy = 0.0;
    int correctCharacters = 0;
    for(int i=0; i<strlen(userInput); i++){
        if(userInput[i] == randomString[i]){
            correctCharacters++;
        }
    }
    accuracy = ((float)correctCharacters/strlen(randomString)) * 100;
    float speed = (float)strlen(randomString)/(timeTaken/60.0);
    printf("\nYou typed: %s", userInput);
    printf("\nAccuracy: %.2f%%", accuracy);
    printf("\nTyping Speed: %.2f words per minute", speed);
}

int main(){
    printf("\t\tTyping Speed Test\n");
    printf("-----------------------------------------------------------------\n");
    printf("\nInstructions:\n1. Read the given word(s) below.\n2. Type the same word(s) as fast as you can.\n3. Press enter when finished.");
    printf("\n\n");
    while(1){
        char* randomString = randomWords();
        printf("%s: ", randomString);
        time_t start = time(0);
        char userInput[100];
        fgets(userInput, 100, stdin);
        time_t end = time(0);
        int timeTaken = end - start;
        calculateTypingSpeed(userInput, randomString, timeTaken);
        printf("\n\n");
    }
    return 0;
}