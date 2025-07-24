//FormAI DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <ctype.h>

char *get_input(char *buffer, int buffer_size) {
    printf("Enter text:\n");
    fgets(buffer, buffer_size, stdin);
    return buffer;
}

int count_words(char *text) {
    int count = 0;
    int is_word = 0;
    while (*text) {
        if (isalnum(*text)) {
            if (!is_word) {
                count++;
                is_word = 1;
            }
        } else {
            is_word = 0;
        }
        text++;
    }
    return count;
}

int main() {
    char input_buffer[1024];
    char *text = get_input(input_buffer, sizeof(input_buffer));
    int count = count_words(text);
    printf("Word count: %d\n", count);
    return 0;
}