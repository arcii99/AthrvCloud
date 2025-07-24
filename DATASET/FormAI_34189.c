//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type as fast and accurately as possible.\n");

    srand(time(NULL)); //initialize random seed based on current time
    char sentences[10][200] = {"The quick brown fox jumps over the lazy dog",
                                "She sells seashells by the seashore",
                                "I am the very model of a modern Major-General",
                                "To be or not to be, that is the question",
                                "There's no place like home",
                                "I wandered lonely as a cloud",
                                "It is a truth universally acknowledged, that a single man in possession of a good fortune, must be in want of a wife",
                                "Four score and seven years ago our fathers brought forth on this continent a new nation, conceived in liberty, and dedicated to the proposition that all men are created equal",
                                "It was the best of times, it was the worst of times",
                                "In a hole in the ground there lived a hobbit"};
    int random = rand()%10; //select a random sentence to type

    printf("\nYour sentence to type is:\n%s\n\n", sentences[random]);
    printf("Type the sentence as fast and accurately as possible and press enter when finished:\n");

    char input[200];
    scanf("%[^\n]%*c", input); //read in user input until enter key is pressed

    //compare user input to sentence and calculate accuracy and typing speed
    float accuracy = 0;
    int i = 0, incorrect = 0;
    clock_t startTime, endTime;
    startTime = clock();
    for(i = 0; i < strlen(sentences[random]); i++){
        if(sentences[random][i] != input[i]) incorrect++;
    }
    endTime = clock();

    accuracy = ((float)strlen(sentences[random])-incorrect)/(float)strlen(sentences[random]);
    float timeElapsed = (float)(endTime - startTime)/CLOCKS_PER_SEC;
    printf("\nYour typing accuracy is: %.2f%%\n", accuracy*100);
    printf("Your typing speed is: %.2f characters per second\n", ((float)strlen(sentences[random])/timeElapsed));

    return 0;
}