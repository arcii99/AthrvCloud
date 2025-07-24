//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_SENT_LEN 500

typedef struct word {
    char *data;
    struct word *next;
} word_t;

typedef struct sentence {
    word_t *words;
    struct sentence *next;
} sentence_t;

void free_words(word_t *w) {
    if (w->next != NULL) {
        free_words(w->next);
    }

    free(w->data);
    free(w);
}

void free_sentences(sentence_t *s) {
    if (s->next != NULL) {
        free_sentences(s->next);
    }

    free_words(s->words);
    free(s);
}

int split_words(char *input, word_t **output) {
    char buffer[MAX_WORD_LEN];
    int buffer_i = 0;
    int i = 0;
    int n_words = 0;

    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\n') {
            if (buffer_i > 0) {
                buffer[buffer_i] = '\0';

                word_t *w = (word_t *)malloc(sizeof(word_t));
                w->data = (char *)malloc(strlen(buffer) + 1);
                strcpy(w->data, buffer);
                w->next = NULL;

                if (*output == NULL) {
                    *output = w;
                } else {
                    word_t *tail = *output;
                    while (tail->next != NULL) {
                        tail = tail->next;
                    }
                    tail->next = w;
                }

                buffer_i = 0;
                n_words++;
            }
        } else {
            if (buffer_i < MAX_WORD_LEN - 1) {
                buffer[buffer_i] = input[i];
                buffer_i++;
            }
        }

        i++;
    }

    if (buffer_i > 0) {
        buffer[buffer_i] = '\0';

        word_t *w = (word_t *)malloc(sizeof(word_t));
        w->data = (char *)malloc(strlen(buffer) + 1);
        strcpy(w->data, buffer);
        w->next = NULL;

        if (*output == NULL) {
            *output = w;
        } else {
            word_t *tail = *output;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = w;
        }

        n_words++;
    }

    return n_words;
}

int split_sentences(char *input, sentence_t **output) {
    char buffer[MAX_SENT_LEN];
    int buffer_i = 0;
    int i = 0;
    int n_sentences = 0;
    int last_was_period = 0;

    while (input[i] != '\0') {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            last_was_period = 1;
        } else if (input[i] == '\n') {
            if (last_was_period && buffer_i > 0) {
                sentence_t *s = (sentence_t *)malloc(sizeof(sentence_t));
                s->words = NULL;
                s->next = NULL;

                if (*output == NULL) {
                    *output = s;
                } else {
                    sentence_t *tail = *output;
                    while (tail->next != NULL) {
                        tail = tail->next;
                    }
                    tail->next = s;
                }

                split_words(buffer, &(s->words));
                n_sentences++;

                buffer_i = 0;
                last_was_period = 0;
            }
        } else {
            last_was_period = 0;
        }

        if (buffer_i < MAX_SENT_LEN - 1) {
            buffer[buffer_i] = input[i];
            buffer_i++;
        }

        i++;
    }

    if (last_was_period && buffer_i > 0) {
        sentence_t *s = (sentence_t *)malloc(sizeof(sentence_t));
        s->words = NULL;
        s->next = NULL;

        if (*output == NULL) {
            *output = s;
        } else {
            sentence_t *tail = *output;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = s;
        }

        split_words(buffer, &(s->words));
        n_sentences++;
    }

    return n_sentences;
}

int count_occurences(sentence_t *sentences, char *word) {
    int count = 0;

    sentence_t *s = sentences;
    while (s != NULL) {
        word_t *w = s->words;
        while (w != NULL) {
            if (strcmp(w->data, word) == 0) {
                count++;
            }
            w = w->next;
        }
        s = s->next;
    }

    return count;
}

int summarize(char *input, char **output, int max_sentences) {
    sentence_t *sentences = NULL;
    int n_sentences = split_sentences(input, &sentences);

    if (n_sentences == 0) {
        *output = (char *)malloc(1);
        *output[0] = '\0';
        return 0;
    }

    if (max_sentences >= n_sentences) {
        *output = (char *)malloc(strlen(input) + 1);
        strcpy(*output, input);
        return n_sentences;
    }

    int *scores = (int *)malloc(n_sentences * sizeof(int));
    for (int i = 0; i < n_sentences; i++) {
        scores[i] = 0;
    }

    sentence_t *s = sentences;
    int i = 0;
    while (s != NULL) {
        word_t *w = s->words;
        while (w != NULL) {
            scores[i] += count_occurences(sentences, w->data);
            w = w->next;
        }
        s = s->next;
        i++;
    }

    int *indices = (int *)malloc(n_sentences * sizeof(int));
    for (int i = 0; i < n_sentences; i++) {
        indices[i] = i;
    }

    for (int i = 0; i < n_sentences; i++) {
        for (int j = i+1; j < n_sentences; j++) {
            if (scores[indices[j]] > scores[indices[i]]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    int n_summary_sentences = (max_sentences < n_sentences) ? max_sentences : n_sentences;
    *output = (char *)malloc(n_summary_sentences * MAX_SENT_LEN + 1);
    int out_i = 0;
    for (int i = 0; i < n_summary_sentences; i++) {
        s = sentences;
        for (int j = 0; j < indices[i]; j++) {
            s = s->next;
        }

        word_t *w = s->words;
        while (w != NULL) {
            if (out_i + strlen(w->data) + 1 > n_summary_sentences * MAX_SENT_LEN) {
                break;
            }

            strcat(*output, w->data);
            strcat(*output, " ");

            out_i += strlen(w->data) + 1;
            w = w->next;
        }

        strcat(*output, "\n");
        out_i++;
    }

    free(scores);
    free(indices);
    free_sentences(sentences);

    return n_summary_sentences;
}

int main() {
    char *input = "C Text Summarizer is a program that applies Natural Language Processing to a text input and outputs a summary of the content. The output summary consists of the most important sentences that best represent the content of the input. C Text Summarizer can be used to quickly extract key information from long texts, making it useful for both research and personal purposes.\n\nC Text Summarizer is implemented using a simple algorithm that ranks sentences based on their relevance to the input text. The relevance of a sentence is determined by the frequency of its constituent words within the input text. Sentences with higher frequency words are considered to be more relevant and are selected for inclusion in the output summary. The final selection of sentences is determined by the length of the desired output summary, which is specified by the user.\n\nC Text Summarizer is a powerful tool for analyzing and summarizing text data. Its simple implementation and ease of use make it a valuable resource for researchers and students alike.";

    char *output;
    int n_summary_sentences = summarize(input, &output, 3);

    printf("%s", output);

    free(output);
    return 0;
}