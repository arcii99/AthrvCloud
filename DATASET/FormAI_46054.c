//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    char *name;
    int num_attributes;
    Attribute *attributes;
} Element;

typedef struct {
    int num_elements;
    Element *elements;
} XMLDocument;

int main() {
    char xml_string[] = "<root>\n  <person name=\"John Doe\" age=\"32\" />\n  <person name=\"Jane Smith\" age=\"28\" />\n</root>";
    XMLDocument doc;
    doc.num_elements = 0;
    doc.elements = NULL;

    char *token = strtok(xml_string, "<>\n");

    while (token != NULL) {
        if (token[0] == '/') {
            doc.num_elements--;
        } else {
            Element element;
            element.name = token;
            element.num_attributes = 0;
            element.attributes = NULL;

            char *attribute_token = strtok(NULL, "\"");
            while (attribute_token != NULL) {
                if (strcmp(attribute_token, " ") != 0 && strcmp(attribute_token, "\n") != 0) {
                    Attribute attribute;
                    attribute.name = attribute_token;
                    attribute.value = strtok(NULL, "\"");
                    element.num_attributes++;
                    element.attributes = realloc(element.attributes, element.num_attributes * sizeof(Attribute));
                    element.attributes[element.num_attributes - 1] = attribute;
                }
                attribute_token = strtok(NULL, "\"");
            }

            doc.num_elements++;
            doc.elements = realloc(doc.elements, doc.num_elements * sizeof(Element));
            doc.elements[doc.num_elements - 1] = element;
        }

        token = strtok(NULL, "<>\n");
    }

    printf("Parsed XML:\n");
    for (int i = 0; i < doc.num_elements; i++) {
        printf("%s\n", doc.elements[i].name);
        for (int j = 0; j < doc.elements[i].num_attributes; j++) {
            printf("  %s: %s\n", doc.elements[i].attributes[j].name, doc.elements[i].attributes[j].value);
        }
    }

    return 0;
}