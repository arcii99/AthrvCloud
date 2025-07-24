//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(char ch, int level);

int main() {
    int level;
    char ch;
    printf("HOLY COW! This is a Fractal Generator program!\n");
    printf("What character do you want to use for your fractal? ");
    scanf("%c", &ch);
    printf("How many levels deep do you want your fractal to be? ");
    scanf("%d", &level);
    printf("Alright, get ready to be amazed...\n");
    fractal(ch, level);
    return 0;
}

void fractal(char ch, int level) {
    if (level <= 0) {
        printf("%c", ch);
    } else {
        fractal(ch, level-1);
        for (int i = 0; i < pow(2, level-1); i++) {
            printf(" ");
        }
        fractal(ch, level-1);
    }
}