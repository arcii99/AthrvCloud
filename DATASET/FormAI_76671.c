//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char name[20];
    int age, num;
    srand(time(NULL));
    printf("Welcome to the Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    if(age < 18){
        printf("Sorry %s, you must be 18 or older to use the Fortune Teller.\n", name);
        return 0;
    }
    
    printf("\nHello %s, let's start!\n", name);
    printf("Think of a number between 1 and 10 and enter it: ");
    scanf("%d", &num);
    int randNum = rand() % 10 + 1;
    if(num == randNum){
        printf("\nCongratulations %s, you have won the jackpot!\n", name);
        printf("Your lucky number was %d and the computer generated %d!\n", num, randNum);
    } else {
        printf("\nSorry %s, better luck next time!\n", name);
        printf("Your input was %d and the computer generated %d.\n", num, randNum);
    }
    return 0;
}