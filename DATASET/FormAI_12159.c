//FormAI DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char input[10];
    int num;

    printf("\n\033[1;31mEnter a hexadecimal color code: #");
    scanf("%s", input);

    if (strlen(input) != 6) {
        printf("\n\033[1;33mInvalid input! Please enter a valid 6 digit hexadecimal color code.\n");
        return 0;
    }

    num = (int) strtol(input, NULL, 16);

    printf("\n\033[1;34mRed component: %d", (num >> 16) & 0xFF);
    printf("\n\033[1;32mGreen component: %d", (num >> 8) & 0xFF);
    printf("\n\033[1;35mBlue component: %d\n", num & 0xFF);

    return 0;
}