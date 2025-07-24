//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ON 1
#define OFF 0

int main(int argc, char *argv[]) {
    bool light_on = true;
    char password[] = "jumblywumbly";
    int i, j;

    printf("Welcome to smart home light control program!\n\n");

    printf("Enter the password to continue: ");

    char input[100];
    fgets(input, sizeof(input), stdin);

    for(i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    if(strcmp(input, password) == 0) {
        printf("Access granted.\n\n");
    } else {
        printf("Access denied.\n");
        exit(0);
    }

    printf("You can now control the lights by following the instructions below:\n");
    printf("Type 'on' to turn the light on or 'off' to turn it off.\n");

    while(true) {
        char command[10];
        fgets(command, sizeof(command), stdin);

        if(strncmp("on", command, 2) == 0) {
            if(light_on == false) {
                light_on = true;
                printf("The light is now on.\n");
            } else {
                printf("The light is already on.\n");
            }
        } else if(strncmp("off", command, 3) == 0) {
            if(light_on == true) {
                light_on = false;
                printf("The light is now off.\n");
            } else {
                printf("The light is already off.\n");
            }
        } else {
            printf("Invalid command. Please type 'on' or 'off'.\n");
        }

        // Puzzle challenge
        for(j = 0; j < 100000; j++) {
            if(j % 10000 == 0 && j != 0) {
                printf("\n\nCan you solve this puzzle? ");
                printf("What number is divisible by 7, 8, 9, and 11?\nEnter your answer: ");

                int answer;
                scanf("%d", &answer);

                if(answer == 5544) {
                    printf("Correct! You may continue controlling the lights.\n\n");
                } else {
                    printf("Incorrect. You must solve the puzzle to continue controlling the lights.\n\n");
                    exit(0);
                }
            }
        }
    }

    return 0;
}