//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("\nWelcome to the Happy Typing Speed Test!\n");
    printf("Get ready to type your way to happiness!\n");

    printf("\nInstructions:\n");
    printf("1. Type the given sentence in the least amount of time.\n");
    printf("2. Your accuracy and speed will be tracked.\n");
    printf("3. Type the exact sentence, including special characters and spaces.\n");
    printf("4. If you make a mistake, keep going and try to correct it later.\n");

    printf("\nAre you ready? Press any key to start the test!\n");
    getchar();

    char sentence[] = "The quick brown fox jumps over the lazy dog.";
    printf("\nType this sentence as fast as you can:\n\n%s\n", sentence);

    clock_t start_time = clock();

    char user_input[100];
    scanf("%[^\n]s", user_input);

    int diff_time = (int)(clock() - start_time);
    int typing_speed = (strlen(sentence)*60)/diff_time;
    int accuracy = 0;

    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i]==user_input[i]){
            accuracy++;
        }
    }
    float accuracy_percentage = (float)accuracy/strlen(sentence) * 100;

    printf("\nYour typing speed is: %d words per minute\n", typing_speed);
    printf("You typed with %.2f%% accuracy!\n", accuracy_percentage);

    if(accuracy_percentage>=80){
        printf("Congratulations! You are a happy typer!\n");
    }
    else{
        printf("Oops! Keep practicing to be a happy typer!\n");
    }

    return 0;
}