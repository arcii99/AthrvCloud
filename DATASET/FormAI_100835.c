//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

struct word{
    char str[MAX_WORD_LENGTH + 1];
    int count;
};

int compare_words(const void *a, const void *b){
    return (*(struct word *)b).count - (*(struct word *)a).count;
}

int main(){
    char *filename = "sample.txt";
    FILE *file = fopen(filename, "r");

    if(!file){
        printf("Unable to open file: %s\n", filename);
        return 1;
    }

    struct word words[MAX_WORDS];
    int num_words = 0;

    char curr_word[MAX_WORD_LENGTH + 1];
    int curr_word_len = 0;
    int c;

    while((c = fgetc(file)) != EOF){
        if(isalpha(c)){
            if(curr_word_len < MAX_WORD_LENGTH){
                curr_word[curr_word_len++] = tolower(c);
            }
        }
        else if(curr_word_len > 0){
            curr_word[curr_word_len] = '\0';

            int i;
            for(i = 0; i < num_words; i++){
                if(strcmp(words[i].str, curr_word) == 0){
                    words[i].count++;
                    break;
                }
            }

            if(i == num_words){
                strcpy(words[num_words].str, curr_word);
                words[num_words].count = 1;
                num_words++;
            }

            curr_word_len = 0;
        }
    }

    if(curr_word_len > 0){
        curr_word[curr_word_len] = '\0';

        int i;
        for(i = 0; i < num_words; i++){
            if(strcmp(words[i].str, curr_word) == 0){
                words[i].count++;
                break;
            }
        }

        if(i == num_words){
            strcpy(words[num_words].str, curr_word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    qsort(words, num_words, sizeof(struct word), compare_words);

    int i;
    for(i = 0; i < num_words; i++){
        printf("%s: %d\n", words[i].str, words[i].count);
    }

    fclose(file);
    return 0;
}