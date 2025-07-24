//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>

int main() {
    FILE *dataFile;
    char fileName[50], data[100];

    printf("Enter the name of the data file: ");
    scanf("%s", fileName);

    dataFile = fopen(fileName, "r");

    if (dataFile == NULL) {
        printf("Error opening data file.");
        return 0;
    }

    printf("Successfully opened data file.\n");

    printf("Recovered data:\n");

    while (fgets(data, 100, dataFile)) {
        printf("%s", data);
    }

    fclose(dataFile);

    return 0;
}