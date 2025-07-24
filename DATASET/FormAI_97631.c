//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8
#define COLS 80
#define MAX_STR_LEN 256

void print_ascii_art(char str[MAX_STR_LEN]);

int main()
{
    char str[MAX_STR_LEN];
    printf("Enter text to convert to ASCII art:");
    fgets(str, MAX_STR_LEN, stdin);
    print_ascii_art(str);

    return 0;
}

void print_ascii_art(char str[MAX_STR_LEN])
{
    int i, j, k = 0;
    int len = strlen(str);
    int* ascii_code = (int*) malloc(len * sizeof(int));

    for (i = 0; i < len - 1; i++)   // exclude the newline character
        ascii_code[i] = (int) str[i];

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (k >= len - 1) {     // exclude the newline character
                printf("\n");      // end of input string
                free(ascii_code);   // release allocated memory
                return;
            }
            printf("%c", ascii_code[k++]);
        }
        printf("\n");
    }
}