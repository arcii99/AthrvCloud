//FormAI DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000

int read_file(char *filename, char *buffer);
int count_words(char *buffer, int len);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    char buffer[MAX_SIZE];
    int len = read_file(argv[1], buffer);

    if (len < 0) {
        fprintf(stderr, "Error: could not read file %s\n", argv[1]);
        return 1;
    }

    int num_words = count_words(buffer, len);
    printf("Number of words: %d\n", num_words);

    return 0;
}

int read_file(char *filename, char *buffer)
{
    FILE *fp;
    int len;

    fp = fopen(filename, "r");
    if (fp == NULL)
        return -1;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    fread(buffer, 1, len, fp);

    fclose(fp);

    return len;
}

int count_words(char *buffer, int len)
{
    char word[MAX_SIZE];
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(buffer[i])) {
            int j = 0;
            while (isalpha(buffer[i])) {
                word[j++] = tolower(buffer[i++]);
            }
            word[j] = '\0';
            count++;
        }
    }

    return count;
}