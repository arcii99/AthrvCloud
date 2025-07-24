//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress(char* input_string) {
    int length = strlen(input_string);
    char* compressed_string = (char*) malloc(sizeof(char) * (length + 1));
    int compressed_index = 0;
    int current_count = 1;
    char current_char = input_string[0];

    for (int i = 1; i < length + 1; i++) {
        if (input_string[i] == current_char) {
            current_count++;
        } else {
            compressed_string[compressed_index++] = current_char;
            char count_char[10];
            memset(count_char, 0, sizeof(count_char));
            sprintf(count_char, "%d", current_count);
            strcat(compressed_string, count_char);
            compressed_index += strlen(count_char);
            current_count = 1;
            current_char = input_string[i];
        }
    }

    compressed_string[compressed_index] = '\0';

    return compressed_string;
}

int main() {
    char input_string[100];
    printf("Enter a string to be compressed:\n");
    scanf("%[^\n]s", input_string);
    getchar();
    printf("\n");

    char* compressed_string = compress(input_string);
    printf("Compressed String:\n%s\n", compressed_string);

    free(compressed_string);

    return 0;
}