//FormAI DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char name[50], lover[50];
    int i, j, n, l;

    printf("What is your name?\n");
    scanf("%s", name);

    n = strlen(name);

    printf("Who do you love?\n");
    scanf("%s", lover);

    l = strlen(lover);

    printf("Here's how your love story looks like:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%c", name[j]);
        }

        for (j = i; j < l; j++) {
            printf("%c", lover[j]);
        }

        printf("\n");
    }

    return 0;
}