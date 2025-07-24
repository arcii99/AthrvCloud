//FormAI DATASET v1.0 Category: Text processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    char word[100];
    int word_count = 0;
    printf("Enter some text: ");
    fgets(text, 1000, stdin);
    printf("Enter a word to search for: ");
    scanf("%s", word);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            word_count++;
        }
        if (strstr(text + i, word) == text + i) {
            printf("Found at index %d\n", i);
            printf("Surrounding text:\n");
            int start_index = i;
            int end_index = i;
            while (text[start_index] != ' ' && text[start_index] != '\n' && start_index >= 0) {
                start_index--;
            }
            if (start_index < 0) {
                start_index = 0;
            } else {
                start_index++;
            }
            while (text[end_index] != ' ' && text[end_index] != '\n' && text[end_index] != '\0') {
                end_index++;
            }
            for (int j = start_index; j < end_index; j++) {
                printf("%c", text[j]);
            }
            printf("\n");
        }
    }
    printf("Word count = %d\n", word_count);
    return 0;
}