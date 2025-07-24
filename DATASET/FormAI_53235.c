//FormAI DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>

void print_hello() {
    printf("Hello, I am a C program.\n");
}

int main() {
    printf("This program will print its own source code.\n");
    printf("Here is the code:\n\n");

    // open up this file and read each line
    FILE *fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer); // print each line
    }

    fclose(fp); // close the file

    printf("\n\nAnd that's it!\n");

    return 0;
}