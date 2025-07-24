//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int parseXML(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_SIZE];
    int i = 0, len = 0, count = 0, tag_start = 0, attr_start = 0, attr_end = 0, value_start = 0;

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    while (fgets(buffer, MAX_SIZE, file)) {
        len = strlen(buffer);
        i = 0;

        while (i < len) {
            if (buffer[i] == '<') {
                tag_start = i + 1;
            } else if (buffer[i] == '>' && tag_start < i) {
                printf("Tag: %.*s\n", i - tag_start, buffer + tag_start);
                count++;
            } else if (buffer[i] == ' ' && tag_start < i) {
                attr_start = tag_start;
                attr_end = i;
                printf("Attribute: %.*s\n", attr_end - attr_start, buffer + attr_start);

                if (buffer[i+1] == '"') {
                    value_start = i+2;
                } else {
                    value_start = i+1;
                }

                while (buffer[i] != '"' && i < len) {
                    i++;
                }

                printf("Value: %.*s\n", i - value_start, buffer + value_start);
            }

            i++;
        }
    }

    fclose(file);
    return count;
}

int main() {
    char *filename = "example.xml";
    int count = parseXML(filename);
    printf("Number of tags: %d\n", count);
    return 0;
}