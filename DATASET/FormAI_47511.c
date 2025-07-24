//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <string.h>

typedef struct Token {
    int type;       // 0 for HTML tag, 1 for content
    char value[100];  // max tag length
} Token;

int is_special_char(char c) {
    return (c == '<' || c == '>');
}

void process_content(char *content, Token *tokens, int *tokens_size) {
    if (strlen(content) == 0) {
        return;
    }

    Token new_token;
    new_token.type = 1;
    strcpy(new_token.value, content);

    tokens[*tokens_size] = new_token;
    *tokens_size = *tokens_size + 1;
}

int main() {
    printf("Enter the HTML code to beautify:\n");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    Token tokens[1000];
    int tokens_size = 0;

    int in_tag = 0;
    char current_tag[100];
    int current_tag_length = 0;
    char current_content[100];
    int current_content_length = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        if (!in_tag && is_special_char(c)) {
            process_content(current_content, tokens, &tokens_size);

            current_content[0] = '\0';
            current_content_length = 0;

            current_tag[0] = c;
            current_tag_length = 1;

            in_tag = 1;
        } else if (in_tag && c == '>') {
            current_tag[current_tag_length] = c;
            current_tag_length++;

            process_content(current_content, tokens, &tokens_size);

            current_content[0] = '\0';
            current_content_length = 0;

            Token new_token;
            new_token.type = 0;
            strcpy(new_token.value, current_tag);

            tokens[tokens_size] = new_token;
            tokens_size++;

            current_tag[0] = '\0';
            current_tag_length = 0;

            in_tag = 0;
        } else if (in_tag) {
            current_tag[current_tag_length] = c;
            current_tag_length++;
        } else {
            current_content[current_content_length] = c;
            current_content_length++;
        }
    }

    // Output the beautified HTML
    for (int i = 0; i < tokens_size; i++) {
        if (tokens[i].type == 0) {
            printf("\n%s\n", tokens[i].value);
        } else {
            printf("%s", tokens[i].value);
        }
    }

    return 0;
}