//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char data[100];
    int size;
} Message;

typedef struct {
    char *data;
    int size;
} Watermark;

int main() {
    Message m;
    printf("Enter your message:\n");
    fgets(m.data, 100, stdin);
    m.size = strlen(m.data);

    Watermark w;
    w.size = 10;
    w.data = (char *) malloc(sizeof(char) * w.size);
    printf("Enter your watermark:\n");
    fgets(w.data, w.size, stdin);

    char *new_data = (char *) malloc(sizeof(char) * (m.size + w.size + 1));
    int i, j;
    for (i = 0; i < m.size; i++) {
        new_data[i] = m.data[i];
    }
    for (j = 0; j < w.size; j++, i++) {
        new_data[i] = w.data[j];
    }
    new_data[i] = '\0';

    printf("Watermarking process completed.\n");
    printf("Your original message was: %s\n", m.data);
    printf("Your new message with watermark is: %s\n", new_data);

    return 0;
}