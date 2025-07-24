//FormAI DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

void print_char(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

void center_text(char *text, int width) {
    int text_len = strlen(text);
    int padding = width - text_len;
    int left_pad = padding / 2;
    int right_pad = padding / 2;

    if (padding % 2 != 0) {
        right_pad++;
    }

    print_char(' ', left_pad);
    printf("%s", text);
    print_char(' ', right_pad);
    printf("\n");
}

int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    center_text(name, 30);
    printf("\n");

    char message[] = "Hello, welcome to my program!";
    center_text(message, 50);

    return 0;
}