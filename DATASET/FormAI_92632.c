//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int a = 0, b = 1, c, i, n;
    int x = 50; // number of rows to print

    printf("\033[2J\033[1;1H");  // clear terminal screen
    // print Fibonacci sequence
    printf("Fibonacci Sequence for %d rows:\n", x);
    for (i = 0; i < x; i++) {
        printf("%d,", a);
        c = a + b;
        a = b;
        b = c;
    }

    // clear terminal screen and print visualization
    printf("\033[2J\033[1;1H");
    printf("Visualizing Fibonacci Sequence for %d rows:\n", x);
    for (i = 0; i < x; i++) {
        printf("\033[38;2;%d;%d;%dm", 255, 51+i*2, 153-i*2); // set color gradient
        printf("."); // print dot
        fflush(stdout); // flush buffer to display dots as they are printed
        usleep(40000); // wait for 0.04 seconds between each dot
    }
    printf("\033[0m\n"); // reset color

    return 0;
}