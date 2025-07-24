//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 2048

typedef struct {
    char tag[32];
    char attributes[64];
} tag_t;

void parseXML(char *xml) {
    int i = 0, j = 0;
    tag_t tag;
    memset(&tag, 0, sizeof(tag_t));

    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            j = 0;
            while (xml[i] != '>') {
                if (xml[i] == ' ') {
                    memset(&tag.attributes, 0, sizeof(tag.attributes));
                    j = 0;
                } else if (xml[i] == '=') {
                    i++;
                    tag.attributes[j] = '=';
                    j++;
                    while (xml[i] != ' ' && xml[i] != '>') {
                        tag.attributes[j] = xml[i];
                        j++;
                        i++;
                    }
                    i--;
                } else {
                    tag.tag[j] = xml[i];
                    j++;
                }
                i++;
            }

            printf("Tag: %s, Attributes: %s\n", tag.tag, tag.attributes);
            memset(&tag, 0, sizeof(tag_t));
        }

        i++;
    }
}

int main() {
    char xml[MAX_CHARACTERS];

    printf("Enter an XML string:\n");
    fgets(xml, MAX_CHARACTERS, stdin);

    parseXML(xml);

    return 0;
}