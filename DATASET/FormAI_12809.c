//FormAI DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <string.h>
#include <stdio.h>

#define MAX_SENTENCES 10

int is_vowel(char c) {
    // Returns true if the given character is a vowel.
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
}

int count_sentences(char* text) {
    // Counts the number of sentences in the given text by counting the number of periods.
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.') {
            sentence_count++;
        }
    }
    return sentence_count;
}

void summarize_text(char* text) {
    // Given some text as input, summarizes it by printing the first sentence of each paragraph.
    int sentences[MAX_SENTENCES];
    int current_sentence = 0;
    // Find the position of the first sentence in each paragraph.
    for (int i = 0; i < strlen(text); i++) {
        if (i > 0 && text[i] == '\n' && text[i-1] == '\n') {
            sentences[current_sentence] = i+1;
            current_sentence++;
        }
    }
    // Print the first sentence of each paragraph.
    for (int i = 0; i < current_sentence; i++) {
        int sentence_start = sentences[i];
        int sentence_end = strlen(text);
        // Find the end of the sentence.
        for (int j = sentence_start; j < strlen(text); j++) {
            if (text[j] == '.') {
                sentence_end = j+1;
                break;
            }
        }
        // Print the sentence.
        printf("%.*s", sentence_end - sentence_start, &text[sentence_start]);
    }
}

int main() {
    char* text = "Once upon a time, there was a little boy named Jack. He lived in a small village at the foot of a hill. Jack loved to play outside in the sunshine and he would often spend hours exploring the fields and woods around his home.\n\nOne day, Jack decided to climb the hill that loomed above the village. It was a steep climb, but he was determined to reach the top. As he climbed, he could feel his heart pounding in his chest and his legs growing tired. But he kept on going, one step at a time.\n\nAt last, he reached the top of the hill and looked out over the valley below. It was a beautiful sight, with the sun shining down on the fields and the trees swaying gently in the breeze. Jack felt a sense of accomplishment wash over him, and he knew that he would always remember this day.";

    printf("Original Text:\n%s\n\n", text);
    printf("Summarized Text:\n");
    summarize_text(text);

    return 0;
}