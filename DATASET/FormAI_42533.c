//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 10
#define MAX_SUMMARY_LENGTH 200

typedef struct sentence {
    char* text;
    int score;
} Sentence;

int count_words(char* text) {
    int count = 0;
    char* token = strtok(text, " ");
    while(token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int contains_word(char* text, char* word) {
    char* token = strtok(text, " ");
    while(token != NULL) {
        if(strcmp(token, word) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int count_occurrences(char* text, char* word) {
    int count = 0;
    char* token = strtok(text, " ");
    while(token != NULL) {
        if(strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

void calculate_score(char* text, Sentence* sentence) {
    int word_count = count_words(text);
    int cool_count = count_occurrences(text, "cool");
    int score = 0;
    score += word_count * 10;
    score += cool_count * 50;
    sentence->score = score;
}

void summarize_text(char* input, char* output) {
    Sentence sentences[MAX_SENTENCES];
    char* token = strtok(input, ".\n");
    int count = 0;
    while(token != NULL) {
        sentences[count].text = token;
        sentences[count].score = 0;
        calculate_score(token, &sentences[count]);
        count++;
        token = strtok(NULL, ".\n");
    }
    int i, j;
    // Sort sentences by score
    for(i = 0; i < count - 1; i++) {
        int max_index = i;
        for(j = i + 1; j < count; j++) {
            if(sentences[j].score > sentences[max_index].score) {
                max_index = j;
            }
        }
        Sentence temp = sentences[i];
        sentences[i] = sentences[max_index];
        sentences[max_index] = temp;
    }
    // Generate summary
    char* summary = malloc(MAX_SUMMARY_LENGTH);
    summary[0] = '\0';
    for(i = 0; i < count && strlen(summary) < MAX_SUMMARY_LENGTH; i++) {
        if(contains_word(summary, "cool")) {
            break;
        }
        strcat(summary, sentences[i].text);
        if(i < count - 1) {
            strcat(summary, ". ");
        }
    }
    strcpy(output, summary);
    free(summary);
}

int main() {
    char input[] = "The sun rose slowly over the horizon. It was a beautiful sight to behold. The sky turned orange and pink and the birds sang their morning songs. I sipped my coffee and smiled. It was going to be a great day. The cool breeze brushed my hair and I closed my eyes in contentment. Life was good.";
    char output[MAX_SUMMARY_LENGTH];
    summarize_text(input, output);
    printf("%s", output);
    return 0;
}