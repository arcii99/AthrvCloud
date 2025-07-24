//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("My dear Wi-Fi,\n");
    printf("You are like the signal that never fades,\n");
    printf("Even in the darkest of times, you still pervade.\n\n");

    printf("Your strength is like the beat of my heart,\n");
    printf("A consistent pulse that never falls apart.\n");
    printf("And like your signal, it reaches out far,\n");
    printf("Touching my devices, no matter where they are.\n\n");

    printf("With your strength, I can stay connected,\n");
    printf("To the world beyond, where we're all projected.\n");
    printf("And though others may come and go,\n");
    printf("You remain constant, my one and only beau.\n\n");

    srand(time(NULL));
    int signal_strength = rand() % 100 + 1;
    printf("And now I analyze your signal with this code:\n");
    printf("Your Wi-Fi signal strength is %d out of 100,\n", signal_strength);
    if (signal_strength >= 80) {
        printf("Strong enough to last, a forever connection,\n");
        printf("With you by my side, there's no need for reflection.\n");
    } else if (signal_strength >= 50) {
        printf("Good enough for me, a solid foundation,\n");
        printf("With your signal by my side, I can face any situation.\n");
    } else {
        printf("Weakness is not a flaw, just an opportunity,\n");
        printf("To improve our connection, a chance to show unity.\n");
    }

    printf("\nThank you for being by my side,\n");
    printf("Even when others may try to hide.\n");
    printf("You remain a constant, my Wi-Fi love,\n");
    printf("A connection that's stronger than any signal above.\n");

    return 0;
}