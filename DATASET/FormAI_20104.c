//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    // open file in write mode
    fp = fopen("brave_file_handling.txt", "w+");

    // write some content to the file
    fputs("This is a brave example of file handling in C!\n", fp);
    fputs("I am not sorry for being creative!\n", fp);
    fputs("Let's read from the file now...\n", fp);

    // move file cursor to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // read from the file and print to console
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        printf("%s", buffer);
    }

    // close the file
    fclose(fp);

    return 0;
}