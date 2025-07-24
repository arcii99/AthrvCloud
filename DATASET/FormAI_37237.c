//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>

#define WINDOW_SIZE 4096
#define BUFFER_SIZE 17

void compress(FILE *input, FILE *output) {
    unsigned char window[WINDOW_SIZE];
    unsigned char buffer[BUFFER_SIZE];
    int window_pos = 0;
    int buffer_pos = 1;
    int buffer_len = 0;
    int match_pos = 0;
    int match_len = 0;
    int c;

    while ((c = getc(input)) != EOF) {
        buffer[buffer_pos] = c;
        buffer_len++;
        match_pos = window_pos;
        match_len = 0;

        for (int i = 0; i < buffer_len; i++) {
            int j = 0;
            
            while (j < WINDOW_SIZE && window[(window_pos + j) % WINDOW_SIZE] == buffer[(buffer_pos + i) % BUFFER_SIZE]) {
                j++;
            }
            
            if (j > match_len) {
                match_pos = (window_pos + j) % WINDOW_SIZE;
                match_len = j;
            }
        }
        
        if (match_len > 2) {
            fprintf(output, "<%d,%d>", match_pos, match_len);
            
            for (int i = 0; i < match_len; i++) {
                window[(window_pos + i) % WINDOW_SIZE] = buffer[(buffer_pos + i) % BUFFER_SIZE];
            }
            
            window_pos = (window_pos + match_len) % WINDOW_SIZE;
            buffer_pos = (buffer_pos + match_len) % BUFFER_SIZE;
            buffer_len -= match_len;
        } else {
            putc(buffer[buffer_pos], output);
            window[window_pos] = buffer[buffer_pos];
            window_pos = (window_pos + 1) % WINDOW_SIZE;
            buffer_pos = (buffer_pos + 1) % BUFFER_SIZE;
            buffer_len--;
        }
    }
    
    while (buffer_len > 1) {
        putc(buffer[buffer_pos], output);
        window[window_pos] = buffer[buffer_pos];
        window_pos = (window_pos + 1) % WINDOW_SIZE;
        buffer_pos = (buffer_pos + 1) % BUFFER_SIZE;
        buffer_len--;
    }
    
    if (buffer_len == 1) {
        putc(buffer[buffer_pos], output);
    }
}

int main(int argc, char *argv[]) {
    FILE *input;
    FILE *output;
    
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }
    
    input = fopen(argv[1], "rb");
    
    if (input == NULL) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        return 1;
    }
    
    output = fopen(argv[2], "wb");
    
    if (output == NULL) {
        printf("Error: Could not open output file '%s'\n", argv[2]);
        fclose(input);
        return 1;
    }
    
    compress(input, output);
    
    fclose(input);
    fclose(output);
    
    return 0;
}