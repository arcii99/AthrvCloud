//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<time.h>

typedef struct{
    char original[101];
    char typed[101];
    int time;
    int errors;
}TypingTest;

int main(){
    int seconds, c, i, correct;
    char str[101];
    TypingTest test;

    srand(time(0));
    printf("*** Welcome to the Shape Shifting Typing Test! ***\n\n");

    //loop to generate random shape shifting string
    for(i=0;i<101;i++){
        c=rand()%26+97;     //generate random ASCII value and convert to lowercase alphabet
        if(rand()%2) c-=32; //randomly convert some to uppercase 
        str[i]=c;
    }
    str[100]='\0'; //terminate the string

    printf("Type the following text as fast as you can!\n\n%s\n\n",str);

    //start timer
    time_t start, end;
    time(&start);

    //loop to take user's input
    i=0;
    while((c=getchar())!=10){    //10 is ASCII value of newline character
        if(i==100){ //limit input to 100 characters
            printf("You have exceeded the character limit!\n");
            return 0;
        }
        else if(isalpha(c)){
            if(c>=65 && c<=90) c+=32;   //convert any uppercase letters to lowercase
            if(c==str[i]){  //if input is correct
                test.typed[i]=c;
                i++;
                correct=1;
            }
            else{   //if input is incorrect
                printf("%c",7); //make a beep sound
                test.errors++;
                correct=0;
            }
        }
        else if(c==127 && i>0){ //special case for backspace key
            test.typed[i-1]='\0';
            i--;
            if(correct) test.errors--;  //adjust the error count if the last input was correct
        }
    }
    time(&end);
    test.time=difftime(end,start);

    //print results
    printf("\nGreat job!\n\n");
    printf("Original Text: %s\n",str);
    printf("Your Input:    %s\n",test.typed);
    printf("Typing Time:   %d seconds\n",test.time);
    printf("Errors:        %d\n",test.errors);

    return 0;
}