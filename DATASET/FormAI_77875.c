//FormAI DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    system("clear");
    
    // Introduction message
    printf("Welcome to the C Word Count Tool, survivor.\n");
    printf("Please enter your post-apocalyptic document below:\n");
    
    // Get input string from user
    char input[10000];
    fgets(input, 10000, stdin);
    
    // Replace new lines with spaces
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            input[i] = ' ';
        }
    }
    
    // Remove punctuation marks
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ',' || input[i] == '.' || input[i] == ';' || input[i] == ':' || input[i] == '!' || input[i] == '?') {
            input[i] = ' ';
        }
    }
    
    // Tokenize input string
    char *token;
    int num_words = 0;
    char *words[10000];
    token = strtok(input, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }
    
    // Count number of occurrences of each unique word
    int word_count[num_words];
    int unique_words = 0;
    for (int i = 0; i < num_words; i++) {
        int count = 1;
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
                words[j] = "";
            }
        }
        if (strcmp(words[i], "") != 0) {
            word_count[unique_words] = count;
            unique_words++;
        }
    }
    
    // Sort unique words and their counts by frequency
    char *sorted_words[unique_words];
    int sorted_counts[unique_words];
    int used_indices[unique_words];
    for (int i = 0; i < unique_words; i++) {
        int max_count = 0;
        int max_index = 0;
        for (int j = 0; j < unique_words; j++) {
            if (word_count[j] > max_count && !contains(used_indices, j, i)) {
                max_count = word_count[j];
                max_index = j;
            }
        }
        sorted_words[i] = words[max_index];
        sorted_counts[i] = max_count;
        used_indices[i] = max_index;
    }
    
    // Display results
    printf("\nWord Count Results\n");
    printf("-------------------\n");
    for (int i = 0; i < unique_words; i++) {
        printf("%s: %d\n", sorted_words[i], sorted_counts[i]);
    }
    
    return 0;
}

int contains(int *arr, int x, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}