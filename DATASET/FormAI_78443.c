//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    char command[100];

    printf("Enter movement commands (w/a/s/d):\n");

    while(1) {
        fgets(command, 100, stdin);

        if(command[0] == 'w') {
            y += 1;
        } else if(command[0] == 'a') {
            x -= 1;
        } else if(command[0] == 's') {
            y -= 1;
        } else if(command[0] == 'd') {
            x += 1;
        } else {
            printf("Invalid command\n");
        }

        printf("Robot is now at (%d, %d)\n", x, y);
    }

    return 0;
}