//FormAI DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char fname[20], sentence[1000];

    printf("Enter the name of the file to be created: ");
    scanf("%s", fname);

    fptr = fopen(fname, "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter a sentence to write to the file: ");
    getchar();
    fgets(sentence, sizeof(sentence), stdin);

    fprintf(fptr, "%s", sentence);

    fclose(fptr);

    printf("File created and written to successfully.\n");

    fptr = fopen(fname, "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Contents of the file:\n");
    while (fgets(sentence, sizeof(sentence), fptr)) {
        printf("%s", sentence);
    }

    fclose(fptr);

    return 0;
}