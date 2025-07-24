//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTR_LENGTH 50
#define MAX_ATTR_COUNT 10
#define MAX_VALUE_LENGTH 100

typedef struct {
    char tag[MAX_TAG_LENGTH];
    char attrs[MAX_ATTR_COUNT][MAX_ATTR_LENGTH];
    char values[MAX_ATTR_COUNT][MAX_VALUE_LENGTH];
    int attr_count;
} xml_element;

void parse_xml(char* xml_content, xml_element* root_element);
void read_tag(FILE* fp, char* tag);
void read_attr(FILE* fp, char* attr_name, char* attr_value);
void read_value(FILE* fp, char* value);

int main() {
    char xml_content[] = "<xml><person name=\"John\" age=\"25\">Hello World!</person></xml>";

    xml_element root_element;
    parse_xml(xml_content, &root_element);

    printf("Root Element: %s\n", root_element.tag);
    printf("Element Attributes:\n");
    for(int i=0; i<root_element.attr_count; i++) {
        printf("%s=%s\n", root_element.attrs[i], root_element.values[i]);
    }
    printf("Element Value: %s\n", root_element.values[0]);

    return 0;
}

void parse_xml(char* xml_content, xml_element* root_element) {
    FILE* fp = fmemopen(xml_content, strlen(xml_content), "r");

    char tag[MAX_TAG_LENGTH];
    read_tag(fp, tag);

    strcpy(root_element->tag, tag);
    root_element->attr_count = 0;

    char c;
    while((c = fgetc(fp)) != EOF) {
        if(c == '<') {
            read_tag(fp, tag);

            if(tag[0] == '/') {
                // End of Element
                break;
            } else {
                // Nested Element
                xml_element nested_element;
                parse_xml(xml_content, &nested_element);

                strcpy(root_element->attrs[root_element->attr_count], nested_element.tag);
                strcpy(root_element->values[root_element->attr_count], "");
                root_element->attr_count++;
            }

        } else if(c == ' ') {
            // Read Attribute
            char attr_name[MAX_ATTR_LENGTH];
            char attr_value[MAX_VALUE_LENGTH];
            read_attr(fp, attr_name, attr_value);

            strcpy(root_element->attrs[root_element->attr_count], attr_name);
            strcpy(root_element->values[root_element->attr_count], attr_value);
            root_element->attr_count++;

        } else if(c == '>') {
            // Read Value
            char value[MAX_VALUE_LENGTH];
            read_value(fp, value);

            strcpy(root_element->values[0], value);
        }
    }

    fclose(fp);
}

void read_tag(FILE* fp, char* tag) {
    char c;
    int i = 0;

    while((c = fgetc(fp)) != EOF) {
        if(c == '>') {
            tag[i] = '\0';
            break;
        } else {
            tag[i] = c;
            i++;
        }
    }
}

void read_attr(FILE* fp, char* attr_name, char* attr_value) {
    char c;
    int i = 0;

    while((c = fgetc(fp)) != EOF) {
        if(c == '=') {
            attr_name[i] = '\0';
            i = 0;

            while((c = fgetc(fp)) != EOF) {
                if(c == '"' || c == '\'') {
                    // Read until closing quote
                    while((c = fgetc(fp)) != EOF) {
                        if(c == '"' || c == '\'') {
                            attr_value[i] = '\0';
                            return;
                        } else {
                            attr_value[i] = c;
                            i++;
                        }
                    }
                } else if(c == ' ') {
                    // Ignore spaces
                    continue;
                } else {
                    attr_value[i] = c;
                    i++;
                }
            }
        } else if(c == ' ') {
            attr_name[i] = '\0';
            return;
        } else {
            attr_name[i] = c;
            i++;
        }
    }
}

void read_value(FILE* fp, char* value) {
    char c;
    int i = 0;
    int inside_tag = 0;

    while((c = fgetc(fp)) != EOF) {
        if(c == '<') {
            inside_tag = 1;
        } else if(c == '>') {
            inside_tag = 0;
        } else if(!inside_tag) {
            value[i] = c;
            i++;
        }
    }

    value[i] = '\0';
}