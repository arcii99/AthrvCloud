//FormAI DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void summarize(char text[]) {
    char keywords[20][20] = {"love", "heart", "romance", "passion", "kiss", "sweetheart", "forever", "adore", "cherish", "devotion"};
    int frequency[20] = {0};
    int i, j, count = 0;
    char sentence[100][100], word[20], *ptr, summary[1000];

    // Convert text to lowercase
    for(i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Split text into sentences
    ptr = strtok(text, ".!?");
    while(ptr != NULL) {
        strcpy(sentence[count], ptr);
        count++;
        ptr = strtok(NULL, ".!?");
    }

    // Check for keywords in each sentence
    for(i = 0; i < count; i++) {
        ptr = strtok(sentence[i], " ,;:");
        while(ptr != NULL) {
            strcpy(word, ptr);
            for(j = 0; j < 10; j++) {
                if(strcmp(word, keywords[j]) == 0) {
                    frequency[j]++;
                }
            }
            ptr = strtok(NULL, " ,;:");
        }
    }

    // Create the summary
    strcpy(summary, "");
    for(i = 0; i < count; i++) {
        for(j = 0; j < 10; j++) {
            if(frequency[j] != 0 && strstr(sentence[i], keywords[j])) {
                strcat(summary, sentence[i]);
                strcat(summary, ". ");
                break;
            }
        }
    }

    // Print the summary
    printf("Here is your Romantic Text Summary: \n\n");
    printf("%s\n", summary);

}

int main() {
    char text[1000];

    printf("Enter your romantic text: \n\n");
    fgets(text, 1000, stdin);

    summarize(text);

    return 0;
}