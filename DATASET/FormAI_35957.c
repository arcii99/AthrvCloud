//FormAI DATASET v1.0 Category: Data validation ; Style: bold
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[50], valid[50];
    int i, j = 0;
    int validInt;
    float validFloat;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            valid[j] = input[i];
            j++;
        } else if (input[i] == '.') {
            valid[j] = input[i];
            j++;
        } else if (input[i] == ' ') {
            continue;
        } else {
            printf("Invalid input! Only digits and a period (.) are allowed.\n");
            return 0;
        }
    }
    valid[j] = '\0';

    if (sscanf(valid, "%d", &validInt) == 1) {
        printf("Valid integer: %d\n", validInt);
    } else if (sscanf(valid, "%f", &validFloat) == 1) {
        printf("Valid float: %f\n", validFloat);
    } else {
        printf("Invalid input! Only digits and a period (.) are allowed.\n");
    }

    return 0;
}