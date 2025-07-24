//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int health = 100;
int score = 0;
int compass = 0;
int food = 0;
int water = 0;
int map = 0;

int main() {
    srand(time(0));
    printf("Welcome to Text-Based Adventure Game!\n");
    printf("You are lost in the middle of a jungle and you need to survive to find your way back to civilization.\n");
    printf("You have 100 health and your goal is to find all the necessary items to survive.\n");
    printf("Good luck and be careful!\n\n");

    while (health > 0 && (food == 0 || water == 0 || map == 0)) {
        int option;
        printf("Choose an option:\n");
        printf("1 - Look for food\n");
        printf("2 - Look for water\n");
        printf("3 - Look for a map\n");
        printf("4 - Check health\n");
        printf("5 - Check inventory\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("You found some berries!\n");
                score += 10;
                food++;
                break;

            case 2:
                printf("You found a stream!\n");
                score += 10;
                water++;
                break;

            case 3:
                int chance = rand() % 10;

                if (chance < 4) {
                    printf("You found a map!\n");
                    score += 20;
                    map++;
                } else {
                    printf("You didn't find anything.\n");
                    score -= 5;
                }
                break;

            case 4:
                printf("You have %d health left.\n", health);
                break;

            case 5:
                printf("Compass: %d\n", compass);
                printf("Food: %d\n", food);
                printf("Water: %d\n", water);
                printf("Map: %d\n", map);
                    break;

            default:
                printf("Invalid option.\n");
                break;
        }

        int chance = rand() % 10;

        if (option != 5) {
            switch (chance) {
                case 0:
                    printf("You slipped and lost 10 health!\n");
                    health -= 10;
                    break;

                case 1:
                    printf("You were bitten by a snake and lost 20 health!\n");
                    health -= 20;
                    break;

                case 2:
                    printf("You found a compass!\n");
                    compass++;
                    break;

                default:
                    break;
            }

            if (health <= 0) {
                printf("GAME OVER - You died!\n");
            }
        }
    }

    if (health > 0) {
        printf("Congratulations! You found all the necessary items and you can find your way back to civilization.\n");
        printf("Your final score is %d.\n", score);
    }

    return 0;
}