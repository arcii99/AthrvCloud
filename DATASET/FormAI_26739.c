//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTRIBUTE_LENGTH 20
#define MAX_ATTRIBUTE_VALUE_LENGTH 100

typedef struct Attribute {
    char name[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
} Attribute;

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    Attribute* attributes;
    int num_attributes;
    struct Node** children;
    int num_children;
    char text[MAX_ATTRIBUTE_VALUE_LENGTH];
} Node;

Node* parseXML(char* xml);
void printNode(Node* node, int depth);

int main() {
    char xml[] = "<bookstore>\n"
                 "  <book category=\"COOKING\">\n"
                 "    <title lang=\"en\">Everyday Italian</title>\n"
                 "    <author>Giada De Laurentiis</author>\n"
                 "    <year>2005</year>\n"
                 "    <price>30.00</price>\n"
                 "  </book>\n"
                 "  <book category=\"CHILDREN\">\n"
                 "    <title lang=\"en\">Harry Potter</title>\n"
                 "    <author>J.K. Rowling</author>\n"
                 "    <year>1997</year>\n"
                 "    <price>25.00</price>\n"
                 "  </book>\n"
                 "</bookstore>";
                 
    Node* root = parseXML(xml);
    
    printf("XML Parse Complete!\n\n");
    
    printNode(root, 0);
    
    return 0;
}

Node* parseXML(char* xml) {
    int i = 0;
    Node* root = malloc(sizeof(Node));
    root->attributes = NULL;
    root->num_attributes = 0;
    root->children = NULL;
    root->num_children = 0;
    strcpy(root->tag, "");
    strcpy(root->text, "");
    
    while(xml[i] != '\0') {
        Node* node = malloc(sizeof(Node));
        node->attributes = malloc(sizeof(Attribute));
        node->num_attributes = 0;
        node->children = NULL;
        node->num_children = 0;
        strcpy(node->tag, "");
        strcpy(node->text, "");
        
        if(xml[i] == '<') {
            i++;
            if(xml[i] == '/') { // end tag
                i++;
                int j = 0;
                char endtag[MAX_TAG_LENGTH];
                while(xml[i] != '>') {
                    endtag[j] = xml[i];
                    j++;
                    i++;
                }
                endtag[j] = '\0';
                if(strcmp(endtag, root->tag) == 0) { // found matching end tag for root node
                    return root;
                }
                else { // end tag doesn't match root node, so must be a child node
                    int k;
                    for(k = root->num_children-1; k >= 0; k--) {
                        if(strcmp(endtag, root->children[k]->tag) == 0) { // found matching end tag for child node
                            break;
                        }
                    }
                    if(k == -1) { // matching end tag not found
                        printf("Error: matching end tag not found for %s\n", endtag);
                    }
                    else { // found matching end tag for child node
                        node = root->children[k];
                        root->num_children--;
                        root->children = realloc(root->children, root->num_children * sizeof(Node*));
                    }
                }
            }
            else { // start tag or self-closing tag
                int j = 0;
                char tag[MAX_TAG_LENGTH];
                while(xml[i] != ' ' && xml[i] != '>') {
                    tag[j] = xml[i];
                    j++;
                    i++;
                }
                tag[j] = '\0';
                strcpy(node->tag, tag);
                
                while(xml[i] != '>') { // parse attributes
                    while(xml[i] == ' ') {
                        i++;
                    }
                    if(xml[i] == '/') { // self-closing tag
                        break;
                    }
                    j = 0;
                    char attribute[MAX_ATTRIBUTE_LENGTH];
                    while(xml[i] != '=') {
                        attribute[j] = xml[i];
                        j++;
                        i++;
                    }
                    attribute[j] = '\0';
                    i++; // skip the equals sign
                    j = 0;
                    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
                    if(xml[i] == '\"') { // attribute value is enclosed in quotes
                        i++;
                        while(xml[i] != '\"') {
                            value[j] = xml[i];
                            j++;
                            i++;
                        }
                        value[j] = '\0';
                        i++; // skip the ending quote
                    }
                    else { // attribute value is not enclosed in quotes
                        while(xml[i] != ' ') {
                            value[j] = xml[i];
                            j++;
                            i++;
                        }
                        value[j] = '\0';
                    }
                    strcpy(node->attributes[node->num_attributes].name, attribute);
                    strcpy(node->attributes[node->num_attributes].value, value);
                    node->num_attributes++;
                    node->attributes = realloc(node->attributes, (node->num_attributes + 1) * sizeof(Attribute));
                }
                
                if(xml[i] == '/') { // self-closing tag
                    i++; // skip the closing slash
                    i++; // skip the closing bracket
                }
                else { // start tag
                    i++; // skip the closing bracket
                    
                    int j = 0;
                    char text[MAX_ATTRIBUTE_VALUE_LENGTH];
                    while(xml[i] != '<') {
                        text[j] = xml[i];
                        j++;
                        i++;
                    }
                    text[j] = '\0';
                    strcpy(node->text, text);
                    
                    root->num_children++;
                    root->children = realloc(root->children, root->num_children * sizeof(Node*));
                    root->children[root->num_children-1] = node;
                }
            }
        }
        else { // text node
            int j = 0;
            char text[MAX_ATTRIBUTE_VALUE_LENGTH];
            while(xml[i] != '<') {
                text[j] = xml[i];
                j++;
                i++;
            }
            text[j] = '\0';
            strcpy(node->text, text);
            
            root->num_children++;
            root->children = realloc(root->children, root->num_children * sizeof(Node*));
            root->children[root->num_children-1] = node;
        }
    }
    
    return root;
}

void printNode(Node* node, int depth) {
    int i;
    for(i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s", node->tag);
    int j;
    for(j = 0; j < node->num_attributes; j++) {
        printf(" %s=\"%s\"", node->attributes[j].name, node->attributes[j].value);
    }
    if(strlen(node->text) == 0 && node->num_children == 0) {
        printf("/>\n");
    }
    else {
        printf(">\n");
        if(strlen(node->text) > 0) {
            for(i = 0; i < depth+1; i++) {
                printf("  ");
            }
            printf("%s\n", node->text);
        }
        for(i = 0; i < node->num_children; i++) {
            printNode(node->children[i], depth+1);
        }
        for(i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
    }
}