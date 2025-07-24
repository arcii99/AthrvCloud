//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int command;
    printf("Welcome to the Chatbot Movement Control Program! \n");
    printf("Please enter your commands: \n");

    do {
        printf("\n1 - Move Forward \n2 - Move Backward \n3 - Turn Left \n");
        printf("4 - Turn Right \n5 - Stop \n6 - Dance \n7 - Exit \n");
        printf("\nEnter your command (1-7): ");

        scanf("%d", &command);
        command = tolower(command);

        switch (command) {
            case 1:
                printf("\nMoving forward...\n");
                break;
            case 2:
                printf("\nMoving backward...\n");
                break;
            case 3:
                printf("\nTurning left...\n");
                break;
            case 4:
                printf("\nTurning right...\n");
                break;
            case 5:
                printf("\nStopping...\n");
                break;
            case 6:
                printf("\nLet's dance! Cha Cha Cha Cha...\n");
                break;
            case 7:
                printf("\nGoodbye! I hope you had fun controlling me! :)\n");
                break;
            default:
                printf("\nInvalid command! Please enter a valid command.\n");
        }

    } while (command != 7);

    return 0;
}