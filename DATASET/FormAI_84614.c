//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void displayFibonacci(int n) {
    //Seed the first two values
    int first = 0, second = 1;
    int next;

    //Display the first two values
    printf("%d %d ", first, second);

    for (int i = 2; i < n; i++) {
        //Calculate the next value
        next = first + second;

        //Shift the two previous values along one
        first = second;
        second = next;

        //Display the current value
        printf("%d ", next);

        //Pause for a short while to visualize progression
        usleep(500000);
    }
}

void drawTriangle(int n) {
    //Initial coordinates
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        //Move to the start of the row
        printf("\033[%d;%dH", y, x);
        //Display the row of fibonacci numbers
        displayFibonacci(i + 1);

        //Adjust y-coordinate for the next row
        y++;
        //Adjust x-coordinate for the next row
        x += 4;
    }
}

int main() {
    //Clear the screen
    system("clear");

    //Draw the fibonacci triangle with 8 rows
    drawTriangle(8);

    //Move to the bottom of the screen
    printf("\n\n\n\n\n");

    return 0;
}