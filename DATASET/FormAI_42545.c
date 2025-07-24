//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Happy C File Encryptor Program!\n");
    printf("This program will encrypt any C file of your choice.\n\n");

    char filename[256];
    printf("Please enter the name of the file you would like to encrypt: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file. Please make sure it exists and try again.\n");
        return 1;
    }

    char outputFilename[256];
    printf("Please enter the name of the file you would like to save the encrypted code as: ");
    scanf("%s", outputFilename);

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening file. Please make sure you have write permissions and try again.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        c += 5; // Shift the character by 5 ASCII values
        fputc(c, outputFile); // Write the encrypted character to the output file
    }

    fclose(file);
    fclose(outputFile);

    printf("Encryption complete! The file can be found at %s.\n", outputFilename);
    printf("Thank you for using the Happy C File Encryptor Program!\n");

    return 0;
}