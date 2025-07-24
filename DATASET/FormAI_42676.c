//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTRIBUTE_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char tag[MAX_TAG_LENGTH];
    char attribute[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_VALUE_LENGTH];
} xml_element;

xml_element* parse_xml(const char* filename, size_t* element_count);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    size_t count;
    xml_element* elements = parse_xml(argv[1], &count);

    for (size_t i = 0; i < count; i++) {
        printf("<%s %s=\"%s\"/>\n", elements[i].tag, elements[i].attribute, elements[i].value);
    }

    free(elements);

    return 0;
}

xml_element* parse_xml(const char* filename, size_t* element_count) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }

    size_t line_size = 1024;
    char* line = (char*)malloc(line_size);

    if (line == NULL) {
        printf("Failed to allocate memory for line buffer\n");
        fclose(fp);
        return NULL;
    }

    size_t count = 0;
    xml_element* elements = (xml_element*)malloc(sizeof(xml_element));

    if (elements == NULL) {
        printf("Failed to allocate memory for elements\n");
        free(line);
        fclose(fp);
        return NULL;
    }

    while (fgets(line, line_size, fp)) {
        char tag[MAX_TAG_LENGTH];
        char attribute[MAX_ATTRIBUTE_LENGTH];
        char value[MAX_VALUE_LENGTH];
        bool tag_complete = false;
        bool attribute_complete = false;

        size_t i = 0;
        size_t tag_length = 0;
        size_t attribute_length = 0;
        size_t value_length = 0;

        while (i < strlen(line)) {
            char c = line[i];

            if (c == '<') {
                tag_complete = false;
                attribute_complete = false;
                tag_length = 0;
                attribute_length = 0;
                value_length = 0;
            }
            else if (c == ' ' && !tag_complete && !attribute_complete) {
                tag[tag_length] = '\0';
                tag_complete = true;
            }
            else if (c == '=' && tag_complete && !attribute_complete) {
                attribute[attribute_length] = '\0';
                attribute_complete = true;
            }
            else if (c == '\"' && attribute_complete) {
                value_length = 0;

                for (size_t j = i + 1; j < strlen(line); j++) {
                    char d = line[j];

                    if (d == '\"') {
                        value[value_length] = '\0';
                        i = j;
                        break;
                    }
                    else {
                        value[value_length] = d;
                        value_length++;
                    }
                }

                xml_element* new_elements = (xml_element*)realloc(elements, (count + 1) * sizeof(xml_element));

                if (new_elements == NULL) {
                    printf("Failed to allocate memory for new elements\n");
                    free(line);
                    fclose(fp);

                    for (size_t j = 0; j < count; j++) {
                        free(elements[j].tag);
                        free(elements[j].attribute);
                        free(elements[j].value);
                    }

                    free(elements);

                    return NULL;
                }

                elements = new_elements;

                strcpy(elements[count].tag, tag);
                strcpy(elements[count].attribute, attribute);
                strcpy(elements[count].value, value);

                count++;

                tag_complete = false;
                attribute_complete = false;
            }
            else {
                if (!tag_complete) {
                    tag[tag_length] = c;
                    tag_length++;
                }
                else if (tag_complete && !attribute_complete) {
                    attribute[attribute_length] = c;
                    attribute_length++;
                }
            }

            i++;
        }
    }

    *element_count = count;

    free(line);
    fclose(fp);

    return elements;
}