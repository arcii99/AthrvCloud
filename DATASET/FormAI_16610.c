//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int extract_metadata(const char *filename, char *metadata) {
    FILE *file = fopen(filename, "r");
    char c, last_c = '\0';
    int i = 0, in_comment = 0, in_metadata = 0;

    if (file == NULL)
        return -1;

    while ((c = fgetc(file)) != EOF && in_metadata < 50) {
        if (in_comment) {
            if (last_c == '*' && c == '/')
                in_comment = 0;
        }
        else {
            if (last_c == '/' && c == '*')
                in_comment = 1;
            else if (!in_metadata && c == '@')
                in_metadata = 1;
            else if (in_metadata && c == '\n')
                in_metadata = 0;
            else if (in_metadata)
                metadata[i++] = c;
        }
        last_c = c;
    }
    metadata[i] = '\0';
    fclose(file);

    return in_metadata ? -2 : i;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char metadata[51] = "";
    int length = extract_metadata(argv[1], metadata);

    if (length == -1)
        fprintf(stderr, "Could not open file %s\n", argv[1]);
    else if (length == -2)
        fprintf(stderr, "Metadata exceeds 50 characters\n");
    else if (length > 0)
        printf("%s\n", metadata);
    else
        printf("No metadata found in %s\n", argv[1]);

    return 0;
}