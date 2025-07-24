//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Error Handling program. Let's make sure everything runs smoothly!\n");

    FILE *fp;
    char *filename = "example.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Uh oh! There was an error opening the file.\n");
        printf("Don't worry, we'll fix it in no time.\n");

        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Error opening file again. We're in trouble now.\n");
            printf("Let's try again with a different file name.\n");

            filename = "example2.txt";
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Oh no! Even the second file isn't working.\n");
                printf("We might have to resort to desperate measures...\n");

                exit(1);
            }
        }
    }

    printf("Great news! We were able to open a file.\n");
    printf("Now let's read the contents and print them to the console.\n");

    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    fclose(fp);

    printf("\nSuccess! We were able to read and print the contents of the file without any errors.\n");

    return 0;
}