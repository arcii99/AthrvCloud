//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

// function to write data to a file
void writeToFile(char *filename) {
    // open file for writing
    FILE *fp;
    fp = fopen(filename, "w");

    // write data to file
    fprintf(fp, "Hello world!\n");
    fprintf(fp, "This is a cheerful file handling example program.\n");
    fprintf(fp, "We are having so much fun!\n");

    // close file
    fclose(fp);
}

// function to read data from a file
void readFromFile(char *filename) {
    // open file for reading
    FILE *fp;
    fp = fopen(filename, "r");

    // read data from file
    char ch = fgetc(fp);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }

    // close file
    fclose(fp);
}

// main function
int main() {
    char *filename = "example.txt";

    // write data to file
    writeToFile(filename);

    // read data from file
    readFromFile(filename);

    return 0;
}