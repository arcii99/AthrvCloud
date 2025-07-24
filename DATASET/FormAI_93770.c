//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Press any key to start...\n");
    getchar();

    int room = 1;
    int hasKey = 0;
    int hasLight = 0;
    int hasPotion = 0;
    int isDead = 0;

    while (!isDead && room <= 10 && !hasKey) {
        switch (room) {
            case 1:
                printf("\nYou are standing in front of the Haunted House. It's dark and eerie.\n");
                printf("Do you want to enter? [y/n] ");
                if (getchar() == 'y') {
                    getchar();
                    printf("You enter the Haunted House.\n");
                    room++;
                } else {
                    getchar();
                    printf("You turn around and go back home.\n");
                    return 0;
                }
                break;
            case 2:
                printf("\nYou are in the Foyer. There are cobwebs everywhere and a musty smell fills the air.\n");
                printf("You see a wooden door to your left and a staircase going up.\n");
                printf("Where do you want to go? [left/up] ");
                if (getchar() == 'l') {
                    getchar();
                    printf("You open the wooden door and enter the Living Room.\n");
                    room++;
                } else {
                    getchar();
                    printf("You climb up the stairs to the second floor.\n");
                    room += 2;
                }
                break;
            case 3:
                printf("\nYou are in the Living Room. The furniture is covered in white sheets.\n");
                printf("You see a key on the coffee table.\n");
                printf("Do you want to take the key? [y/n] ");
                if (getchar() == 'y') {
                    getchar();
                    printf("You take the key.\n");
                    hasKey = 1;
                } else {
                    getchar();
                }
                printf("You leave the Living Room and return to the Foyer.\n");
                room--;
                break;
            case 4:
                printf("\nYou are in the Kitchen. Pots and pans are strewn all over the place.\n");
                if (!hasLight) {
                    printf("It's too dark in here to see anything. You need a flashlight.\n");
                    printf("You leave the Kitchen and return to the Foyer.\n");
                    room--;
                } else {
                    printf("You find a bottle of potion on the counter.\n");
                    printf("Do you want to take the potion? [y/n] ");
                    if (getchar() == 'y') {
                        getchar();
                        printf("You take the potion.\n");
                        hasPotion = 1;
                    } else {
                        getchar();
                    }
                    printf("You leave the Kitchen and return to the Foyer.\n");
                    room--;
                }
                break;
            case 5:
                printf("\nYou are in the Study. The walls are lined with shelves of books.\n");
                printf("You find a flashlight on the desk.\n");
                printf("Do you want to take the flashlight? [y/n] ");
                if (getchar() == 'y') {
                    getchar();
                    printf("You take the flashlight.\n");
                    hasLight = 1;
                } else {
                    getchar();
                }
                printf("You leave the Study and return to the Foyer.\n");
                room--;
                break;
            case 6:
                printf("\nYou are on the second floor landing. There's a door to your left and a door to your right.\n");
                printf("Where do you want to go? [left/right] ");
                if (getchar() == 'l') {
                    getchar();
                    printf("You enter the Bathroom.\n");
                    printf("There's nothing of interest here.\n");
                } else {
                    getchar();
                    printf("You enter the Bedroom.\n");
                    printf("You feel a cold breeze and hear a strange noise coming from the closet.\n");
                    printf("Do you want to open the closet? [y/n] ");
                    if (getchar() == 'y') {
                        getchar();
                        printf("You open the closet and find a Ghost! AHHHHHHHH!!!\n");
                        isDead = 1;
                    } else {
                        getchar();
                    }
                }
                room++;
                break;
            case 7:
                printf("\nYou are in the Master Bedroom. The bed is unmade and there's a chill in the air.\n");
                printf("There's a chest at the foot of the bed.\n");
                if (!hasKey) {
                    printf("It's locked. You need a key to open it.\n");
                } else {
                    printf("You open the chest and find a treasure trove of gold and jewels!\n");
                    printf("Congratulations! You have completed the Haunted House Simulator!\n");
                    return 0;
                }
                printf("You leave the Master Bedroom and return to the second floor landing.\n");
                room--;
                break;
            case 8:
                printf("\nYou are in the Attic. It's dusty and musty up here.\n");
                printf("You don't find anything of interest.\n");
                printf("You leave the Attic and descend back down to the second floor landing.\n");
                room--;
                break;
            case 9:
                printf("\nYou are in the Child's Bedroom. The room is full of toys and stuffed animals.\n");
                printf("You find a note on the bed that reads 'Beware the Ghost of the Haunted House'.\n");
                printf("You leave the Child's Bedroom and go back down to the Foyer.\n");
                room -= 2;
                break;
            case 10:
                printf("\nYou are in the Basement. It's dark and damp down here.\n");
                if (!hasPotion) {
                    printf("You smell something foul in the air. You need a potion to keep from passing out.\n");
                    isDead = 1;
                } else {
                    printf("You drink the potion and are able to explore the basement.\n");
                    printf("You don't find anything of interest.\n");
                }
                break;
            default:
                printf("Error: Room %d does not exist.\n", room);
                return 1;
        }
    }

    if (isDead) {
        printf("You have died a horrible death.\n");
    } else {
        printf("You have completed the Haunted House Simulator!\n");
    }

    return 0;
}