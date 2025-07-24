//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    char inputString[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", inputString);

    int arr[10][1000];

    int i, j, k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 1000; j++) {
            arr[i][j] = 0;
        }
    }

    for (i = 0; inputString[i]; i++) {
        int asciiVal = (int) inputString[i];

        for (j = 0; j < 10; j++) {
            for (k = 0; k < 100; k++) {
                if ((asciiVal >> (9 - j)) & 1) {
                    arr[j][100 * i + k] = 1;
                }
            }
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 1000; j++) {
            printf("%c", arr[i][j] ? '@' : '.');
        }
        printf("\n");
    }

    return 0;
}