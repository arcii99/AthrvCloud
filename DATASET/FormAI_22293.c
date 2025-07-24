//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>

int main() {
    int catspeak = 0;
    char c;
    printf("Enter a sentence in C Cat Language (using only 'meow', 'purr', and 'hiss'):\n");
    while ((c = getchar()) != EOF) {
        if (c == 'm') {
            if (getchar() == 'e' && getchar() == 'o' && getchar() == 'w') {
                putchar('m');
                putchar('a');
                putchar('n');
                putchar(' ');
                catspeak++;
            }
        } else if (c == 'p') {
            if (getchar() == 'u' && getchar() == 'r' && getchar() == 'r') {
                putchar('c');
                putchar('o');
                putchar('d');
                putchar('e');
                catspeak++;
            }
        } else if (c == 'h') {
            if (getchar() == 'i' && getchar() == 's' && getchar() == 's') {
                putchar('d');
                putchar('e');
                putchar('b');
                putchar('u');
                putchar('g');
                catspeak++;
            }
        }
    }
    if (catspeak == 0) {
        printf("Sorry, no C Cat Language detected.\n");
    }
    return 0;
}