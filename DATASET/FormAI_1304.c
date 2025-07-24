//FormAI DATASET v1.0 Category: Funny ; Style: active
#include <stdio.h>

int main() {
    printf("Welcome to the Funny Program!\n");

    int userNum;

    printf("Please enter a number: ");
    scanf("%d", &userNum);

    printf("You entered: %d\n", userNum);

    if(userNum % 2 == 0) {
        printf("Ha! %d is an even number, just like me!\n", userNum);
    } else {
        printf("Hoho! %d is an odd number, just like my ex...\n", userNum);
    }

    int counter = 0;

    while(counter < userNum) {
        printf("I will not eat green eggs and ham. ");
        counter++;
    }

    printf("\n");

    for(int i = userNum; i >= 1; i--) {
        printf("I have %d bottles of beer on the wall, %d bottles of beer. Take one down, pass it around, %d bottles of beer on the wall...\n", i, i, i - 1);
    }

    printf("That's enough for today, folks! Bye bye!\n");

    return 0;
}