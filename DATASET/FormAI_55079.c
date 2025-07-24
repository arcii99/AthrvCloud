//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: retro
#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, next, i, j;
    printf("Enter the number of terms of Fibonacci sequence you would like to generate: ");
    scanf("%d", &n);
    printf("\033[2J"); // clear screen
    printf("\033[23;1f"); // set text cursor to bottom left corner of screen
    printf("Fibonacci Sequence (in retro style):\n\n");
    printf("\033[%d;%df", 4, 1); // set text cursor to row 4, column 1
    for (i = 1; i <= n; i++) {
        printf("%d,", first);
        next = first + second;
        first = second;
        second = next;
        if (i % 20 == 0) {
            printf("\033[%d;%df", i/20+4, 1); // set text cursor to next row
        }
    }
    printf("\033[%d;%df...\n", n/20+4, 1); // indicate continuation
    printf("\033[%d;%df[Press ENTER to exit]", n/20+5, 1); // set text cursor to next row
    getchar(); // wait for user to press enter
    return 0;
}