//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>

char stack[100];
int top = -1;

void push(char ch) {
    if (top >= 99) printf("Stack overflow");
    else stack[++top] = ch;
}

char pop() {
    if (top < 0) printf("Stack underflow");
    else {
        char ch = stack[top];
        top--;
        return ch;
    }
}

int isWhiteSpace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') return 1;
    return 0;
}

int isDelimiter(char c) {
    switch (c) {
        case '{':
        case '}':
        case ';':
        case ',':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

void indent(int level) {
    for (int i = 0; i < level; i++) printf("    ");
}

int main() {
    FILE* inFile = fopen("input.html", "r");
    FILE* outFile = fopen("output.html", "w");

    char ch, prev = '\0', next = '\0', nextNext = '\0';
    int level = 0;
    while ((ch = fgetc(inFile)) != EOF) {
        if (ch == '<' && next != '/') {
            if (!isWhiteSpace(prev) && !isDelimiter(prev)) printf("\n");
            indent(level);
            printf("%c", ch);
            level++;
        }
        else if (ch == '>' && prev != '/') {
            printf("%c\n", ch);
            indent(level - 1);
        }
        else if (ch == '/' && prev == '<') {
            level--;
            printf("%c", ch);
        }
        else if (ch == '>' && next == '/') {
            printf("%c\n", ch);
            prev = pop();
            indent(level - 1);
        }
        else if (ch == '-' && next == '-') {
            while ((ch = fgetc(inFile)) != EOF && !(ch == '-' && next == '>')) {
                prev = ch;
                next = fgetc(inFile);
            }
        }
        else {
            printf("%c", ch);
        }

        if (!isWhiteSpace(ch) && !isDelimiter(ch)) push(ch);
        prev = ch;
        next = nextNext;
        nextNext = fgetc(inFile);
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}