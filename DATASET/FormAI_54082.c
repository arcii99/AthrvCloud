//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

void displayLight(char c){
    system("clear");
    if(c == 'R')
        printf(" ___\n|   |\n| R |\n|___|\n");
    else if(c == 'A')
        printf(" ___\n|   |\n| A |\n|___|\n");
    else if(c == 'G')
        printf(" ___\n|   |\n| G |\n|___|\n");
    else
        printf("Invalid Input\n");
}

void delay(int seconds){
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock(); // returns the number of clock ticks elapsed since the program was launched
    while(clock() < start_time + milli_seconds); // keep the loop running until the desired time has elapsed
}

int main(){
    int i,j;
    char light[3] = "RAG";
    system("clear");
    printf("Initializing Traffic Light Controller...\n");
    delay(2);
    for(j=0;j<3;j++){
        displayLight(light[j]);
        delay(3);
    }
    for(i=0;i<5;i++){
        displayLight(light[0]);
        delay(4);
        displayLight(light[1]);
        delay(2);
        displayLight(light[2]);
        delay(4);
        displayLight(light[1]);
        delay(2);
    }
    displayLight('G');
    printf("Traffic Light Controller program has completed successfully.\n");
    return 0;
}