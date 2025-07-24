//FormAI DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>

int main() {
    // file pointers
    FILE *file1, *file2, *file3;

    // open first file
    file1 = fopen("file1.txt", "w");
    if(file1 == NULL) {
        printf("Error opening file1!\n");
        return 1;
    }

    // write to file1
    fprintf(file1, "Hello world\n");
    fprintf(file1, "This is example program\n");
    fprintf(file1, "For demonstrating file handling in C programming\n");

    // close file1
    fclose(file1);

    // open second file
    file2 = fopen("file2.txt", "w");
    if(file2 == NULL) {
        printf("Error opening file2!\n");
        return 1;
    }

    // write to file2
    fprintf(file2, "This is the second file\n");
    fprintf(file2, "It is being written from the same program\n");

    // close file2
    fclose(file2);

    // open third file
    file3 = fopen("file3.txt", "w");
    if(file3 == NULL) {
        printf("Error opening file3!\n");
        return 1;
    }

    // write to file3
    fprintf(file3, "This is the third file\n");
    fprintf(file3, "It is also being written from the same program\n");

    // close file3
    fclose(file3);

    // open first file again to read contents
    file1 = fopen("file1.txt", "r");
    if(file1 == NULL) {
        printf("Error opening file1!\n");
        return 1;
    }

    // read contents of file1 and print to screen
    printf("Contents of file1:\n");
    char ch;
    while((ch = fgetc(file1)) != EOF) {
        printf("%c", ch);
    }

    // close file1
    fclose(file1);

    // open second file again to read contents
    file2 = fopen("file2.txt", "r");
    if(file2 == NULL) {
        printf("Error opening file2!\n");
        return 1;
    }

    // read contents of file2 and print to screen
    printf("Contents of file2:\n");
    while((ch = fgetc(file2)) != EOF) {
        printf("%c", ch);
    }

    // close file2
    fclose(file2);

    // open third file again to read contents
    file3 = fopen("file3.txt", "r");
    if(file3 == NULL) {
        printf("Error opening file3!\n");
        return 1;
    }

    // read contents of file3 and print to screen
    printf("Contents of file3:\n");
    while((ch = fgetc(file3)) != EOF) {
        printf("%c", ch);
    }

    // close file3
    fclose(file3);

    return 0;
}