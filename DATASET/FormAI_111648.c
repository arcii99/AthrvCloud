//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include<stdio.h>

#define MAX_FLOOR 9

int main() {
    int floor = 0, dir = 1; // dir 1 for up, -1 for down, 0 for stopped
    int people = 0;
    int delay = 1000;
    printf("\nRetro Elevator Simulation\n\n");
    printf("Up Arrow: Go Up\n");
    printf("Down Arrow: Go Down\n");
    printf("Space Bar: Stop\n");
    printf("Escape: Exit\n\n");
    while(1) {
        char c = getchar();
        if(c == 27) { // Exit on Escape
            break;
        } else if(c == ' ') {
            dir = 0; // Stop on Space
        } else if(c == '\n' || c == '\r') {
            continue; // Skip line breaks
        } else {
            if(c == '+') {
                people++;
                printf("Added 1 person to elevator. Elevator now has %d people.\n", people);
            } else if(c == '-') {
                if(people > 0) {
                    people--;
                    printf("Removed 1 person from elevator. Elevator now has %d people.\n", people);
                } else {
                    printf("Elevator is already empty!\n");
                }
            } else if(c == '[') {
                delay += 100; // Slow Down
                printf("Delay now set to %dms.\n", delay);
            } else if(c == ']') {
                delay -= 100; // Speed Up
                if(delay < 0) {
                    delay = 0;
                }
                printf("Delay now set to %dms.\n", delay);
            } else if(c == '.') {
                dir = 1; // Go Up
                printf("Elevator is now going up!\n");
            } else if(c == ',') {
                dir = -1; // Go Down
                printf("Elevator is now going down!\n");
            } else {
                printf("Invalid Key!\n");
                continue;
            }
            if(floor + dir >= 0 && floor + dir <= MAX_FLOOR) {
                floor += dir;
            } else {
                printf("Elevator cannot go any further!\n");
            }
        }
        printf("Current floor: %d, People: %d\n", floor, people);
        for(int i = 0; i <= MAX_FLOOR; i++) {
            if(i == floor) {
                printf("|\tE\t|");
            } else if(i == 0) {
                printf("|\tG\t|");
            } else if(i == MAX_FLOOR) {
                printf("|\t%d\t|", i);
            } else {
                printf("|\t \t|");
            }
            if(dir == 1 && i == floor) {
                printf(" /\n");
            } else if(dir == -1 && i == floor) {
                printf(" \\\n");
            } else {
                printf("\n");
            }
        }
        printf("\n");
        fflush(stdout);
        usleep(delay * 1000);
    }
    printf("\nExiting Elevator Simulation!\n");
    return 0;
}