//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* tag;
    int level;
} Element;

#define MAX_ELEMENTS 1000
#define MAX_LEVELS 1000

Element elements[MAX_ELEMENTS];
int num_elements = 0;
int depths[MAX_LEVELS];
int num_depths = 0;
char* current_tag;

void parse_xml(char* xml) {
    char* token = strtok(xml, "<>");
    int depth = 0;

    while(token) {
        if(token[0] == '/') {
            depths[num_depths] = depth;
            num_depths--;
            current_tag = NULL;
        } else {
            elements[num_elements].level = depth;
            if(current_tag) {
                // element has child tags
                elements[num_elements].tag = strdup(current_tag);
                num_elements++;
            }
            current_tag = strdup(token);
            num_depths++;
            depth = num_depths;
        }
        token = strtok(NULL, "<>");
    }
}

void print_elements() {
    for(int i = 0; i < num_elements; i++) {
        for(int j = 0; j < elements[i].level; j++) {
            printf("\t");
        }
        printf("%s\n", elements[i].tag);
    }
}

int main() {
    char xml[] = "<root><child1><subchild1></subchild1></child1><child2></child2></root>";
    parse_xml(xml);
    print_elements();
    return 0;
}