//FormAI DATASET v1.0 Category: Text Summarizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 500

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int frequency;
    float sentence_score;
} Sentence;

int get_total_sentences(char *text) {
    int count = 0;
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
        i++;
    }
    return count;
}

void split_text_into_sentences(char *text, char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH]) {
    int i = 0, j = 0, k = 0;
    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[j][k] = text[i];
            sentences[j][k+1] = '\0';
            j++;
            k = 0;
        }
        else {
            sentences[j][k] = text[i];
            k++;
        }
        i++;
    }
}

void remove_punctuations(char *sentence) {
    int i = 0, j = 0;
    while (sentence[i] != '\0') {
        if (!ispunct(sentence[i])) {
            sentence[j] = sentence[i];
            j++;
        }
        i++;
    }
    sentence[j] = '\0';
}

void remove_spaces(char *sentence) {
    int i = 0, j = 0;
    while (sentence[i] != '\0') {
        if (!isspace(sentence[i])) {
            sentence[j] = sentence[i];
            j++;
        }
        i++;
    }
    sentence[j] = '\0';
}

void to_lowercase(char *sentence) {
    for (int i = 0; sentence[i]; i++) {
        sentence[i] = tolower(sentence[i]);
    }
}

void calculate_sentence_frequency(char *text, Sentence sentence_array[MAX_SENTENCES], int total_sentences) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    split_text_into_sentences(text, sentences);
    for (int i = 0; i < total_sentences; i++) {
        sentence_array[i].frequency = 0;
        for (int j = 0; j < total_sentences; j++) {
            if (i != j) {
                char *temp = strstr(sentences[j], sentences[i]);
                if (temp != NULL) {
                    sentence_array[i].frequency++;
                }
            }
        }
    }
}

void calculate_sentence_score(char *text, Sentence sentence_array[MAX_SENTENCES], int total_sentences) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    split_text_into_sentences(text, sentences);
    int total_words = 0;
    for (int i = 0; i < total_sentences; i++) {
        sentence_array[i].sentence_score = 0;
        char *temp = strtok(sentences[i], " ");
        while (temp != NULL) {
            total_words++;
            temp = strtok(NULL, " ");
        }
    }
    for (int i = 0; i < total_sentences; i++) {
        char *temp = strtok(sentences[i], " ");
        while (temp != NULL) {
            for (int j = 0; j < total_sentences; j++) {
                if (i != j) {
                    char *check = strstr(sentences[j], temp);
                    if (check != NULL) {
                        sentence_array[i].sentence_score += 1.0 / sentence_array[j].frequency;
                    }
                }
            }
            temp = strtok(NULL, " ");
        }
        sentence_array[i].sentence_score *= (float)sentence_array[i].frequency / total_words;
    }
}

void get_summary(char *text, char *summary, int max_summary_length) {
    Sentence sentence_array[MAX_SENTENCES];
    int total_sentences = get_total_sentences(text);
    calculate_sentence_frequency(text, sentence_array, total_sentences);
    calculate_sentence_score(text, sentence_array, total_sentences);
    float max_score = 0;
    int max_index = 0;
    for (int i = 0; i < total_sentences; i++) {
        if (sentence_array[i].sentence_score > max_score) {
            max_score = sentence_array[i].sentence_score;
            max_index = i;
        }
    }
    strcpy(summary, sentence_array[max_index].sentence);
    for (int i = 0; i < total_sentences; i++) {
        if (i != max_index) {
            if (strlen(summary) + strlen(sentence_array[i].sentence) < max_summary_length - 1) {
                strcat(summary, sentence_array[i].sentence);
            }
            else {
                break;
            }
        }
    }
}

int main() {
    char text[] = "Natural Language Processing (NLP) is a subfield of computer science that deals with the interactions between computers and humans using natural language. The ultimate objective of NLP is to enable computers to understand, interpret, and generate human language. In order to achieve this goal, NLP employs machine learning algorithms, computational linguistics, and artificial intelligence techniques. NLP has several applications, including machine translation, sentiment analysis, named entity recognition, and speech recognition. With the rapid growth of big data and machine learning, the demand for NLP-based products and services has been increasing in recent years.";
    char summary[MAX_SUMMARY_LENGTH];
    get_summary(text, summary, MAX_SUMMARY_LENGTH);
    printf("%s", summary);
    return 0;
}