//FormAI DATASET v1.0 Category: Funny ; Style: brave
#include <stdio.h>

int main() {
    printf("Greetings adventurer! You have stumbled upon a program that will test your bravery.\n");
    printf("Are you ready to embark on this quest? (yes/no): ");

    char answer[5];
    scanf("%s", answer);
    
    if (strcmp(answer, "yes") == 0) {
        printf("Brave choice! Let us proceed.\n\n");
        printf("You are in a dark dungeon. There are three doors in front of you - one red, one blue, and one green.\n");
        printf("Which one will you choose? (red/blue/green): ");

        char door[6];
        scanf("%s", door);

        if (strcmp(door, "red") == 0) {
            printf("Good choice! You have found a magic sword that will slay any monster you encounter.\n");
        } else if (strcmp(door, "blue") == 0) {
            printf("Oh no! You have fallen into a pit trap and are now stuck.\n");
            printf("Don't worry, with some bravery and skill, you might be able to climb out.\n");
            int strength = 12;
            int skill = 8;
            int result = (strength + skill) / 2;
            if (result >= 10) {
                printf("Congratulations! You have made it out of the pit and found a magical amulet.\n");
            } else {
                printf("Sorry, you were not brave enough to escape. You are now trapped in the pit forever.\n");
            }
        } else if (strcmp(door, "green") == 0) {
            printf("Great choice! You have stumbled upon a treasure chest filled with gold coins.\n");
        } else {
            printf("Sorry, that is not a valid choice. You must have made a wrong turn somewhere.\n");
        }

    } else {
        printf("Perhaps another time then. Goodbye for now adventurer!\n");
    }

    return 0;
}