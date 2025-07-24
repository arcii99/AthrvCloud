//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>

int main() {

    // Open file in write mode
    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Write contents to file
    fprintf(fp, "Hello World!");

    // Close file
    fclose(fp);

    // Open file in read mode
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read contents from file and print to console
    char buf[255];
    while (fgets(buf, 255, fp)) {
        printf("%s", buf);
    }

    // Close file
    fclose(fp);

    return 0;
}