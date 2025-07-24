//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() { 
    char input_text[10000], output_text[10000];
    char sentence_array[100][1000];
    int sentence_count = 0, word_count = 0, character_count = 0;

    printf("Enter the text that needs to be summarized:\n");

    //Reads input text
    fgets(input_text, 10000, stdin);

    //loop to tokenize sentences and words
    for(int i = 0; i < strlen(input_text); i++) {
        if(input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_array[sentence_count][word_count++] = input_text[i];
            sentence_array[sentence_count][word_count] = '\0';
            sentence_count++;
            word_count = 0;
        } else if(input_text[i] == ' ') {
            sentence_array[sentence_count][word_count++] = input_text[i];
        } else {
            sentence_array[sentence_count][word_count++] = tolower(input_text[i]);
        }
    }

    //loop to summarize text
    for(int i = 0; i < sentence_count; i++) {
        int count = 0, j = 0;

        while(j < strlen(sentence_array[i])) {
            if(isalpha(sentence_array[i][j])) {
                count++;
                while(isalpha(sentence_array[i][j])) j++;
            } else {
                j++;
            }
        }

        if(count > 2 && (character_count + strlen(sentence_array[i])) <= 70) {
            strcat(output_text, sentence_array[i]);
            character_count += strlen(sentence_array[i]);
        } else if((character_count + strlen(sentence_array[i])) > 70) {
            break;
        }
    }

    //Prints the summarized text
    printf("\n------------------\n");
    printf("Summarized Text:\n");
    printf("------------------\n");
    printf("%s\n", output_text);

    return 0;
}