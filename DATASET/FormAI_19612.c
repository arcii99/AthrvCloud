//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 100

int main() {
    char input[MAX_FIELD_LENGTH * MAX_FIELDS];
    char* fields[MAX_FIELDS];
    char* fieldValue;
    char* fieldName;
    int numFields = 0;
    int inputLen;
    int i, j;

    // Prompt the user to enter metadata string
    printf("Please enter a comma-separated metadata string:\n");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if it is present
    inputLen = strlen(input);
    if (input[inputLen - 1] == '\n') {
        input[inputLen - 1] = '\0';
    }

    // Split the string into fields
    fieldValue = strtok(input, ",");
    while (fieldValue != NULL) {
        fields[numFields++] = fieldValue;
        fieldValue = strtok(NULL, ",");
    }

    // Print out the metadata
    printf("\nMETADATA:\n");
    for (i = 0; i < numFields; i++) {
        fieldName = strtok(fields[i], ":");
        printf("%s: ", fieldName);
        fieldValue = strtok(NULL, ":");
        printf("%s\n", fieldValue);
    }

    return 0;
}