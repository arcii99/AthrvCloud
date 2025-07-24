//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_ATTRIBUTES 10
#define MAX_ATTRIBUTE_NAME 50
#define MAX_ATTRIBUTE_VALUE 100

typedef struct {
    char name[MAX_ATTRIBUTE_NAME];
    char value[MAX_ATTRIBUTE_VALUE];
} attribute;

typedef struct {
    char name[MAX_TAG_NAME];
    attribute attributes[MAX_TAG_ATTRIBUTES];
    int attribute_count;
} tag;

void parse_tag(char* tag_str, tag* t) {
    char* ptr = tag_str;
    char name[MAX_TAG_NAME];
    int i;

    while (*ptr && isspace(*ptr)) ptr++; // skip leading whitespace

    // extract tag name
    for (i = 0; *ptr && !isspace(*ptr) && *ptr != '>'; i++) {
        name[i] = *ptr++;
    }
    name[i] = '\0';
    strcpy(t->name, name);

    // extract attributes
    while (*ptr != '>') {
        char attribute_name[MAX_ATTRIBUTE_NAME];
        char attribute_value[MAX_ATTRIBUTE_VALUE];

        while (*ptr && isspace(*ptr)) ptr++; // skip leading whitespace

        // extract attribute name
        for (i = 0; *ptr && *ptr != '=' && !isspace(*ptr); i++) {
            attribute_name[i] = *ptr++;
        }
        attribute_name[i] = '\0';

        while (*ptr && isspace(*ptr)) ptr++; // skip whitespace

        if (*ptr == '=') {
            ptr++;

            while (*ptr && isspace(*ptr)) ptr++; // skip whitespace

            // extract attribute value
            if (*ptr == '"') {
                ptr++;
                for (i = 0; *ptr && *ptr != '"'; i++) {
                    attribute_value[i] = *ptr++;
                }
                attribute_value[i] = '\0';

                while (*ptr && *ptr != '>') ptr++; // skip remaining junk
            }
        }

        // append attribute to tag
        strcpy(t->attributes[t->attribute_count].name, attribute_name);
        strcpy(t->attributes[t->attribute_count].value, attribute_value);
        t->attribute_count++;
    }
}

int main() {
    char xml[] = "<book title=\"The Catcher in the Rye\">"
                 "<author>J.D. Salinger</author>"
                 "<year>1951</year>"
                 "</book>";

    tag book;
    parse_tag(xml, &book);

    printf("Tag name: %s\n", book.name);
    printf("Attributes:\n");

    for (int i = 0; i < book.attribute_count; i++) {
        printf("  %s = %s\n", book.attributes[i].name, book.attributes[i].value);
    }

    return 0;
}