//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    char word[100] = "";
    char input[100] = "";
    int count = 0, correct = 0, incorrect = 0;
    double accuracy = 0.0, timeTaken = 0.0;
    clock_t start, end;
    srand(time(NULL));
    
    //Words to be typed
    char words[10][100] = {"programming", "algorithm", "keyboard", "developer", "interface", "compiler", "syntax", "application", "variable", "function"};
    
    printf("\nWelcome to the Typing speed test!\n");
    printf("Type the following words as fast as you can and press enter:\n\n");

    //Displaying words with gaps
    for(int i=0; i<10; i++){
        for(int j=0; j<strlen(words[i]); j++){
            printf("%c ", words[i][j]);
        }
        printf("\n");
    }

    printf("\nPress enter to start.\n");
    getchar();

    for(int i=0; i<10; i++){
        count = 0;
        printf("Type the word above: ");
        start = clock();
        fgets(input, 100, stdin); // get user input
        
        //removing the newline character
        if((strlen(input) > 0) && (input[strlen(input)-1] == '\n')){
            input[strlen(input)-1] = '\0';
        }
        
        end = clock();
        timeTaken += (double)(end - start) / CLOCKS_PER_SEC;
        
        //Checking the correctness of the word
        while(words[i][count] != '\0' && input[count] != '\0'){
            if(words[i][count] != input[count]){
                printf("\nIncorrect input. Please try again.\n");
                incorrect++;
                break;
            }
            count++;
        }
        
        if(strlen(words[i]) == strlen(input) && strcmp(words[i], input) == 0){
            printf("\nCorrect\n");
            correct++;
        }else if(strlen(words[i]) != strlen(input)){
            printf("\nIncorrect input. Please try again.\n");
            incorrect++;
        }
        
    }

    //calculating accuracy and speed
    accuracy = ((double)correct / (double)10) * 100;
    timeTaken = timeTaken * 100;
    
    printf("\n-----------------\n");
    printf("Test Results:\n");
    printf("-----------------\n");
    printf("Words typed correctly: %d out of %d\n", correct, 10);
    printf("Words typed incorrectly: %d out of %d\n", incorrect, 10);
    printf("Accuracy: %.2f %%\n", accuracy);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Typing speed: %.2f WPM\n", 60.0 / timeTaken * correct);

    printf("\nThanks for taking the test!\n");

    return 0;
}