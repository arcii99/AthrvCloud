//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_CHARACTERS 10000

char sentences[MAX_SENTENCES][MAX_CHARACTERS];
char words[MAX_WORDS][MAX_CHARACTERS];

void get_sentences(char text[]);
void get_words(char sentence[], int sentence_number);
int count_words(char sentence[]);
int count_sentences();
void to_lowercase(char string[]);
void sort_sentences(int sentence_count);
void print_summary(int sentence_count);

int main() {
    char text[MAX_CHARACTERS];
    printf("Enter a text to summarize: ");
    fgets(text, MAX_CHARACTERS, stdin);

    get_sentences(text);
    int sentence_count = count_sentences();

    if (sentence_count == 0) {
        printf("No sentences found.");
        return 1;
    }

    for (int i = 0; i < sentence_count; i++) {
        get_words(sentences[i], i);
    }

    sort_sentences(sentence_count);
    print_summary(sentence_count);

    return 0;
}

void get_sentences(char text[]) {
    int text_length = strlen(text);
    int sentence_index = 0;
    int character_index = 0;

    for (int i = 0; i < text_length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences[sentence_index][character_index] = text[i];
            sentences[sentence_index][character_index + 1] = '\0';
            sentence_index++;
            character_index = 0;
        } else {
            sentences[sentence_index][character_index] = text[i];
            character_index++;
        }
    }
}

void get_words(char sentence[], int sentence_number) {
    int sentence_length = strlen(sentence);
    int word_index = 0;
    int character_index = 0;

    for (int i = 0; i < sentence_length; i++) {
        if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '\n' || sentence[i] == '\r') {
            words[sentence_number][word_index] = '\0';
            word_index++;
            character_index = 0;
        } else {
            words[sentence_number][word_index] = sentence[i];
            character_index++;
        }
    }
}

int count_words(char sentence[]) {
    int sentence_length = strlen(sentence);
    int word_count = 0;

    for (int i = 0; i < sentence_length; i++) {
        if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '\n' || sentence[i] == '\r') {
            word_count++;
        }
    }

    return word_count;
}

int count_sentences() {
    int sentence_count = 0;

    for (int i = 0; i < MAX_SENTENCES; i++) {
        if (sentences[i][0] != '\0') {
            sentence_count++;
        }
    }

    return sentence_count;
}

void to_lowercase(char string[]) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        string[i] = tolower(string[i]);
    }
}

void sort_sentences(int sentence_count) {
    for (int i = 0; i < sentence_count; i++) {
        for (int j = i + 1; j < sentence_count; j++) {
            if (count_words(words[i]) > count_words(words[j])) {
                char temp_sentence[MAX_CHARACTERS];
                strcpy(temp_sentence, sentences[i]);
                strcpy(sentences[i], sentences[j]);
                strcpy(sentences[j], temp_sentence);

                char temp_words[MAX_CHARACTERS];
                strcpy(temp_words, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp_words);
            }
        }
    }
}

void print_summary(int sentence_count) {
    printf("\n\nSherlock Holmes says:\n\n");
    printf("Based on my analysis, the relevant information of the text you provided is as follows:\n\n");

    for (int i = sentence_count - 1; i >= 0; i--) {
        int word_count = count_words(words[i]);

        if (word_count >= 5) {
            to_lowercase(sentences[i]);
            printf("%s", sentences[i]);
        }
    }
}