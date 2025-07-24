//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int result = 0;

    printf("Let's do some arithmetic!\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    result = x + y;
    printf("x + y = %d\n", result);

    if (result > 15) {
        printf("Wow, that's a big number!\n");
        printf("We're really crunching those bits now!\n");
    } else if (result < 10) {
        printf("Oops, that's a little small...\n");
        printf("Better take off those training wheels, buddy!\n");
    } else {
        printf("Eh, it's not bad. Could be better though.\n");
        printf("Time to hit the books and learn some more math!\n");
    }

    result = x - y;
    printf("x - y = %d\n", result);

    if (result == 5) {
        printf("Hey, look at that! Our math is working!\n");
    } else {
        printf("Well, that's not quite right...\n");
        printf("Looks like we'll have to double-check our work!\n");
    }

    result = x * y;
    printf("x * y = %d\n", result);

    if (result % 2 == 0) {
        printf("Wow, that's an even number!\n");
        printf("We're really rocking this arithmetic thing!\n");
    } else {
        printf("Well, that's an odd number...\n");
        printf("But hey, nobody's perfect!\n");
    }

    result = x / y;
    printf("x / y = %d\n", result);

    if (result == 2) {
        printf("Nice job, buddy!\n");
        printf("You must have been studying hard!\n");
    } else {
        printf("Hmm, that's not quite right...\n");
        printf("Looks like we'll have to hit the books again!\n");
    }

    return 0;
}