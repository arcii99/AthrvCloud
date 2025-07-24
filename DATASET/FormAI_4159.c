//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct stack {
    char data[BUFFER_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top >= BUFFER_SIZE) {
        fprintf(stderr, "Error: Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[s->top++] = c;
}

char pop(Stack *s) {
    if (s->top <= 0) {
        fprintf(stderr, "Error: Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[--s->top];
}

void compress(char *input_filename, char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open input file\n");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error: Could not open output file\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    Stack s;
    s.top = 0;

    char buffer[BUFFER_SIZE];
    int buffer_index = 0;

    int c = fgetc(input_file);
    while (c != EOF) {
        buffer[buffer_index++] = c;
        if (buffer_index == BUFFER_SIZE) {
            for (int i = 0; i < buffer_index; i++) {
                push(&s, buffer[i]);
            }
            buffer_index = 0;
        }

        if (buffer_index == 1) {
            char prev_char = buffer[buffer_index-1];
            char next_char = fgetc(input_file);

            if (next_char == EOF) {
                fprintf(output_file, "%d%c", 1, prev_char);
                break;
            }

            if (prev_char != next_char) {
                fprintf(output_file, "%d%c", 1, prev_char);
            } else {
                int count = 1;
                while (next_char == prev_char) {
                    count++;
                    if (count > 9) {
                        fprintf(output_file, "%d%c", count, prev_char);
                        count = 0;
                    }
                    prev_char = next_char;
                    next_char = fgetc(input_file);
                    if (next_char == EOF) {
                        count++;
                        break;
                    }
                }
                fprintf(output_file, "%d%c", count, prev_char);
                buffer_index = 0;
                continue;
            }
        }
        c = fgetc(input_file);
    }

    for (int i = 0; i < buffer_index; i++) {
        push(&s, buffer[i]);
    }

    while (s.top > 0) {
        fprintf(output_file, "01%c", pop(&s));
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    compress(argv[1], argv[2]);

    return 0;
}