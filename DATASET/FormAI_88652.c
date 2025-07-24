//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_element(char* element) {
    // TODO: Add your element parsing logic here
}

void parse_xml(char* xml) {
    char* start_tag = NULL;
    char* end_tag = NULL;
    int i = 0;
    
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            // starting tag
            if (xml[i + 1] != '/') {
                start_tag = &xml[i + 1];
            }
            // ending tag
            else {
                end_tag = &xml[i + 2];
                xml[i - strlen(end_tag) - 2] = '\0';
                parse_element(end_tag);
            }
        }
        i++;
    }
}

int main() {
    char xml[] = "<students><student><name>John</name><age>21</age></student><student><name>Jane</name><age>22</age></student></students>";
    parse_xml(xml);
    return 0;
}