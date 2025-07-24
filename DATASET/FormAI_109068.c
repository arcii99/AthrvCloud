//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>

#define MAX_SUMMARY_LENGTH 200

void summarize(char* input_text) {
    char summary[MAX_SUMMARY_LENGTH];
    int i, j, k;

    // Remove duplicate spaces and newlines
    for (i = 0, j = 0; input_text[i] != '\0'; i++) {
        if (!(input_text[i] == ' ' && (input_text[i+1] == ' ' || input_text[i+1] == '\n'))) {
            input_text[j++] = input_text[i];
        }
    }
    input_text[j] = '\0';

    // Start the summary with the first sentence
    k = 0;
    while (input_text[k] == '\n' || input_text[k] == ' ') k++;
    for (i = k, j = 0; input_text[i] != '\0' && j < MAX_SUMMARY_LENGTH; i++) {
        summary[j++] = input_text[i];
        if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            summary[j++] = '\n';
            while (input_text[i+1] == ' ') i++;
            while (input_text[i+1] == '\n') i++;
            break;
        }
    }
    summary[j] = '\0';

    // Add a maximum of 5 more sentences
    int num_added = 0;
    while (input_text[i] != '\0' && num_added < 5) {
        while (input_text[i] == ' ' || input_text[i] == '\n') i++;
        k = i;
        while (input_text[i] != '\0' && input_text[i] != '.' && input_text[i] != '?' && input_text[i] != '!') i++;
        if (input_text[i] != '\0') i++;
        for (j = k; j < i && num_added < 5 && j-k < MAX_SUMMARY_LENGTH; j++, num_added++) {
            summary[strlen(summary)] = input_text[j];
        }
        if (input_text[i] != '\0' && num_added < 5) {
            summary[strlen(summary)] = ' ';
        }
    }

    printf("%s", summary);
}

int main() {
    char input_text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed varius felis et nulla feugiat, ac suscipit elit pretium.\n\nSed aliquet suscipit mauris eget volutpat. Cras eget ultrices nisi. Duis eu sapien ut augue vestibulum pellentesque.\n\nSuspendisse potenti. Nunc sagittis, est a lobortis rutrum, sem justo posuere velit, eu blandit elit turpis eu metus.\n\nProin semper ipsum augue, ac sagittis erat suscipit ut. Praesent sit amet est a mauris ullamcorper malesuada a at urna. Pellentesque id ante nec nibh suscipit suscipit. Donec ut euismod tortor, vitae dapibus erat.";

    printf("Input text:\n%s\n\n", input_text);
    printf("Summary:\n");
    summarize(input_text);

    return 0;
}