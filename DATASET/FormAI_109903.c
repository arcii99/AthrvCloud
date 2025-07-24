//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>

int main() {
    char c;
    int smileyCount = 0;

    printf("Enter some text containing smiley faces!\n");
    while ((c = getchar()) != EOF) {
        if (c == ':') { // potential smiley face
            c = getchar();
            if (c == ')') {
                smileyCount++;
            } else {
                while (c != ' ' && c != '\n') {
                    c = getchar();
                }
            }
        }
    }

    printf("You found %d smiley faces! Keep on smiling :)\n", smileyCount);

    return 0;
}