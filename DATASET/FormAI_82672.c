//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a dark and eerie mansion...\n");
    printf("Do you want to start exploring? (Y/N): ");

    char choice = getchar(); // get user's choice

    if (choice == 'Y' || choice == 'y') {

        printf("\nAs you enter the first room, you hear a loud creaking sound...\n");
        printf("The door suddenly slams shut behind you!\n");

        int randomNum = rand() % 3; // generate a random number between 0-2
        if (randomNum == 0) {

            printf("You try to open the door, but it won't budge.\n");
            printf("Suddenly, you feel a cold breath on your neck...\n");
            printf("Game Over!");

        } else if (randomNum == 1) {

            printf("You find a key on the floor. You use it to unlock the door.\n");
            printf("Congratulations! You have completed the first room.\n");
            printf("\nAs you enter the second room, you notice a painting on the wall...\n");
            printf("But when you look closer, the eyes of the painting start following you!\n");

            randomNum = rand() % 3; // generate a new random number
            if (randomNum == 0) {

                printf("You try to ignore the painting, but you feel like it's watching you.\n");
                printf("You feel a strong wind blowing from the painting...\n");
                printf("Game Over!");

            } else if (randomNum == 1) {

                printf("You take a closer look at the painting, and notice a secret passage behind it!\n");
                printf("Congratulations! You have completed the second room.\n");
                printf("\nAs you enter the third room, you hear strange whispers...\n");
                printf("You turn around, but no one's there.\n");

                randomNum = rand() % 3; // generate another random number
                if (randomNum == 0) {

                    printf("The whispers get louder, and you feel like something is grabbing your ankles...\n");
                    printf("Game Over!");

                } else if (randomNum == 1) {

                    printf("You follow the whispers, and find a secret door.\n");
                    printf("You open it, and see a staircase leading down...\n");
                    printf("Congratulations! You have completed the third room.\n");
                    printf("\nYou descend the staircase, and find yourself in the basement...\n");
                    printf("As you explore the darkness, you hear something moving...\n");

                    randomNum = rand() % 3; // generate yet another random number
                    if (randomNum == 0) {

                        printf("You feel something cold and slimy touch your face...\n");
                        printf("Game Over!");

                    } else if (randomNum == 1) {

                        printf("You find a flashlight, and turn it on.\n");
                        printf("You see a door at the end of the basement, and head towards it.\n");
                        printf("Congratulations! You have completed the basement.\n");
                        printf("\nAs you open the door, you step outside...\n");
                        printf("The sun is shining, and the birds are singing!\n");
                        printf("You did it! You survived the Haunted House Simulator!\n");

                    } else {

                        printf("You hear a growling sound...\n");
                        printf("You realize too late that it's a monster!\n");
                        printf("Game Over!");

                    }

                } else {

                    printf("The whispers guide you to a chest in the corner of the room.\n");
                    printf("You find a map, which leads you to the exit!\n");
                    printf("Congratulations! You have completed the third room.\n");
                    printf("\nYou follow the map, and find the way out.\n");
                    printf("As you step outside, you breathe a sigh of relief.\n");
                    printf("You did it! You survived the Haunted House Simulator!\n");

                }

            } else {

                printf("You try to run away from the painting, but it follows you...\n");
                printf("You feel like you're going insane...\n");
                printf("Game Over!");

            }

        } else {

            printf("You find a book on the table. You flip through the pages, and find a spell.\n");
            printf("You recite the spell, and the door opens.\n");
            printf("Congratulations! You have completed the first room.\n");
            printf("\nAs you enter the second room, you see an old grandfather clock...\n");
            printf("The clock starts ticking faster and faster...\n");

            randomNum = rand() % 3; // generate a new random number
            if (randomNum == 0) {

                printf("The clock strikes twelve, and the doors of the room start closing in...\n");
                printf("Game Over!");

            } else if (randomNum == 1) {

                printf("You notice a keyhole on the back of the clock. You use the key you found earlier to unlock it.\n");
                printf("The clock stops ticking, and a secret passage is revealed!\n");
                printf("Congratulations! You have completed the second room.\n");
                printf("\nAs you enter the third room, you feel a cold breeze...\n");
                printf("You see a ghostly figure in the corner of the room...\n");

                randomNum = rand() % 3; // generate another random number
                if (randomNum == 0) {

                    printf("The ghostly figure starts floating towards you...\n");
                    printf("Game Over!");

                } else if (randomNum == 1) {

                    printf("You summon your courage, and try to communicate with the ghostly figure.\n");
                    printf("To your surprise, it tells you the way out!\n");
                    printf("Congratulations! You have completed the third room.\n");
                    printf("\nYou follow the ghost's instructions, and find the way out.\n");
                    printf("As you step outside, you breathe a sigh of relief.\n");
                    printf("You did it! You survived the Haunted House Simulator!\n");

                } else {

                    printf("You try to run away from the ghostly figure, but it blocks your path...\n");
                    printf("You feel something cold and slimy touch your face...\n");
                    printf("Game Over!");

                }

            } else {

                printf("You hide behind the clock, and wait for the ticking to stop...\n");
                printf("When it does, you find a key which opens the door to the next room.\n");
                printf("Congratulations! You have completed the second room.\n");
                printf("\nAs you enter the third room, you find yourself in a maze...\n");
                printf("You have to find the way out before the walls close in!\n");

                // simulate maze
                int maze[5][5] = {
                    {1, 1, 1, 0, 1},
                    {0, 0, 1, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 1, 1},
                    {1, 1, 1, 1, 1}
                };

                int x = 0, y = 0;
                while (x != 4 || y != 4) {
                    printf("You are at (%d, %d)\n", x, y);
                    printf("Enter 'N', 'S', 'E', or 'W' to move: ");

                    char move = getchar();
                    getchar(); // discard newline character

                    if (move == 'N' || move == 'n') {
                        if (x > 0 && maze[x-1][y] == 1) x--;
                    } else if (move == 'S' || move == 's') {
                        if (x < 4 && maze[x+1][y] == 1) x++;
                    } else if (move == 'E' || move == 'e') {
                        if (y < 4 && maze[x][y+1] == 1) y++;
                    } else if (move == 'W' || move == 'w') {
                        if (y > 0 && maze[x][y-1] == 1) y--;
                    }

                    if (x == 4 && y == 4) {
                        printf("Congratulations! You have completed the third room.\n");
                        printf("\nYou find the way out of the maze, and step outside.\n");
                        printf("As you breathe the fresh air, you feel alive!\n");
                        printf("You did it! You survived the Haunted House Simulator!\n");
                        break; // end game
                    }
                }
            }
        }

    } else if (choice == 'N' || choice == 'n') {

        printf("Goodbye!\n");

    } else {

        printf("Invalid choice. Goodbye!\n");

    }

    return 0;
}