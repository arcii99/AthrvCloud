//FormAI DATASET v1.0 Category: Text Summarizer ; Style: rigorous
/*
    C Text Summarizer Example Program
    Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE], summary[MAX_SUMMARY_SIZE];
    int input_size, summary_size, i, j, k, l, m, count;
    char words[MAX_INPUT_SIZE][20];
    int freq[MAX_INPUT_SIZE] = {0};
    int index[MAX_INPUT_SIZE];
    
    printf("Enter the text:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);
    
    // Remove special characters and convert to lowercase
    for(i = 0; i < input_size; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
        if(!(input[i] >= 'a' && input[i] <= 'z')) {
            input[i] = ' ';
        }
    }
    
    // Tokenize input
    j = 0;
    k = 0;
    for(i = 0; i < input_size; i++) {
        if(input[i] == ' ') {
            words[j][k] = '\0';
            j++;
            k = 0;
        } else {
            words[j][k] = input[i];
            k++;
        }
    }
    
    // Calculate word frequencies
    for(i = 0; i < j; i++) {
        freq[i] = 1;
        for(k = i+1; k < j; k++) {
            if(strcmp(words[i], words[k]) == 0) {
                freq[i]++;
                words[k][0] = '\0';
            }
        }
    }
    
    // Sort words by frequency
    count = j;
    for(i = 0; i < count; i++) {
        index[i] = i;
    }
    for(i = 0; i < count-1; i++) {
        for(k = i+1; k < count; k++) {
            if(freq[index[i]] < freq[index[k]]) {
                l = index[i];
                index[i] = index[k];
                index[k] = l;
            }
        }
    }
    
    // Generate summary
    summary_size = 0;
    for(i = 0; i < count; i++) {
        if(freq[index[i]] > 1) {
            for(m = 0; m < summary_size; m++) {
                if(strcmp(summary, words[index[i]]) == 0) {
                    break;
                }
            }
            if(m == summary_size) {
                strcat(summary, words[index[i]]);
                strcat(summary, " ");
                summary_size += strlen(words[index[i]]) + 1;
            }
        }
    }
    
    // Print summary
    printf("Summary:\n%s\n", summary);
    
    return 0;
}