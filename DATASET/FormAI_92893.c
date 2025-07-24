//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int i, count;

    // set up seed for random number generator
    srand((unsigned)time(NULL));

    // generate and print 10 random numbers between 1 and 100
    printf("Generating 10 random numbers between %d and %d:\n\n", MIN_VALUE, MAX_VALUE);
    for (i = 0; i < 10; i++) {
        int num = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        printf("%d\n", num);
    }

    // generate a random string of alphabet letters
    count = 5;
    printf("\nGenerating a random string of %d alphabet letters:\n\n", count);
    for (i = 0; i < count; i++) {
        char letter = rand() % 26 + 'a';
        printf("%c", letter);
    }

    // generate a random password consisting of alphabet letters and digits
    count = 8;
    printf("\n\nGenerating a random password of %d characters:\n\n", count);
    for (i = 0; i < count; i++) {
        int type = rand() % 2;
        char ch;
        if (type == 0) {  // generate a random digit
            ch = rand() % 10 + '0';
        } else {  // generate a random alphabet letter
            ch = rand() % 26 + 'a';
        }
        printf("%c", ch);
    }

    return 0;
}