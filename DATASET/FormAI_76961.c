//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("input.html", "r");
    while ((c = getc(fp)) != EOF) {
        if (c == '<') {
            putchar(c);
            while ((c = getc(fp)) != '>') {
                putchar(c);
            }
            putchar(c);
        } else {
            putchar(c);
        }
    }
    fclose(fp);
    return 0;
}