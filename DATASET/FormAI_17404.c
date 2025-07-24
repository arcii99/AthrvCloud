//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 30
#define MAX_ATTR_LENGTH 20
#define MAX_ATTR_COUNT 10
#define MAX_TEXT_LENGTH 100

void parse_node(char*);
void parse_attr(char*, char*, char*);

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: ./xml_parser <file_name>\n");
        return 0;
    }

    char* file_name = argv[1];
    FILE* xml_file = fopen(file_name, "r");

    if(xml_file == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    char line[100];
    while(fgets(line, sizeof(line), xml_file)) {
        // Check if line contains a tag
        if(line[0] == '<') {
            parse_node(line);
        }
    }

    fclose(xml_file);
    return 0;
}

void parse_node(char* node) {
    // Extract tag name
    char tag[MAX_TAG_LENGTH];
    int len = strlen(node);
    int i = 1, j = 0;
    while(i < len && node[i] != ' ' && node[i] != '>') {
        tag[j++] = node[i++];
    }
    tag[j] = '\0';

    // Extract attributes if any
    char* attr_start = NULL;
    char* attr_end = NULL;
    char attr[MAX_ATTR_COUNT][MAX_ATTR_LENGTH];
    int attr_count = 0;

    while(i < len && node[i] != '>') {
        // Find start of an attribute
        if(node[i] != ' ' && attr_start == NULL) {
            attr_start = &node[i];
        }

        // Find end of an attribute
        if((node[i] == ' ' || node[i] == '=') && attr_start != NULL) {
            attr_end = &node[i-1];
            parse_attr(attr[attr_count], attr_start, attr_end);
            attr_count++;
            attr_start = NULL;
        }
        i++;
    }

    // Extract text if any
    char text[MAX_TEXT_LENGTH];
    i++; // skip '>'
    j = 0;
    while(i < len && node[i] != '<' && j < MAX_TEXT_LENGTH) {
        text[j++] = node[i++];
    }
    text[j] = '\0';

    // Print parsed node
    printf("Tag: %s\n", tag);
    for(i=0; i<attr_count; i++) {
        printf("Attribute %d: %s\n", i+1, attr[i]);
    }
    printf("Text: %s\n", text);
}

void parse_attr(char* dest, char* src_start, char* src_end) {
    int j = 0;
    while(src_start <= src_end) {
        dest[j++] = *src_start++;
    }
    dest[j] = '\0';
}