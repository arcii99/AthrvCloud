//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char tag[MAX_STRING_LENGTH];
    char attributes[MAX_STRING_LENGTH];
    char value[MAX_STRING_LENGTH];
} Element;

void parseXML(char* xml, Element* elements, int* num_elements) {
    char* start_tag = NULL;
    char* end_tag = NULL;
    char* attr_start = NULL;
    char* attr_end = NULL;
    char* value_start = NULL;
    char* value_end = NULL;
    char tmp[MAX_STRING_LENGTH];
    int i = 0;
    while (*xml != '\0') {
        if (*xml == '<') {
            start_tag = xml + 1;
            end_tag = strchr(xml, '>');
            if (end_tag == NULL) {
                printf("Invalid XML!\n");
                return;
            }
            *end_tag = '\0';
            if (*start_tag == '/') {
                // closing element
                i--;
            } else {
                // opening element
                strcpy(elements[i].tag, start_tag);
                elements[i].attributes[0] = '\0';
                elements[i].value[0] = '\0';
                attr_start = start_tag;
                while ((attr_start = strchr(attr_start, ' ')) != NULL) {
                    attr_start++;
                    attr_end = strchr(attr_start, '=');
                    if (attr_end == NULL) {
                        break;
                    }
                    *attr_end = '\0';
                    strcpy(tmp, attr_start);
                    strcat(elements[i].attributes, tmp);
                    strcat(elements[i].attributes, ": ");
                    attr_start = attr_end + 2;
                    if (*attr_start == '"') {
                        attr_start++;
                        value_start = attr_start;
                        value_end = strchr(attr_start, '"');
                        if (value_end == NULL) {
                            break;
                        }
                        *value_end = '\0';
                        strcpy(elements[i].value, value_start);
                    }
                }
                i++;
            }
            xml = end_tag + 1;
        } else {
            xml++;
        }
    }
    *num_elements = i;
}

int main() {
    char xml[] = "<root><person name=\"John\" age=\"42\" /><person name=\"Jane\" age=\"39\" /></root>";
    Element elements[MAX_STRING_LENGTH];
    int num_elements = 0;
    parseXML(xml, elements, &num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d:\n", i + 1);
        printf("Tag: %s\n", elements[i].tag);
        if (strlen(elements[i].attributes) > 0) {
            printf("Attributes: %s\n", elements[i].attributes);
        }
        if (strlen(elements[i].value) > 0) {
            printf("Value: %s\n", elements[i].value);
        }
        printf("\n");
    }
    return 0;
}