//FormAI DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>

int main() {

    FILE *fp;
    int i = 0;
    char c;

    fp = fopen("mystery.txt", "r");

    while (1) {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        else if (c == ',') {
            i++;
        }
    }
    fclose(fp);

    if (i == 42) {
        printf("Congratulations! You solved the mystery!\n");
    }
    else {
        printf("Sorry, that's not the correct answer.\n");
    }

    return 0;
}