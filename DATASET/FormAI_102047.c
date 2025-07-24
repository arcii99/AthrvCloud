//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NODE_NAME_SIZE 50
#define MAX_ATTR_NAME_SIZE 50
#define MAX_ATTR_VALUE_SIZE 100
#define MAX_DATA_SIZE 1000
#define MAX_CHILDREN 50

typedef struct xml_node {
    char name[MAX_NODE_NAME_SIZE]; // name of tag
    char data[MAX_DATA_SIZE]; // data within tag
    struct xml_node* children[MAX_CHILDREN];
    char attr_names[MAX_CHILDREN][MAX_ATTR_NAME_SIZE]; // attribute names
    char attr_values[MAX_CHILDREN][MAX_ATTR_VALUE_SIZE]; // attribute values
    int num_children; // number of child tags
    int num_attrs; // number of attributes
} xml_node;

typedef struct thread_args {
    char* xml_string;
    xml_node* root;
} thread_args;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* parse_xml(void* args_ptr) {
    thread_args* args = (thread_args*) args_ptr;
    char* xml_string = args->xml_string;
    xml_node* root = args->root;

    char* token = strtok(xml_string, "<"); 
    while (token != NULL) {
        pthread_mutex_lock(&mutex);

        if (token[0] == '/') { 
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        xml_node* child_node = (xml_node*) malloc(sizeof(xml_node));
        child_node->num_children = 0;
        child_node->num_attrs = 0;

        sscanf(token, "%s", child_node->name); 

        token = strstr(token, ">") + 1;

        sscanf(token, "%[^<]", child_node->data);

        token = strstr(token, "<") + 1; 

        while (token[0] != '/') {
            if (token[0] == '>') {
                token = strstr(token, "<") + 1;
                continue;
            }

            char attr_name[MAX_ATTR_NAME_SIZE];
            char attr_value[MAX_ATTR_VALUE_SIZE];

            sscanf(token, "%[^=]=\"%[^\"]\"", attr_name, attr_value);

            strncpy(child_node->attr_names[child_node->num_attrs], attr_name, MAX_ATTR_NAME_SIZE);
            strncpy(child_node->attr_values[child_node->num_attrs], attr_value, MAX_ATTR_VALUE_SIZE);

            child_node->num_attrs++;

            token = strstr(token, "\"") + 1;
            token = strstr(token, "\"") + 1;
            token = strstr(token, "<") + 1;
        }

        xml_node** children = root->children;
        children[root->num_children] = child_node;
        root->num_children++;
        pthread_mutex_unlock(&mutex);

        thread_args* child_args = (thread_args*) malloc(sizeof(thread_args));
        child_args->xml_string = token;
        child_args->root = child_node;

        pthread_t child_thread;
        pthread_create(&child_thread, NULL, parse_xml, (void*) child_args);

        token = strtok(NULL, "<");
    }

    return NULL;
}

int main() {
    char xml_string[MAX_DATA_SIZE];
    xml_node root_node;
    root_node.num_children = 0;
    root_node.num_attrs = 0;

    printf("Enter XML data: ");
    fgets(xml_string, MAX_DATA_SIZE, stdin);
    xml_string[strcspn(xml_string, "\n")] = 0;

    thread_args args;
    args.xml_string = xml_string;
    args.root = &root_node;

    parse_xml((void*) &args);

    printf("Root Node: %s\n", root_node.name);
    printf("Root Node Data: %s\n", root_node.data);
    printf("Root Node Attributes: ");

    for (int i = 0; i < root_node.num_attrs; i++) {
        printf("%s=\"%s\" ", root_node.attr_names[i], root_node.attr_values[i]);
    }

    printf("\n");

    printf("Child Nodes: \n");

    for (int i = 0; i < root_node.num_children; i++) {
        xml_node* child = root_node.children[i];

        printf("Node %d: %s\n", i+1, child->name);
        printf("Data: %s\n", child->data);
        printf("Attributes: ");

        for (int j = 0; j < child->num_attrs; j++) {
            printf("%s=\"%s\" ", child->attr_names[j], child->attr_values[j]);
        }

        printf("\n");
    }

    return 0;
}