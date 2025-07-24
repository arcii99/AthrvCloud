//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xml_node {
    char tag_name[20];
    int num_attributes;
    char **attributes;
    char **attribute_values;
    char data[100];
    int num_children;
    struct xml_node **children;
};

// function to parse the XML file and return the root node
struct xml_node* parse_xml(char* xml_file) {
    FILE *fp;
    char buffer[1000];
    char *token;
    struct xml_node *root = NULL;
    struct xml_node *current_node = NULL;
    int current_indent = -1;

    fp = fopen(xml_file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\r\n")] = '\0'; // remove newline character(s)

        // check if line contains a tag
        if (strchr(buffer, '<') != NULL) {
            struct xml_node *new_node = malloc(sizeof(struct xml_node));
            new_node->num_attributes = 0;
            new_node->num_children = 0;

            // get tag name
            token = strtok(buffer, " ");
            token = strtok(NULL, " ");
            strcpy(new_node->tag_name, token + 1);

            // check if tag is opening or closing
            if (new_node->tag_name[0] != '/') {
                // get attributes
                token = strtok(NULL, ">");
                while (token != NULL) {
                    if (strstr(token, "=") != NULL) {
                        new_node->num_attributes++;
                        new_node->attributes = realloc(new_node->attributes, sizeof(char*) * new_node->num_attributes);
                        new_node->attribute_values = realloc(new_node->attribute_values, sizeof(char*) * new_node->num_attributes);
                        new_node->attributes[new_node->num_attributes-1] = strdup(strtok(token, "="));
                        new_node->attribute_values[new_node->num_attributes-1] = strdup(strtok(NULL, "\""));
                        token = strtok(NULL, ">");
                    }
                    else {
                        break;
                    }
                }

                // check if node has data or is self closing
                if (token == NULL) {
                    continue;
                }
                else if (token[1] != '/') {
                    // set current node as parent of new node
                    current_indent++;
                    if (current_node != NULL) {
                        current_node->num_children++;
                        current_node->children = realloc(current_node->children, sizeof(struct xml_node*) * current_node->num_children);
                        current_node->children[current_node->num_children-1] = new_node;
                    }
                    else {
                        root = new_node;
                    }
                    current_node = new_node;

                    // get data
                    strcpy(current_node->data, strtok(token + 1, "<"));
                }
            }
            else {
                // close current node and move to parent node
                current_node->num_children++;
                current_node->children = realloc(current_node->children, sizeof(struct xml_node*) * current_node->num_children);
                current_node->children[current_node->num_children-1] = NULL;
                current_indent--;
                current_node = current_node->children[current_node->num_children-2];
            }
        }
    }

    fclose(fp);
    return root;
}

// example XML file
char* xml_file = "<root>\n\
                     <person id=\"1\">\n\
                         <name>John Doe</name>\n\
                         <age>25</age>\n\
                     </person>\n\
                     <person id=\"2\">\n\
                         <name>Jane Smith</name>\n\
                         <age>35</age>\n\
                     </person>\n\
                 </root>";

int main() {
    // create temporary XML file for parsing
    FILE *temp_file = tmpfile();
    fprintf(temp_file, "%s", xml_file);

    // parse XML file and print results
    struct xml_node *root = parse_xml(temp_file);
    printf("Tag Name: %s\n", root->tag_name);
    for (int i = 0; i < root->num_children; i++) {
        struct xml_node *person_node = root->children[i];
        printf("Person %s:\n", person_node->attributes[0]);
        for (int j = 0; j < person_node->num_children; j++) {
            struct xml_node *child_node = person_node->children[j];
            printf("    %s: %s\n", child_node->tag_name, child_node->data);
        }
    }

    return 0;
}