//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 50
#define MAX_ELEMENTS 100

typedef struct {
    char type[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
} Element;

typedef struct {
    Element elements[MAX_ELEMENTS];
    int count;
} XML;

int parseXML(char* filename, XML* xml) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    char buffer[MAX_ELEMENT_SIZE];
    int i = 0;
    int j = 0;

    while (fgets(buffer, MAX_ELEMENT_SIZE, file)) {
        i = 0;

        while (buffer[i] != '<' && i < MAX_ELEMENT_SIZE) {
            i++;
        }

        if (buffer[i] == '<') {
            j = i + 1;

            while (buffer[j] != '>' && j < MAX_ELEMENT_SIZE) {
                j++;
            }

            if (buffer[j] == '>') {
                strncpy(xml->elements[xml->count].type, buffer + i + 1, j - i - 1);
                xml->elements[xml->count].type[j - i - 1] = '\0';

                i = j + 1;
                j = i;

                while (buffer[j] != '<' && j < MAX_ELEMENT_SIZE) {
                    j++;
                }

                if (buffer[j] == '<') {
                    strncpy(xml->elements[xml->count].value, buffer + i , j - i);
                    xml->elements[xml->count].value[j - i] = '\0';
                    xml->count++;
                }
            }
        }
    }

    fclose(file);
    return 0;
}

int main() {
    XML xml;
    xml.count = 0;

    if(parseXML("example.xml", &xml) != 0) {
        return 1;
    }

    for(int i = 0; i < xml.count; i++) {
        printf("Element type: %s, Element value: %s\n", xml.elements[i].type, xml.elements[i].value);
    }

    return 0;
}