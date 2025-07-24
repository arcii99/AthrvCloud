//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(unsigned int ms){
    clock_t goal = ms + clock();
    while(goal > clock());
}

int main(){
    while(1){
        float temperature = (rand() % 120) - 20;
        printf("\033[2J"); //Clear screen
        printf("\033[31m"); //Set color to red
        printf("\033[%d;%df",0,0); //Set cursor position
        printf("Temperature Monitor\n");
        printf("\033[32m"); //Set color to green
        printf("\033[%d;%df",2,0);
        printf("Current Temperature: %.2f", temperature);
        printf("\033[0m"); //Reset color
        delay(1000); //Wait for 1 second
    }
    return 0;
}