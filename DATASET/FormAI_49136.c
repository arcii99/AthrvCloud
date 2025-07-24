//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
#include <stdio.h>

int main() {

    char *code = "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}";

    char c;
    int i = 0;
    int tabs = 0;

    while ((c = code[i]) != NULL) {

        if (c == '\n') {
            printf("%c", c);

            for (int j = 0; j < tabs; j++) {
                printf("\t");
            }
        }
        else if (c == '{') {
            printf("{\n");
            tabs++;

            for (int j = 0; j < tabs; j++) {
                printf("\t");
            }
        }
        else if (c == '}') {
            printf("\n");

            tabs--;

            for (int j = 0; j < tabs; j++) {
                printf("\t");
            }

            printf("}\n");

            if (code[i+1] == ';') {
                i++; // Skip semicolon after curly brace
            }

            for (int j = 0; j < tabs; j++) {
                printf("\t");
            }
        }
        else {
            printf("%c", c);
        }

        i++;
    }

    return 0;
}