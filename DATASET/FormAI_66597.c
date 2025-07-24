//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to calculate the occurrence of a word in a string
int word_count(char str[], char word[]) {
    int count = 0;
    char *ptr = strstr(str, word);
    
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr + 1, word);
    }
    
    return count;
}

//Function to calculate the frequency of each word in a string
void calculate_frequency(char str[]) {
    char *token, *copy;
    int count = 0, i, j, k, n = 0;
    char words[100][100];
    int occurrences[100] = {0};
    
    copy = strdup(str);
    token = strtok(copy, " ,.!?\n");
    
    while(token != NULL) {
        for(i = 0; i < n; i++) {
            if(strcmp(words[i], token) == 0) {
                occurrences[i]++;
                count = 1;
                break;
            }
        }
        if(count == 0) {
            strcpy(words[n], token);
            occurrences[n]++;
            n++;
        }
        count = 0;
        token = strtok(NULL, " ,.!?\n");
    }
    
    printf("\nFrequency Table:");
    printf("\n----------------");
    for(i = 0; i < n; i++) {
        printf("\n%-10s", words[i]);
        for(j = 0; j < occurrences[i]; j++) {
            printf("*");
        }
    }
}

int main() {
    char input_text[1000];
    char summary[500];
    
    printf("Enter the text to summarize: ");
    fgets(input_text, 1000, stdin);
    
    int word_count_education = word_count(input_text, "education");
    int word_count_technology = word_count(input_text, "technology");
    int word_count_science = word_count(input_text, "science");
    int total_word_count = word_count_education + word_count_technology + word_count_science;
    
    if(total_word_count == 0) {
        printf("\nNo relevant words found in input text.\n");
        exit(0);
    }
    
    if(word_count_education > (total_word_count / 2)) {
        strcat(summary, "This text talks mostly about education. ");
    }
    if(word_count_technology > (total_word_count / 2)) {
        strcat(summary, "This text talks mostly about technology. ");
    }
    if(word_count_science > (total_word_count / 2)) {
        strcat(summary, "This text talks mostly about science. ");
    }
    
    printf("\nSummary: %s", summary);
    
    calculate_frequency(input_text);
    
    return 0;
}