//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <string.h>

// A function to calculate the length of an array
int get_size(char arr[]) {
    int size = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        size++;
    }
    return size;
}

// A function to check if a character is a space or not
int is_space(char c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    }
    return 0;
}

// A function to remove leading and trailing spaces
char* trim(char arr[]) {
    int size = get_size(arr);
    int start_index = 0, end_index = size - 1;

    while (is_space(arr[start_index])) {
        start_index++;
    }
    while (is_space(arr[end_index])) {
        end_index--;
    }

    char *new_arr = malloc(sizeof(char) * (end_index - start_index + 2));
    int j = 0;

    for (int i = start_index; i <= end_index; i++) {
        new_arr[j] = arr[i];
        j++;
    }
    new_arr[j] = '\0';

    return new_arr;
}

// A function to split a string into words
char** split_words(char *arr, int *word_count) {
    int size = get_size(arr);
    int start_index = 0, end_index = 0, words = 1;

    // Counting number of words in the array
    for (int i = 0; i < size; i++) {
        if (is_space(arr[i])) {
            words++;
        }
    }

    char **word_arr = malloc(sizeof(char*) * words);

    // Storing words in the array
    for (int i = 0; i < words; i++) {
        while (is_space(arr[start_index])) {
            start_index++;
        }
        end_index = start_index;
        while (!is_space(arr[end_index]) && end_index < size) {
            end_index++;
        }

        word_arr[i] = malloc(sizeof(char) * (end_index - start_index + 1));
        int j = 0;
        for (int k = start_index; k < end_index; k++) {
            word_arr[i][j] = arr[k];
            j++;
        }
        word_arr[i][j] = '\0';
        start_index = end_index;
    }

    *word_count = words;
    return word_arr;
}

// A function to get frequency of each word
void get_freq(char **word_arr, int word_count, int freq[]) {
    for (int i = 0; i < word_count; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (strcmp(word_arr[i], word_arr[j]) == 0) {
                freq[i]++;
            }
        }
    }
}

// A function to print the summary
void print_summary(char **word_arr, int freq[], int word_count) {
    int max_freq = 0, max_index = 0;    

    printf("Summary: ");

    // Finding the most frequent word
    for (int i = 0; i < word_count; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_index = i;
        }
    }

    // Printing sentences with most frequent word
    for (int i = 0; i < word_count; i++) {
        char *curr_word = word_arr[i];
        if (freq[i] == max_freq) {
            printf("%s ", curr_word);
        }
        for (int j = 0; curr_word[j] != '\0'; j++) {
            if (curr_word[j] == '.' || curr_word[j] == '?' || curr_word[j] == '!') {
                if (freq[i] == max_freq) {
                    printf("%c ", curr_word[j]);
                }
                break;
            }
        }
    }
}

// The main function
int main() {
    char text[] = "This is a sample text. It is just for demonstration purposes. We will use it to create a summary. The summary will contain the most frequently occurring word. Hopefully, the summary will be accurate and meaningful.";

    // Removing leading and trailing spaces
    char *trimmed_text = trim(text);

    // Splitting text into words
    int word_count = 0;
    char **word_arr = split_words(trimmed_text, &word_count);

    // Getting frequency of each word
    int freq[word_count];
    for (int i = 0; i < word_count; i++) {
        freq[i] = 1;
    }
    get_freq(word_arr, word_count, freq);

    // Printing the summary
    print_summary(word_arr, freq, word_count);

    return 0;
}