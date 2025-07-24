//FormAI DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the C File handling example program!\n");
    printf("This program will read a file, count words and display them in decreasing order!\n");

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot read the file!");
        return 1;
    }

    int words[26] = {0};
    char c;
    int index;
    while ((c = fgetc(file)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            index = c - 'A';
        } else if (c >= 'a' && c <= 'z') {
            index = c - 'a';
        } else {
            continue;
        }
        words[index]++;
    }

    fclose(file);

    printf("Word\t\tCount\n");
    for (int i = 0; i < 26; i++) {
        int max = 0;
        int max_index;
        for (int j = 0; j < 26; j++) {
            if (words[j] > max) {
                max_index = j;
                max = words[j];
            }
        }
        if (max > 0) {
            printf("%c\t\t%d\n", 'a' + max_index, max);
            words[max_index] = 0;
        }
    }

    return 0;
}