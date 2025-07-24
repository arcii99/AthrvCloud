//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char fileName[50];
    char data[100];
    int i = 0;
    printf("Enter file name: ");
    scanf("%s", fileName); // get the file name

    file = fopen(fileName, "r"); // read the file
    if (file == NULL) { // check if the file exists
        printf("File not found!\n");
        return -1;
    }

    while (!feof(file)) { // read the data
        fscanf(file, "%c", &data[i]);
        i++;
    }
    data[i-1] = '\0'; // add null terminator at the end of the data
    fclose(file); // close the file

    int len = strlen(data);
    int j = 0;
    char newData[len];
    for (i=len-1; i>=0; i--) { // reverse the data
        newData[j] = data[i];
        j++;
    }
    newData[j] = '\0'; // add null terminator at the end of the new data

    char newFileName[50] = "recovered_";
    strcat(newFileName, fileName); // create a new file name
    file = fopen(newFileName, "w"); // write the data to a new file
    if (file == NULL) { // check if the file could be created
        printf("Failed to create new file!\n");
        return -1;
    }
    fprintf(file, "%s", newData); // write the reversed data to the file
    fclose(file); // close the file
    printf("Data has been recovered and saved to file: %s\n", newFileName);

    return 0;
}