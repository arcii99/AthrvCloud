//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void rollDice(){
    int num;
    printf("What type of dice do you want to roll?\n");
    printf("1. D4\n2. D6\n3. D8\n4. D10\n5. D12\n6. D20\n7. D100\n");
    scanf("%d", &num);
    switch(num){
        case 1:
            printf("You rolled a D4 and got: %d\n", rand()%4 + 1);
            break;
        case 2:
            printf("You rolled a D6 and got: %d\n", rand()%6 + 1);
            break;
        case 3:
            printf("You rolled a D8 and got: %d\n", rand()%8 + 1);
            break;
        case 4:
            printf("You rolled a D10 and got: %d\n", rand()%10 + 1);
            break;
        case 5:
            printf("You rolled a D12 and got: %d\n", rand()%12 + 1);
            break;
        case 6:
            printf("You rolled a D20 and got: %d\n", rand()%20 + 1);
            break;
        case 7:
            printf("You rolled a D100 and got: %d\n", rand()%100 + 1);
            break;
        default:
            printf("Invalid input, please select a valid option.\n");
            rollDice();
            break;
    }
}

int main(){
    printf("Welcome to the Dice Roller!\n");
    printf("Press enter to roll a dice...\n");
    getchar(); // waits for enter
    srand(time(NULL)); // seeds random function with current time
    rollDice();
    getchar(); // waits for enter
    return 0;
}