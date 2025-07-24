//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

typedef struct {
    char sentence[200];
    int sentence_len;
    int sentence_id;
    float tf_idf_score;
} Sentence;

int cmp_sentence_score(const void* a, const void* b) {
    float diff = ((Sentence*)b)->tf_idf_score - ((Sentence*)a)->tf_idf_score;
    if (diff > 0) {
        return 1;
    } else if (diff == 0) {
        return 0;
    } else {
        return -1;
    }
}

float compute_tf_idf_score(char word[], char** sentences, int num_sentences) {
    int num_occurences = 0;

    for (int i = 0; i < num_sentences; i++) {
        if (strstr(sentences[i], word) != NULL) {
            num_occurences++;
        }
    }

    float tf = (float)num_occurences / num_sentences;
    float idf = log10((float)num_sentences / num_occurences);
    return tf * idf;
}

void summarize(char** sentences, int num_sentences) {
    Sentence summarized_sentences[num_sentences];
    int total_words = 0;

    for (int i = 0; i < num_sentences; i++) {
        int sentence_len = strlen(sentences[i]);
        total_words += sentence_len;

        Sentence new_sentence;
        strcpy(new_sentence.sentence, sentences[i]);
        new_sentence.sentence_len = sentence_len;
        new_sentence.sentence_id = i;
        new_sentence.tf_idf_score = 0;

        char split_sentence[sentence_len][20];
        int num_split_sentence_words = 0;

        char* token = strtok(sentences[i], " ");
        while (token != NULL && num_split_sentence_words < sentence_len) {
            strcpy(split_sentence[num_split_sentence_words], token);
            num_split_sentence_words++;
            token = strtok(NULL, " ");
        }

        for (int j = 0; j < num_split_sentence_words; j++) {
            float score = compute_tf_idf_score(split_sentence[j], sentences, num_sentences);
            new_sentence.tf_idf_score += score;
        }

        summarized_sentences[i] = new_sentence;
    }

    int avg_sentence_length = total_words / num_sentences;
    int num_summary_sentences = MAX_SUMMARY_LENGTH / avg_sentence_length;

    qsort(summarized_sentences, num_sentences, sizeof(Sentence), cmp_sentence_score);

    for (int i = 0; i < num_summary_sentences; i++) {
        printf("%s", summarized_sentences[i].sentence);
    }
}

int main() {
    char* sentences[] = {
        "This is the first sentence. It is a simple sentence.",
        "This is the second sentence. It is slightly longer than the first sentence.", 
        "This is the third sentence. It is the longest sentence in the paragraph.",
        "This is the fourth sentence. It is a short sentence.",
        "This is the fifth sentence. It is a medium length sentence with a few words."
    };

    summarize(sentences, 5);
    
    return 0;
}