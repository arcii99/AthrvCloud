//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for usleep()
#include <time.h>

#define FIB_MAX 20 // maximum Fibonacci number to generate
#define DELAY 100000 // delay between printing each number, in microseconds

int main() {
    int fib1 = 0, fib2 = 1, temp; // initialize three variables for Fibonacci sequence
    int count = 0; // initialize variable to count number of times loop has run
    int row, col; // initialize variables for row and column of console output

    printf("\x1b[2J"); // clear console
    printf("\x1b[?25l"); // hide cursor

    // loop through Fibonacci sequence up to FIB_MAX
    while (count < FIB_MAX) {
        // calculate next Fibonacci number and assign it to temp variable
        temp = fib2;
        fib2 += fib1;
        fib1 = temp;

        // print Fibonacci number to console in Cyberpunk style
        printf("\x1b[38;2;%d;%d;%dm", rand() % 256, rand() % 256, rand() % 256); // set text color to random RGB value
        printf("\x1b[%d;0f", rand() % 24 + 1); // move cursor to random row
        printf("%d%c", fib2, rand() % 2 == 0 ? '|' : '+'); // print number and either '|' or '+'
        fflush(stdout); // flush output buffer

        // wait for DELAY microseconds before printing next number
        usleep(DELAY);

        // increment count variable
        count++;
    }

    printf("\x1b[0m"); // reset text color to default
    printf("\x1b[24;0f"); // move cursor to bottom row
    printf("Press any key to exit\n");

    // wait for user input before exiting program
    getchar();

    printf("\x1b[2J"); // clear console
    printf("\x1b[?25h"); // show cursor

    return 0;
}