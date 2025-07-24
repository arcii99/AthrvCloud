//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100

int countWords(char *str);

int main()
{
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    int num_words = countWords(str);

    if(num_words == 0){
        printf("No words found in string.\n");
    }
    else if(num_words == 1){
        printf("1 word found in string.\n");
    }
    else{
        printf("%d words found in string.\n", num_words);
    }

    return 0;
}

int countWords(char *str)
{
    int count = 0, inWord = 0;

    // Loop through each character in string
    for(int i = 0; str[i] != '\0'; i++){
        // If current character is alphabetic
        if(isalpha(str[i])){
            // Check if currently in a word
            if(inWord == 0){
                inWord = 1;
                count++;
            }
        }
        // If current character is not alphabetic
        else{
            inWord = 0;
        }
    }

    return count;
}