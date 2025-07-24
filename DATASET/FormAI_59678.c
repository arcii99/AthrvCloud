//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_delay(int sec) { //quick delay function in seconds
    int milli_seconds = 1000 * sec; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds);
}

void clear_input_buffer(void) { //clear input buffer function
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void explore_world() {
    printf("You are standing in an old forest. The trees are tall and the leaves are changing colors. You see a path to your east, and another path to your north.\n");
    while (1) {
        printf("\nWhere would you like to go? (east/north)\n> ");
        char direction[10];
        fgets(direction, 10, stdin);
        if (strcmp(direction, "east\n") == 0) {
            printf("You walk for what seems like hours, until you come across an abandoned cabin. It looks invitingly warm and cozy inside. Do you\n");
            printf("1. Enter the cabin\n2. Continue east\n> ");
            int choice;
            scanf("%d", &choice);
            clear_input_buffer();
            if (choice == 1) {
                printf("You push open the door to the cabin… only to find that it is completely empty. Frustrated, you exit and head back to the forest.\n");
            }
            else if (choice == 2) {
                printf("You continue to walk for another hour, until you come across a strange stone tower. It looks like it’s been abandoned for centuries…\n");
                printf("1. Approach the tower\n2. Head back to the forest\n> ");
                int choice2;
                scanf("%d", &choice2);
                if (choice2 == 1) {
                    printf("As you approach the tower, you feel a sudden chill down your spine. The closer you get, the more uneasy you feel. Suddenly, you hear a voice in your mind...\n");
                    quick_delay(2);
                    printf("\"You have been chosen.\"\n");
                    quick_delay(2);
                    printf("Without warning, the ground beneath you gives way and you fall into darkness.\n\n");
                }
                else if (choice2 == 2) {
                    printf("Disappointed, you head back to the forest.\n");
                }
            }
        }
        else if (strcmp(direction, "north\n") == 0) {
            printf("The path to the north is shrouded in mist. You can barely see five feet in front of you. Do you\n");
            printf("1. Brave the mist and continue north\n2. Head back\n> ");
            int choice3;
            scanf("%d", &choice3);
            clear_input_buffer();
            if (choice3 == 1) {
                printf("You continue walking through the mist for what feels like an hour. Suddenly, you see a faint blue light in the distance. It's getting brighter…\n");
                quick_delay(2);
                printf("As you get closer, you realize that the light is coming from a small village. You enter the first building you come across, a cozy inn.\n");
                printf("\"Welcome to The Blue Moon Inn!\" the innkeeper greets you. \"I hope you’re here to stay.\"\n");
                quick_delay(2);
                printf("You decide to take him up on his offer and rent a room. As you settle in, you can't help but wonder what other mysteries this strange world holds.\n");
                exit(0); //end the program
            }
            else if (choice3 == 2) {
                printf("You head back to the fork in the road.");
            }
        }
    }
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will be exploring a strange and mystical world. You will be faced with many choices, some of which may lead to your ultimate demise.\n");
    printf("Are you ready to begin? (y/n)\n> ");
    char ready[2];
    fgets(ready, 2, stdin);
    if (strcmp(ready, "y\n") == 0) {
        explore_world();
    }
    else if (strcmp(ready, "n\n") == 0) {
        printf("Goodbye!");
        exit(0); //end the program
    }
}