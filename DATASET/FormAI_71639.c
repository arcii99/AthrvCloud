//FormAI DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[10];
    char output[10];

    printf("Enter the hexadecimal code: ");
    scanf("%s", &input);

    if (strlen(input) != 6) {
        printf("Invalid input. The expected length is 6.");
        return EXIT_FAILURE;
    }

    int r = (input[0] << 4) + input[1];
    int g = (input[2] << 4) + input[3];
    int b = (input[4] << 4) + input[5];

    printf("The RGB values are: %d %d %d\n", r, g, b);

    sprintf(output, "#%02X%02X%02X", r, g, b);

    printf("The new hexadecimal code is: %s", output);

    return EXIT_SUCCESS;
}