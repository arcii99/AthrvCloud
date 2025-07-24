//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator

    printf("Welcome to The Adventure!\n");
    printf("To start, please choose a character name: ");
    char name[20];
    fgets(name, 20, stdin);

    printf("\n%s, your adventure starts here.\n", name);
    printf("You find yourself in a dark forest. The trees are towering above you, blocking out all sunlight. The ground is damp and cold under your feet. You have no idea how you got here, or where you should go.\n");

    while (1) {
        printf("\nWhat would you like to do?:\n");
        printf("1. Search the area\n");
        printf("2. Follow a path\n");
        printf("3. Climb a tree\n");
        printf("4. Exit the game\n");

        char choice[2];
        fgets(choice, 2, stdin);

        switch (choice[0]) {
            case '1':
                printf("\nYou start searching the area. After a while, you find a small clearing. In the middle of the clearing, there is an old chest. What do you want to do?:\n");
                printf("1. Open the chest\n");
                printf("2. Ignore the chest\n");

                char chest[2];
                fgets(chest, 2, stdin);

                if (chest[0] == '1') {
                    printf("\nYou try to open the chest, but it is locked. You need a key to unlock it. What do you want to do?:\n");
                    printf("1. Look for a key\n");
                    printf("2. Ignore the chest\n");

                    char key[2];
                    fgets(key, 2, stdin);

                    if (key[0] == '1') {
                        int chance = rand() % 10 + 1; // generate a random number between 1 and 10

                        if (chance >= 3) {
                            printf("\nYou search the area and find a key under a rock. You use it to unlock the chest. Inside, you find a map that shows the way out of the forest! You win the game!\n");
                            return 0;
                        } else {
                            printf("\nYou search the area, but you cannot find a key. You give up and continue your adventure.\n");
                        }
                    }
                }

                break;

            case '2':
                printf("\nYou start following a path, hoping that it will lead you out of the forest. After a while, you see a river blocking your way. What do you want to do?:\n");
                printf("1. Swim across the river\n");
                printf("2. Look for a bridge\n");

                char river[2];
                fgets(river, 2, stdin);

                if (river[0] == '1') {
                    int chance = rand() % 10 + 1;

                    if (chance >= 5) {
                        printf("\nYou start swimming across the river. It is tough, but you manage to reach the other side. You feel exhausted, but you also feel a sense of accomplishment.\n");
                    } else {
                        printf("\nYou start swimming across the river. However, the current is too strong, and you get swept away. You end up further downstream, but at least you are still alive.\n");
                    }
                } else {
                    printf("\nYou start looking for a bridge. After a while, you find one that leads across the river. You cross it safely.\n");
                }

                break;

            case '3':
                printf("\nYou decide to climb a tree, hoping to get a better view of the forest. After a while, you reach the treetop. You can see for miles in all directions. Suddenly, you see something moving in the distance. What do you want to do?:\n");
                printf("1. Climb down and investigate\n");
                printf("2. Stay in the tree and observe from a distance\n");

                char moving[2];
                fgets(moving, 2, stdin);

                if (moving[0] == '1') {
                    printf("\nYou climb down the tree and start walking towards the moving object. After a while, you see that it is a pack of wolves. They look hungry, and they smell your presence. What do you want to do?:\n");
                    printf("1. Run away\n");
                    printf("2. Climb another tree\n");
                    printf("3. Fight the wolves\n");

                    char wolves[2];
                    fgets(wolves, 2, stdin);

                    if (wolves[0] == '1') {
                        printf("\nYou start running as fast as you can, but the wolves are too quick. They catch up to you, and you become their meal.\n");
                        printf("Game over!\n");
                        return 0;
                    } else if (wolves[0] == '2') {
                        printf("\nYou climb up another tree, but the wolves follow you. They start circling the tree, waiting for you to come down. You cannot stay up there forever.\n");
                    } else {
                        printf("\nYou start fighting the wolves. It is a tough battle, but you manage to defeat them all. You feel proud of yourself and continue your adventure.\n");
                    }
                } else {
                    printf("\nYou stay in the tree and observe the moving object from a distance. After a while, you see that it is a group of travelers. They look friendly, and they have a map that shows the way out of the forest. You climb down the tree and follow them.\n");
                    printf("You exit the forest and win the game!\n");
                    return 0;
                }

                break;

            case '4':
                printf("\nAre you sure you want to exit the game?:\n");
                printf("1. Yes\n");
                printf("2. No\n");

                char exit[2];
                fgets(exit, 2, stdin);

                if (exit[0] == '1') {
                    printf("\nThank you for playing The Adventure! Goodbye!\n");
                    return 0;
                }

                break;

            default:
                printf("\nInvalid option! Please choose again.\n");

                break;
        }
    }
}