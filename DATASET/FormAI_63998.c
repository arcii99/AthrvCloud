//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return -1;
    }

    char line[256];

    while(fgets(line, sizeof(line), file)) {
        if(strstr(line, "//") != NULL) {
            char *metadata = strstr(line, "//") + 2;
            printf("%s\n", metadata);
        }
    }

    fclose(file);

    return 0;
}