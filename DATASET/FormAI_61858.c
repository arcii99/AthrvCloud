//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

/* A tragic tale of forbidden image editing */

int main() {
    FILE *fpIn, *fpOut;
    char inName[100], outName[100];
    int c;

    printf("Enter input file name: ");
    scanf("%s", inName);

    fpIn = fopen(inName, "rb");

    if (fpIn == NULL) {
        printf("Error: Could not open file %s\n", inName);
        exit(1);
    }

    printf("Enter output file name: ");
    scanf("%s", outName);

    fpOut = fopen(outName, "wb");

    if (fpOut == NULL) {
        printf("Error: Could not open file %s\n", outName);
        exit(1);
    }

    printf("Do you wish to edit the image? [Y/N]: ");
    getchar();
    c = getchar();

    if (c == 'Y' || c == 'y') {
        printf("Alas, we cannot be seen performing such sacrilege!\n");
        printf("Our love of image editing must forever remain hidden\n");
        printf("We must part ways, and our paths never again cross\n");
        printf("Farewell, my dear friend...\n");
    } else {
        printf("You do not share my love of image editing, it seems\n");
        printf("But I shall always cherish the memories we made together\n");
        printf("Until we meet again, take care\n");
    }

    fclose(fpIn);
    fclose(fpOut);
    return 0;
}