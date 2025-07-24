//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("file.txt", "r"); // open text file for reading

    if (fp == NULL) // check if file exists
    {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char word[50]; // buffer to store each word
    int words_count = 0, chars_count = 0;

    // read each word from file
    while (fscanf(fp, "%s", word) != EOF)
    {
        int len = strlen(word);
        chars_count += len; // increment character count by length of word
        words_count++; // increment word count

        // convert word to uppercase
        for (int i = 0; i < len; i++) 
        {
            word[i] = toupper(word[i]);
        }

        printf("%s ", word); // print converted word to console
    }

    printf("\n\nNumber of words: %d", words_count);
    printf("\nNumber of characters: %d", chars_count);

    fclose(fp); // close file pointer
    return 0;
}