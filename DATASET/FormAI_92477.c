//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LENGTH 100
#define MAX_ATTRIBUTE_LENGTH 100
#define MAX_VALUE_LENGTH 500

typedef struct {
    char tag[MAX_TAG_LENGTH];
    char attribute[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_VALUE_LENGTH];
} XMLTag;

typedef struct {
    int size;
    int capacity;
    XMLTag* tags;
} XMLTagList;

void initTagList(XMLTagList* list) {
    list->size = 0;
    list->capacity = 10;
    list->tags = (XMLTag*)malloc(sizeof(XMLTag) * list->capacity);
}

void pushTag(XMLTagList* list, XMLTag tag) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->tags = (XMLTag*)realloc(list->tags, sizeof(XMLTag) * list->capacity);
    }
    list->tags[list->size++] = tag;
}

void printTag(XMLTag tag) {
    printf("<%s %s=\"%s\" />\n", tag.tag, tag.attribute, tag.value);
}

void printTagList(XMLTagList* list) {
    for (int i = 0; i < list->size; i++) {
        printTag(list->tags[i]);
    }
}

XMLTag parseTag(char* tagString) {
    XMLTag tag;
    tag.attribute[0] = '\0';
    tag.value[0] = '\0';

    // Find tag name
    int i;
    for (i = 0; i < strlen(tagString); i++) {
        if (isspace(tagString[i])) break;
        tag.tag[i] = tagString[i];
    }
    tag.tag[i] = '\0';

    // Find attributes
    int attributeStart = i;
    while (i < strlen(tagString)) {
        char c = tagString[i];
        if (c == '=') {
            int j;
            for (j = i+1; j < strlen(tagString); j++) {
                if (tagString[j] == '\"') break;
                tag.attribute[j-i-1] = tagString[j];
            }
            tag.attribute[j-i-1] = '\0';
        }
        else if (c == '\"') {
            int j;
            for (j = i+1; j < strlen(tagString); j++) {
                if (tagString[j] == '\"') break;
                tag.value[j-i-1] = tagString[j];
            }
            tag.value[j-i-1] = '\0';
        }
        i++;
    }

    return tag;
}

XMLTagList parseXML(char* xmlString) {
    XMLTagList list;
    initTagList(&list);

    // Find and parse each tag
    int i = 0;
    while (i < strlen(xmlString)) {
        char c = xmlString[i];
        if (c == '<') {
            int tagStart = i+1;
            while (xmlString[i] != '>') i++;
            int tagEnd = i;
            XMLTag tag = parseTag(xmlString + tagStart);
            pushTag(&list, tag);
        }
        i++;
    }

    return list;
}

int main() {
    char* xml = "<note title=\"My Note\" body=\"This is a note.\" /><book title=\"My Book\" author=\"John Doe\" publisher=\"Penguin\" />";
    XMLTagList tags = parseXML(xml);
    printTagList(&tags);
    return 0;
}