//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>

int main() {

    // file to read from
    FILE *fp;

    // open a file
    fp = fopen("my_book.txt", "r");

    // string buffer to read a single line
    char buffer[256];

    // read each line from the file and print to console
    while (fgets(buffer, 256, fp)) {
        printf("%s", buffer);
    }

    // close the file
    fclose(fp);

    return 0;
}