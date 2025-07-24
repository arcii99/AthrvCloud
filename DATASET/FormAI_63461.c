//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    
    char filename[100];
    printf("Please enter the name of the file you would like to count: ");
    scanf("%s", filename);
    
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int word_count = 0;
    int char_count = 0;
    
    char c;
    int in_word = 0;
    while ((c = fgetc(fp)) != EOF) {
        char_count++;
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }
    
    fclose(fp);
    
    printf("The file '%s' contains %d words and %d characters.\n", filename, word_count, char_count);
    
    return 0;
}