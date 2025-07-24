//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_LINE_LEN 200

int main() {
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    int count = 0;
    int totalWords = 0;
    float avg = 0.0;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        int i;
        for (i = 0; i <= strlen(line); i++) {
            if (line[i] == ' ' || line[i] == '\0' || line[i] == '\n') {
                if (count > 0) {
                    totalWords++;
                }
                count = 0;
            } else {
                word[count++] = line[i];
            }
        }
        avg = (float) totalWords / i;
    }

    printf("Total words: %d\n", totalWords);
    printf("Average word count: %.2f\n", avg);

    fclose(fp);
    return 0;
}