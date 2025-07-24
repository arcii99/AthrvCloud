//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Enter an HTML filename to beautify.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file '%s'\n", argv[1]);
        return 1;
    }

    char line[1024];
    int depth = 0;
    while (fgets(line, 1024, file)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        // check if line starts with closing tag, and reduce depth if so
        if (line[0] == '<' && line[1] == '/') {
            depth--;
        }

        indent(depth);
        printf("%s\n", line);

        // check if line ends with an opening tag, and increase depth if so
        if (len > 2 && line[len-2] == '<' && line[len-1] != '/') {
            depth++;
        }
    }

    fclose(file);
    return 0;
}