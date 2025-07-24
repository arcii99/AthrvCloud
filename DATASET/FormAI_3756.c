//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    printf("Welcome to the Adventure Game!\n\n");

    char choice[MAX_INPUT_LENGTH];
    int done = 0;

    while (!done) {

        printf("You're in a dark room with three doors. Which one do you choose? (1/2/3)\n\n");

        fgets(choice, MAX_INPUT_LENGTH, stdin);
        clear_input_buffer();

        if (strcmp(choice, "1\n") == 0) {

            printf("\nYou enter the first door and find yourself in a small room. There's a table in the middle with a book on top of it.\nDo you want to read the book? (y/n)\n\n");

            fgets(choice, MAX_INPUT_LENGTH, stdin);
            clear_input_buffer();

            if (strcmp(choice, "y\n") == 0) {
                printf("\nYou open the book and read the first page. Suddenly, the room starts to shake and the walls crumble down.\nYou fall into a pit and die. Game over.\n");
                done = 1;
            } else {
                printf("\nYou leave the book on the table and head back to the door. You try to open it, but it's locked from the outside. You die of starvation. Game over.\n");
                done = 1;
            }

        } else if (strcmp(choice, "2\n") == 0) {

            printf("\nYou enter the second door and find yourself in a hallway. There are two doors on your left and right. Which one do you choose? (l/r)\n\n");

            fgets(choice, MAX_INPUT_LENGTH, stdin);
            clear_input_buffer();

            if (strcmp(choice, "l\n") == 0) {
                printf("\nYou enter the door on the left and find yourself in a treasure room. There's a chest in the corner.\nDo you want to open it? (y/n)\n\n");

                fgets(choice, MAX_INPUT_LENGTH, stdin);
                clear_input_buffer();

                if (strcmp(choice, "y\n") == 0) {
                    printf("\nYou open the chest and find a pile of gold. Congratulations, you win!\n");
                    done = 1;
                } else {
                    printf("\nYou leave the chest untouched and head back to the hallway. You try to go back to the door you came from, but it's locked. You die of dehydration. Game over.\n");
                    done = 1;
                }

            } else if (strcmp(choice, "r\n") == 0) {
                printf("\nYou enter the door on the right and find yourself in a maze. You try to find your way out, but you get lost and die. Game over.\n");
                done = 1;

            } else {
                printf("\nYou choose an non-existing room and die. Game over.\n");
                done = 1;
            }

        } else if (strcmp(choice, "3\n") == 0) {
            printf("\nYou enter the third door and find yourself in a dark tunnel. There's a light at the end, do you want to approach? (y/n)\n\n");

            fgets(choice, MAX_INPUT_LENGTH, stdin);
            clear_input_buffer();

            if (strcmp(choice, "y\n") == 0) {
                printf("\nYou follow the light and find yourself outside. You made it, congratulations!\n");
                done = 1;

            } else {
                printf("\nYou stay in the dark tunnel, but you get attacked by a monster and die. Game over.\n");
                done = 1;
            }

        } else {
            printf("\nPlease choose a valid door.\n\n");
        }
    }

    return 0;
}