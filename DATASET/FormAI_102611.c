//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 20
#define MAX_SUMMARY_SIZE 300

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} word_count;

word_count *count_words(char *text, int *num_unique_words);
int compare_word_count(const void *a, const void *b);
void generate_summary(word_count *words, int num_words, char *summary);

int main(){
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer porta tempor ex et luctus. Vestibulum convallis sapien leo, a facilisis lacus ullamcorper quis. Morbi quis felis urna. Duis fringilla nisl sed dolor faucibus ultrices. Sed eget arcu mauris. Suspendisse potenti. Sed semper felis quis augue eleifend, at accumsan mauris mollis. Sed vel ornare nibh. Vivamus sed enim vel ante rhoncus rhoncus. Nunc efficitur ex ac leo ullamcorper, vitae consequat nibh interdum. Sed a nulla eget libero dapibus laoreet. Sed quis malesuada metus. Quisque ut diam blandit, dignissim nisi et, commodo lectus. Morbi urna elit, dapibus nec metus id, gravida maximus purus.";

    int num_words;
    word_count *words = count_words(text, &num_words);
    qsort(words, num_words, sizeof(word_count), compare_word_count);

    char summary[MAX_SUMMARY_SIZE];
    generate_summary(words, num_words, summary);

    printf("Original Text: %s\n\n", text);
    printf("Summary: %s\n", summary);

    free(words);

    return 0;
}

word_count *count_words(char *text, int *num_unique_words){
    char *word;
    word_count *words = NULL;
    int max_words = 0;
    *num_unique_words = 0;

    word = strtok(text, " .,;:");
    while(word != NULL){
        if(isalpha(word[0])){
            int i, found = -1;
            for(i = 0; i < *num_unique_words; i++){
                if(strcmp(words[i].word, word) == 0){
                    found = i;
                    break;
                }
            }

            if(found == -1){
                if((*num_unique_words) >= max_words){
                    max_words += 10;
                    words = realloc(words, max_words*sizeof(word_count));
                    if(words == NULL){
                        fprintf(stderr, "Error: Could not allocate memory\n");
                        exit(1);
                    }
                }

                strcpy(words[(*num_unique_words)].word, word);
                words[(*num_unique_words)].count = 1;
                (*num_unique_words)++;
            }
            else {
                words[found].count++;
            }
        }

        word = strtok(NULL, " .,;:");
    }

    return words;
}

int compare_word_count(const void *a, const void *b){
    return ((word_count*)b)->count - ((word_count*)a)->count;
}

void generate_summary(word_count *words, int num_words, char *summary){
    int i, summary_len = 0;

    for(i = 0; i < num_words && summary_len < MAX_SUMMARY_SIZE; i++){
        if(words[i].count >= 2){ // only consider words that appear twice or more
            strcat(summary, words[i].word);
            strcat(summary, " ");
            summary_len += strlen(words[i].word) + 1;
        }
    }
}