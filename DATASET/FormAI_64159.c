//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char* tag_name;
    char** attributes;
    int attribute_count;
    char* text;
    struct Node** children;
    int children_count;
} Node;

/* Function to parse XML file and create a tree of Nodes */
Node* parse_xml(char* xml_file) {
    FILE* fp;
    char buffer[MAX_BUFFER_SIZE];
    Node* root_node = NULL;
    Node* current_node = NULL;
    int i, j, k, l, is_tag_start, is_tag_end, is_comment, is_text;

    fp = fopen(xml_file, "r");

    if (fp == NULL) {
        printf("Unable to open XML file.\n");
        return NULL;
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        is_tag_start = is_tag_end = is_comment = is_text = 0;

        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '<') {
                is_tag_start = 1;
                break;
            }
            else if (!isspace(buffer[i])) {
                is_text = 1;
                break;
            }
        }

        if (is_text) {
            if (current_node != NULL) {
                current_node->text = strdup(buffer);
            }
            else {
                printf("Encountered text outside of any tag.\n");
            }
        }
        else if (is_tag_start) {
            is_tag_end = (buffer[i+1] == '/');
            is_comment = (buffer[i+1] == '!');
            k = i + is_tag_end; // k is the start of the tag name
            l = is_comment ? strlen(buffer) : strlen(buffer) - 2; // l is the end of the tag name
            j = k; // j is the start of the attributes
            current_node = malloc(sizeof(Node));

            if (is_comment) {
                continue;
            }
            else {
                if (!is_tag_end) {
                    current_node->tag_name = strndup(buffer + k, l - k);
                    current_node->children = malloc(sizeof(Node*) * MAX_BUFFER_SIZE);
                    current_node->children_count = 0;
                    current_node->attributes = malloc(sizeof(char*) * MAX_BUFFER_SIZE);
                    current_node->attribute_count = 0;

                    while (buffer[j] != '>') {
                        if (!isspace(buffer[j])) {
                            k = j; // k is the start of the attribute name
                            while (buffer[j] != '=') {
                                j++; // j is the end of the attribute name
                            }
                            current_node->attributes[current_node->attribute_count++] = strndup(buffer + k, j - k);

                            while (isspace(buffer[j])) {
                                j++;
                            }

                            if (buffer[j] == '=') {
                                j++; // j is the start of the attribute value

                                while (isspace(buffer[j]) || buffer[j] == '\'' || buffer[j] == '"') {
                                    j++; // j is the end of the opening quote
                                }
                                k = j; // k is the start of the attribute value

                                while (!(buffer[j] == '\'' || buffer[j] == '"')) {
                                    j++; // j is the end of the attribute value
                                }

                                current_node->attributes[current_node->attribute_count++] = strndup(buffer + k, j - k);

                                while (isspace(buffer[j]) || buffer[j] == '\'' || buffer[j] == '"') {
                                    j++; // j is the end of the closing quote
                                }
                            }
                        }
                        else {
                            j++;
                        }
                    }

                    if (root_node == NULL) {
                        root_node = current_node;
                    }

                    if (current_node != NULL) {
                        Node *tmp = current_node;
                        current_node = current_node->children[current_node->children_count++] = malloc(sizeof(Node));
                        current_node->text = NULL;
                        current_node->children = NULL;
                        current_node->children_count = 0;
                        current_node->attributes = NULL;
                        current_node->attribute_count = 0;
                    }
                }
                else {
                    Node *tmp = current_node;
                    current_node = NULL;
                }
            }
        }
    }

    fclose(fp);

    return root_node;
}

/* Function to print the tree of Nodes */
void print_xml(Node* node, int indent) {
    int i, j;

    for (i = 0; i < indent; i++) {
        printf(" ");
    }

    if (node->text != NULL) {
        printf("%s", node->text);
    }
    else {
        printf("<%s", node->tag_name);

        for (j = 0; j < node->attribute_count; j += 2) {
            printf(" %s=\"%s\"", node->attributes[j], node->attributes[j+1]);
        }

        printf(">");

        if (node->children_count > 0) {
            printf("\n");
            for (i = 0; i < node->children_count; i++) {
                print_xml(node->children[i], indent + 2);
            }
            for (i = 0; i < indent; i++) {
                printf(" ");
            }
        }

        printf("</%s>", node->tag_name);
    }

    printf("\n");
}

int main(int argc, char* argv[]) {
    Node* root_node = parse_xml("example.xml");

    if (root_node != NULL) {
        print_xml(root_node, 0);
    }

    return 0;
}