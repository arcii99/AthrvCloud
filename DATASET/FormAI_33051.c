//FormAI DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

int main(){
    char input[MAX_WORDS * MAX_LENGTH];
    char *words[MAX_WORDS];
    int count[MAX_WORDS] = {0};

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    /* Tokenize input */
    char *token = strtok(input, " \n");
    int num_words = 0;

    while(token != NULL && num_words < MAX_WORDS){
        words[num_words++] = token;
        token = strtok(NULL, " \n");
    }

    /* Count word frequency */
    for(int i = 0; i < num_words; i++){
        for(int j = 0; j < num_words; j++){
            if(strcmp(words[i], words[j]) == 0){
                count[i]++;
            }
        }
    }

    /* Print word frequency */
    printf("\nWord Frequency:\n");

    for(int i = 0; i < num_words; i++){
        if(count[i] != -1){
            printf("%s: %d\n", words[i], count[i]);

            /* Mark word as counted */
            for(int j = i + 1; j < num_words; j++){
                if(strcmp(words[i], words[j]) == 0){
                    count[j] = -1;
                }
            }
        }
    }

    return 0;
}