//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_slow(char* message, int delay) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(delay);
    }
}

void pause_game() {
    char input[10];
    printf("\nPress Enter to continue...\n");
    fgets(input, 10, stdin);
}

int main() {

    char name[30];
    printf("Welcome! What is your name?\n");
    fgets(name, 30, stdin);

    printf("Hello, %s! You are about to embark on an epic adventure.\n", name);
    printf("You find yourself in a mysterious forest. You are not sure how you got here, but you know you need to find your way out.\n");

    pause_game();

    printf("As you continue walking, you come across a fork in the path.\n");
    printf("To the left, you see a narrow, winding path leading uphill.\n");
    printf("To the right, you see a wider, more well-worn path leading downhill.\n");
    printf("Which path do you choose? (left/right)\n");

    char path_choice[10];
    fgets(path_choice, 10, stdin);

    if (strcmp(path_choice, "left\n") == 0) {
        printf("You start walking up the narrow path. The trees overhead form a thick canopy, blocking out most of the light.\n");
        printf("You hear the sounds of birds and small animals all around you.\n");

        pause_game();

        printf("As you round a bend in the path, you come to a clearing in the forest.\n");
        printf("In the center of the clearing, you see a small cottage.\n");
        printf("Do you approach the cottage? (yes/no)\n");

        char approach_cottage[10];
        fgets(approach_cottage, 10, stdin);

        if (strcmp(approach_cottage, "yes\n") == 0) {
            printf("You cautiously approach the cottage. The door is closed, but you can hear a faint humming sound coming from inside.\n");
            printf("Do you knock on the door? (yes/no)\n");

            char knock_cottage[10];
            fgets(knock_cottage, 10, stdin);

            if (strcmp(knock_cottage, "yes\n") == 0) {
                printf("You knock on the door. After a few moments, you hear a voice from inside.\n");
                printf("\"Who's there?\" the voice asks.\n");
                printf("What do you say?\n");

                char cottage_response[50];
                fgets(cottage_response, 50, stdin);

                printf("\"%s\", you respond.\n", cottage_response);
                printf("After a moment of silence, the door creaks open, revealing an old woman with piercing blue eyes.\n");
                printf("\"Hello there, %s,\" she says, beckoning you inside. \"What brings you to my humble abode?\"\n", name);

                pause_game();

                printf("You explain your situation to the old woman. She nods sagely and offers you a cup of tea.\n");
                printf("\"I might be able to help you,\" she says. \"But first, you must solve a riddle.\"\n");
                printf("\"I am taken from a mine, and shut up in a wooden case, from which I am never released, and yet I am used by almost every person. What am I?\"\n");

                char riddle_response[30];
                fgets(riddle_response, 30, stdin);

                if (strcmp(riddle_response, "pencil\n") == 0) {
                    printf("\"Correct!\" the old woman exclaims. \"You have proven yourself worthy of my aid.\"\n");
                    printf("The old woman gives you a map and some provisions for your journey. \"Follow this map,\" she says, \"and it will lead you out of the forest.\"\n");
                    printf("You thank the old woman and set out on your journey once again.\n");
                } else {
                    printf("\"I'm sorry, that is not correct,\" the old woman says. \"You must leave now - I cannot help those who don't listen.\"\n");
                    printf("You thank the old woman and leave the cottage, feeling dejected.\n");
                }
            } else {
                printf("You decide not to knock on the door and continue on your journey.\n");
            }
        } else {
            printf("You decide not to approach the cottage and continue on your journey.\n");
        }

    } else {
        printf("You start walking down the wider path. The sun is shining and the birds are chirping.\n");
        printf("As you walk, you notice a glint of metal in the bushes to your left.\n");
        printf("Do you investigate? (yes/no)\n");

        char investigate_metal[10];
        fgets(investigate_metal, 10, stdin);

        if (strcmp(investigate_metal, "yes\n") == 0) {
            printf("You push aside the bushes and find a shiny sword lying on the ground.\n");
            printf("Do you take the sword? (yes/no)\n");

            char take_sword[10];
            fgets(take_sword, 10, stdin);

            if (strcmp(take_sword, "yes\n") == 0) {
                printf("You take the sword and continue on your journey.\n");
            } else {
                printf("You leave the sword and continue on your journey.\n");
            }
        } else {
            printf("You decide not to investigate and continue on your journey.\n");
        }

        pause_game();

        printf("As you continue walking, you hear the sound of rushing water up ahead.\n");
        printf("When you arrive, you see a beautiful waterfall cascading down from a tall cliff.\n");
        printf("Do you climb the cliff to see where the waterfall is coming from? (yes/no)\n");

        char climb_cliff[10];
        fgets(climb_cliff, 10, stdin);

        if (strcmp(climb_cliff, "yes\n") == 0) {
            printf("You begin your climb up the cliff. It is a difficult climb, but you eventually reach the top.\n");
            printf("There, you find a hidden cave entrance behind the waterfall.\n");
            printf("Do you enter the cave? (yes/no)\n");

            char enter_cave[10];
            fgets(enter_cave, 10, stdin);

            if (strcmp(enter_cave, "yes\n") == 0) {
                printf("You enter the cave with caution. The air inside is damp and musty.\n");
                printf("As you make your way deeper into the cave, you hear the sound of voices up ahead.\n");
                printf("Do you sneak up to listen to what they are saying? (yes/no)\n");

                char sneak_listen[10];
                fgets(sneak_listen, 10, stdin);

                if (strcmp(sneak_listen, "yes\n") == 0) {
                    printf("You creep up to the voices and listen. It sounds like a group of bandits dividing up their loot.\n");
                    printf("You can't help but overhear their plans to attack a nearby village.\n");
                    printf("What do you do?\n");

                    char response_bandits[50];
                    fgets(response_bandits, 50, stdin);

                    printf("\"%s,\" you say.\n", response_bandits);
                    printf("The bandits turn around, startled, and draw their weapons.\n");
                    printf("You are quick on your feet and manage to dodge their attacks.\n");
                    printf("In the end, you emerge victorious and relieve them of their ill-gotten gains.\n");

                    pause_game();

                    printf("You exit the cave and continue on your journey, feeling stronger and wiser.\n");
                } else {
                    printf("You decide not to eavesdrop and continue on your journey.\n");
                }
            } else {
                printf("You decide not to enter the cave and continue on your journey.\n");
            }
        } else {
            printf("You decide not to climb the cliff and continue on your journey.\n");
        }
    }

    printf("Finally, after hours of wandering through the forest, you see a clearing up ahead.\n");
    printf("As you step out of the forest, you see a small town in the distance.\n");
    printf("You have survived your adventure, %s. Congratulations!\n", name);

    return 0;
}