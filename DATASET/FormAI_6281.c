//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    FILE *fp;
    char file_name[MAX_SIZE];
    char search_word[MAX_SIZE];
    char replace_word[MAX_SIZE];
    char temp[MAX_SIZE];
    char *pos;
    int len_search, len_replace;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the search word: ");
    scanf("%s", search_word);

    printf("Enter the replace word: ");
    scanf("%s", replace_word);

    len_search = strlen(search_word);
    len_replace = strlen(replace_word);

    fp = fopen(file_name, "r+");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(temp, MAX_SIZE, fp) != NULL) {
        while ((pos = strstr(temp, search_word)) != NULL) {
            strncpy(pos, replace_word, len_replace);
            memmove(pos + len_replace, pos + len_search, strlen(pos + len_search) + 1);
            fseek(fp, -strlen(temp), SEEK_CUR);
            fputs(temp, fp);
            fseek(fp, strlen(temp) - len_replace, SEEK_CUR);
        }
    }

    fclose(fp);
    printf("Done!\n");

    return 0;
}