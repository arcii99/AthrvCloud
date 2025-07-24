//FormAI DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[30], data;

    printf("Enter filename to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb"); // open file in read-binary mode

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    printf("\nData recovered from file \"%s\":\n\n", filename);

    while (fread(&data, sizeof(char), 1, fp) != 0) { // read one byte at a time
        printf("%c", data); // print each byte as a character
    }

    fclose(fp); // close file

    return 0;
}