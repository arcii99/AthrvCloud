//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>

void travel(int x, int y);

int x = 0; // current x coordinate
int y = 0; // current y coordinate

int main() {
    printf("Welcome to the Space Adventure!\n");
    printf("You find yourself on the planet Earth. Where do you want to go now? (Type 1 or 2)\n");
    printf("1. Board the spaceship and explore new galaxies.\n");
    printf("2. Stay on Earth and continue your boring life.\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You board the spaceship and feel the thrill of excitement.\n");
        printf("The ship takes off and you accelerate towards the vast unknown.\n");

        travel(10, 20);

        printf("You have reached your destination!\n");
        printf("You step out of the ship and realize that you are on a strange planet.\n");
        printf("The sky is red and the air is thick. You take a deep breath and explore your surroundings.\n");

        // more adventure code here...
    }
    else {
        printf("You decide to stay on Earth and continue your boring life.\n");
        printf("You spend the rest of your days regretting your decision and longing for adventure.\n");
    }

    return 0;
}

void travel(int x_dest, int y_dest) {
    int x_diff = x_dest - x;
    int y_diff = y_dest - y;

    if (x_diff != 0) {
        printf("You navigate the ship to the left or right, avoiding any obstacles in your way.\n");
        x += x_diff;
    }
    if (y_diff != 0) {
        printf("You adjust the ship's trajectory to go up or down, using the ship's advanced sensors to detect any danger.\n");
        y += y_diff;
    }
}