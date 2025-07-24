//FormAI DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int colorCodeConverter(char color[], int numVals[]) {
    int r, g, b;
    if (sscanf(color, "#%02x%02x%02x", &r, &g, &b) == 3) {
        numVals[0] = r;
        numVals[1] = g;
        numVals[2] = b;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char color[10];
    int numVals[3];

    printf("Enter a hex color code: ");
    scanf("%s", color);

    if (colorCodeConverter(color, numVals)) {
        printf("The decimal values for the color %s are: %d, %d, %d\n", color, numVals[0], numVals[1], numVals[2]);
    } else {
        printf("Invalid color code entered.");
        return -1;
    }

    return 0;
}