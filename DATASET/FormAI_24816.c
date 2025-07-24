//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char inputChar;         //variable to read user's input
    int count = 0;          //variable to keep count of correct input
    double timeTaken;       //variable to keep track of time taken
    time_t startTime, endTime;
    srand(time(NULL));

    printf("----------------------------------\n");
    printf("|      INVASIVE TYPING TEST      |\n");
    printf("----------------------------------\n\n");
    printf("Instructions: Type the following text as fast and accurately as you can.\n");

    //generate random sequence of characters
    char sequence[100];
    for(int i = 0; i < 100; i++){
        sequence[i] = (char) (rand() % 26 + 97);
        printf("%c", sequence[i]);      //print the sequence
    }
    printf("\n");

    startTime = time(NULL);     //start time counter

    //loop until user enters all correct input
    while(count < 100){
        inputChar = getchar();          //read user's input character
        if(inputChar == '\n') break;    //break if user presses enter
        if(inputChar == sequence[count]){
            count++;        //if correct input is entered increase the count
        }
    }
    endTime = time(NULL);       //end time counter
    timeTaken = difftime(endTime,startTime);   //calculate time taken

    if(count != 100){       //if user didn't enter all correct input
        printf("\nYou failed!\n");
    }
    else{       //if user entered all correct input
        printf("\nCongratulations, you have completed the typing test in %g seconds!\n", timeTaken);
    }

    return 0;
}