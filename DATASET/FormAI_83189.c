//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    // check if the file exists or not
    if ((fp = fopen("example.txt", "r")) == NULL) {
        printf("File does not exist.\n");
        return 1;
    }

    // read the contents of the file
    int c;
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }

    // close the file
    fclose(fp);

    // prompt the user to add some text to the file
    printf("\nEnter some text to add to the file: \n");
    char buffer[100];
    fgets(buffer, 100, stdin);

    // append the user input to the file
    fp = fopen("example.txt", "a");
    fputs(buffer, fp);
    fclose(fp);

    // read the file again to display the updated contents
    fp = fopen("example.txt", "r");
    printf("\nUpdated contents of the file: \n");
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }

    // close the file
    fclose(fp);

    return 0;
}