//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[128];
    char value[128];
} attribute_t;

typedef struct {
    char name[128];
    int num_attributes;
    attribute_t attributes[10];
    char content[256];
} element_t;

void strip_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {
    FILE *fp;
    char buffer[256];
    int buffer_len;
    int line_num = 1;

    fp = fopen("sample.xml", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    element_t elements[10];
    int num_elements = 0;
    char element_stack[10][128];
    int top = -1;

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer_len = strlen(buffer);
        strip_newline(buffer);

        if (buffer[0] == '<' && buffer[1] != '/') {
            char *pch = strtok(buffer+1, " ");
            strncpy(elements[num_elements].name, pch, sizeof(elements[num_elements].name));
            elements[num_elements].num_attributes = 0;
            elements[num_elements].content[0] = '\0';
            while (pch != NULL) {
                pch = strtok(NULL, " ");
                if (pch != NULL) {
                    strip_newline(pch);
                    char *pch2 = strtok(pch, "=");
                    strncpy(elements[num_elements].attributes[elements[num_elements].num_attributes].name, pch2, sizeof(elements[num_elements].attributes[elements[num_elements].num_attributes].name));
                    pch2 = strtok(NULL, "=");
                    strncpy(elements[num_elements].attributes[elements[num_elements].num_attributes].value, pch2, sizeof(elements[num_elements].attributes[elements[num_elements].num_attributes].value));
                    elements[num_elements].num_attributes++;
                }
            }

            if (top >= 0) {
                strncpy(elements[num_elements-1].content, element_stack[top], sizeof(elements[num_elements-1].content));
            }

            strncpy(element_stack[++top], elements[num_elements].name, sizeof(element_stack[top]));

            num_elements++;

        } else if (buffer[0] == '<' && buffer[1] == '/') {
            top--;
        } else if (top >= 0) {
            strcat(elements[num_elements-1].content, buffer);
        }

        line_num++;
    }

    fclose(fp);

    for (int i=0; i<num_elements; i++) {
        printf("Element %d: %s\n", i, elements[i].name);
        for (int j=0; j<elements[i].num_attributes; j++) {
            printf("%s=%s\n", elements[i].attributes[j].name, elements[i].attributes[j].value);
        }
        printf("Content: %s\n", elements[i].content);
    }

    return 0;
}