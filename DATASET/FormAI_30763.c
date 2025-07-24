//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1024
#define MAX_TAGS 32

struct XMLTag {
    char* name;
    char* value;
    struct XMLTag* subtags[MAX_TAGS];
};

typedef struct XMLTag XMLTag;

void removeLeadingWhitespace(char* str) {
    int len = strlen(str);
    int i = 0;

    while (i < len && (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')) {
        i++;
    }

    memmove(str, str + i, len - i + 1);
}

int parseTag(char* buffer, int idx, XMLTag** tag) {
    int len = strlen(buffer) - idx;

    if (len == 0 || buffer[idx] != '<') {
        return -1;
    }

    int tagStartIdx = idx + 1;
    int tagEndIdx = -1;

    // check if it's a closing tag
    if (buffer[tagStartIdx] == '/') {
        while (buffer[idx] != '>') {
            idx++;
        }

        tagEndIdx = idx;
    } 
    // otherwise it's an opening tag
    else {
        while (buffer[idx] != '>' && buffer[idx] != ' ' && idx < len) {
            idx++;
        }

        tagEndIdx = idx;

        // create the tag object
        *tag = malloc(sizeof(XMLTag));
        (*tag)->name = malloc(tagEndIdx - tagStartIdx + 1);
        (*tag)->value = NULL;

        strncpy((*tag)->name, buffer + tagStartIdx, tagEndIdx - tagStartIdx);
        (*tag)->name[tagEndIdx - tagStartIdx] = '\0';

        int subtagIdx = 0;

        // check for subtags
        while (idx < len && buffer[idx] != '>') {
            subtagIdx++;

            // create the subtag object
            XMLTag* subtag = NULL;
            idx = parseTag(buffer, idx, &subtag);

            // add the subtag to the parent tag
            if (subtag != NULL) {
                (*tag)->subtags[subtagIdx] = subtag;
            }
        }
    }

    return tagEndIdx;
}

void printXMLTag(XMLTag* tag, int level) {
    if (tag == NULL) {
        return;
    }

    // print the tag name
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("<%s", tag->name);

    // print any subtags
    for (int i = 0; i < MAX_TAGS; i++) {
        if (tag->subtags[i] != NULL) {
            printf("\n");
            printXMLTag(tag->subtags[i], level + 1);
        }
    }

    // print the tag value
    if (tag->value != NULL) {
        printf("%s", tag->value);
    }

    // end the tag
    if (tag->subtags[0] == NULL) {
        printf("/>\n");
    } else {
        printf("\n");

        for (int i = 0; i < level; i++) {
            printf("  ");
        }

        printf("</%s>\n", tag->name);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // read the file into a string buffer
    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char buffer[MAX_CHARS + 1];
    memset(buffer, 0, MAX_CHARS + 1);
    fread(buffer, 1, MAX_CHARS, file);
    fclose(file);

    // remove all leading whitespace
    removeLeadingWhitespace(buffer);

    // parse the XML
    XMLTag* root = NULL;
    parseTag(buffer, 0, &root);

    // print the parsed XML
    printXMLTag(root, 0);

    // free the memory allocated for the XML
    free(root->name);
    free(root);

    return 0;
}