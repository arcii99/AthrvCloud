//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for holding a single xml node
struct xml_node {
    char* name;
    char* value;
    int num_children;
    struct xml_node* children;
};

// Function to create a new xml node with given name and value
struct xml_node* create_xml_node(char* name, char* value) {
    struct xml_node* node = malloc(sizeof(struct xml_node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->num_children = 0;
    node->children = NULL;
    return node;
}

// Function to add a child to a given xml node
void add_child(struct xml_node* parent, struct xml_node* child) {
    parent->num_children++;
    parent->children = realloc(parent->children, parent->num_children * sizeof(struct xml_node));
    parent->children[parent->num_children - 1] = *child;
}

// Function to parse given xml string and return the root xml node
struct xml_node* parse_xml(char* xml_str) {
    struct xml_node* root = NULL;
    char* start_tag = NULL;
    char* end_tag = NULL;
    char* tag_name = NULL;
    char* tag_value = NULL;
    int nesting_level = 0;
    int i = 0;
    while(xml_str[i] != '\0') {
        if(xml_str[i] == '<') {
            if(xml_str[i+1] == '/') {
                nesting_level--;
                end_tag = strchr(xml_str+i+1, '>');
                i = end_tag - xml_str;
                continue;
            }
            start_tag = xml_str+i+1;
            tag_name = strtok(start_tag, " >");
            tag_value = strtok(NULL, "<");
            if(tag_value[0] != '/') {
                struct xml_node* node = create_xml_node(tag_name, tag_value);
                if(nesting_level == 0) {
                    root = node;
                } else {
                    add_child(&root->children[root->num_children - 1], node);
                }
                nesting_level++;
            }
            i += strlen(tag_name) + strlen(tag_value) + 3;
        } else {
            i++;
        }
    }
    return root;
}

int main() {
    char* xml_str = "<root><name>John Doe</name><age>25</age><address><street>Main St</street><city>Example City</city><state>CA</state></address></root>";
    struct xml_node* root = parse_xml(xml_str);
    printf("Root node name: %s\n", root->name);
    printf("Root node value: %s\n", root->value);
    printf("Number of children: %d\n", root->num_children);
    for(int i=0; i<root->num_children; i++) {
        printf("Child %d name: %s\n", i+1, root->children[i].name);
        printf("Child %d value: %s\n", i+1, root->children[i].value);
        printf("Child %d number of children: %d\n", i+1, root->children[i].num_children);
        for(int j=0; j<root->children[i].num_children; j++) {
            printf("   Child %d-%d name: %s\n", i+1, j+1, root->children[i].children[j].name);
            printf("   Child %d-%d value: %s\n", i+1, j+1, root->children[i].children[j].value);
        }
    }
    return 0;
}