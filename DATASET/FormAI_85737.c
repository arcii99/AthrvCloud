//FormAI DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[8];
    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color code in the format 'RRGGBB':\n");

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) != 6 || !isValidHex(input)) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    char r[3], g[3], b[3];

    strncpy(r, input, 2);
    r[2] = '\0';

    strncpy(g, input + 2, 2);
    g[2] = '\0';

    strncpy(b, input + 4, 2);
    b[2] = '\0';

    int red = strtol(r, NULL, 16);
    int green = strtol(g, NULL, 16);
    int blue = strtol(b, NULL, 16);

    printf("The RGB code for #%s is (%d, %d, %d).", input, red, green, blue);

    return 0;
}

int isValidHex(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f'))) {
            return 0;
        }
    }
    return 1;
}