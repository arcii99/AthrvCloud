//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to your very own Smart Home Light Control System!\n");
    printf("You'll never have to fumble for a light switch again!\n\n");

    srand(time(NULL));
    int onOff = rand() % 2;

    if(onOff){
        printf("The lights in your house are currently ON.\n");
    }else{
        printf("The lights in your house are currently OFF.\n");
    }

    printf("Would you like to turn the lights ON or OFF? (Type '1' for ON or '0' for OFF)\n");

    int userChoice;
    scanf("%d", &userChoice);

    if(userChoice == 1){
        printf("Turning lights ON...\n");
    }else{
        printf("Turning lights OFF...\n");
    }

    printf("Done! The lights are now ");

    if(userChoice == onOff){
        printf("still ");
    }

    if(userChoice){
        printf("ON!");
    }else{
        printf("OFF!");
    }

    return 0;
}