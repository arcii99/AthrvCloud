//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int len, i, j, counter;
    float alpha_score, sentence_score[1000], total_score;
    char *sentence[1000];

    // Get input text
    printf("Enter your text:\n");
    fgets(text, 1000, stdin);

    // Calculate the length of the input text
    len = strlen(text);

    // Split the input text into sentences
    counter = 0;
    for (i = 0; i < len; i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence[counter] = &text[i+1];
            text[i+1] = '\0';
            counter++;
        }
    }

    // Calculate the score of each sentence
    for (i = 0; i < counter; i++) {
        alpha_score = 0;
        for (j = 0; j < strlen(sentence[i]); j++) {
            if ((sentence[i][j] >= 'a' && sentence[i][j] <= 'z') || (sentence[i][j] >= 'A' && sentence[i][j] <= 'Z')) {
                alpha_score++;
            }
        }
        sentence_score[i] = alpha_score / strlen(sentence[i]);
    }

    // Calculate the total score of the input text
    total_score = 0;
    for (i = 0; i < counter; i++) {
        total_score += sentence_score[i];
    }

    // Print the most important sentences
    printf("The summary of your text is:\n");
    printf("----------------------------------\n");
    for (i = 0; i < counter; i++) {
        if (sentence_score[i] > (total_score/counter)) {
            printf("%s.\n", sentence[i]);
        }
    }
    printf("----------------------------------\n");

    return 0;
}