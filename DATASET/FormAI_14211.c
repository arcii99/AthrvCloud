//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include<stdio.h>

void beautifyCode(char buffer[]) {
    int indent = 0;
    int i = 0;
    int newLine = 1;
    char currentChar;

    while(buffer[i] != '\0') {
        currentChar = buffer[i];

        if(currentChar == '{') {
            printf("{");
            printf("\n");
            indent++;
            newLine = 1;
        } else if (currentChar == '}') {
            printf("\n");
            indent--;
            for(int j = 0; j < indent; j++) {
                printf("\t");
            }
            printf("}");
            newLine = 1;
        } else if (currentChar == ';') {
            printf(";");
            printf("\n");
            newLine = 1;
        } else if (newLine == 1) {
            for(int j = 0; j < indent; j++) {
                printf("\t");
            }
            printf("%c", currentChar);
            newLine = 0;
        } else {
            printf("%c", currentChar);
        }

        i++;
    }
}

int main() {
    char buffer[] = "<html>      <body>        <h1>Heading</h1>        <p>Paragraph.</p>      </body>    </html>    ";
    beautifyCode(buffer);
    return 0;
}