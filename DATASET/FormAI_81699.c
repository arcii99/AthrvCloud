//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>

int main() {
    printf("**Welcome to the Data Recovery Tool!**\n\n");
    printf("Let's try to recover some lost data. Please input the name of the file you wish to recover:\n");

    char filename[50];
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Uh oh, it seems like the file %s does not exist or could not be opened. Please try again later.\n", filename);
        return 1;
    }

    printf("Great! We have successfully opened the file %s. Now we will attempt to recover your lost data. Hold tight!\n\n", filename);

    char recoveredData[100];
    int index = 0;
    char currentChar;

    while((currentChar = fgetc(fp)) != EOF) {
        recoveredData[index] = currentChar;
        index++;
    }

    fclose(fp);

    printf("**Congratulations! The data from file %s has been successfully recovered!**\n", filename);
    printf("Here are the contents of the recovered file:\n\n");
    printf("%s", recoveredData);

    return 0;
}