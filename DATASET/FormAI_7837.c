//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include <stdio.h>
#include <string.h>

#define MAX_TAG_SIZE 50
#define MAX_ATTR_SIZE 50
#define MAX_VALUE_SIZE 100
#define MAX_XML_SIZE 1000

typedef struct {
    char tag[MAX_TAG_SIZE];
    char attributes[MAX_ATTR_SIZE][MAX_VALUE_SIZE];
    char values[MAX_ATTR_SIZE][MAX_VALUE_SIZE];
    int attr_count;
} XmlNode;

int main() {
    char xml_string[MAX_XML_SIZE] = "<items><item id='1' name='apple' price='1.20'/><item id='2' name='orange' price='0.90'/></items>";

    XmlNode nodes[10];
    int node_count = 0;

    char tag_stack[MAX_TAG_SIZE][MAX_VALUE_SIZE];
    int top = -1;

    char *token = strtok(xml_string, "<>/=\'\"");

    while (token != NULL) {
        if (strcmp(token, "items") == 0) {
            strncpy(tag_stack[++top], token, MAX_TAG_SIZE);
        } else if (strcmp(token, "/items") == 0) {
            top--;
        } else {
            if (top == 0) {
                strncpy(nodes[node_count].tag, token, MAX_TAG_SIZE);
                nodes[node_count].attr_count = 0;
                node_count++;
            } else if (top == 1) {
                if (strcmp(tag_stack[top], "item") == 0) {
                    int index = nodes[node_count - 1].attr_count;
                    if (index < MAX_ATTR_SIZE) {
                        strncpy(nodes[node_count - 1].attributes[index], token, MAX_VALUE_SIZE);
                        token = strtok(NULL, "<>/=\'\"");
                        strncpy(nodes[node_count - 1].values[index], token, MAX_VALUE_SIZE);
                        nodes[node_count - 1].attr_count++;
                    }
                }
            }
        }
        token = strtok(NULL, "<>/=\'\"");
    }

    printf("Parsed XML string:\n");

    for (int i = 0; i < node_count; i++) {
        printf("Tag: %s\n", nodes[i].tag);
        for (int j = 0; j < nodes[i].attr_count; j++) {
            printf("Attribute: %s, Value: %s\n", nodes[i].attributes[j], nodes[i].values[j]);
        }
    }

    return 0;
}