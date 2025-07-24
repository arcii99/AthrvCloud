//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAGS 10
#define MAX_CHARS 100

typedef struct tag {
    char name[MAX_CHARS];
    int depth;
    struct tag *child_tags[MAX_TAGS];
    struct tag *parent_tag;
} tag_t;

tag_t* parse_xml(char *xml);
void print_xml_tree(tag_t *root);

int main() {

    char xml[] = "<people><person><name>John</name><age>25</age></person><person><name>Sarah</name><age>30</age></person></people>";
    
    tag_t *root = parse_xml(xml);
    
    print_xml_tree(root);
    
    return 0;
}

tag_t* parse_xml(char *xml) {

    tag_t *root = NULL;
    tag_t *current_tag = NULL;
    char *token = strtok(xml, "<>");
    char *my_tags[MAX_TAGS];
    int tag_count = 0;
    int depth = 0;
    
    while (token != NULL) {
        
        if (strcmp(token, "") == 0) {
            token = strtok(NULL, "<>");
            continue;
        }
        
        if (strcmp(token, "/") == 0) {
            current_tag = current_tag->parent_tag;
            depth--;
            token = strtok(NULL, "<>");
            continue;
        } 
        
        if (strcmp(token, "?xml") == 0) {
            token = strtok(NULL, "<>");
            continue;
        }

        if (strcmp(token, "!doctype") == 0) {
            token = strtok(NULL, "<>");
            continue;
        }
        
        if (tag_count % 2 == 0) {
            my_tags[tag_count] = malloc(sizeof(token));
            strcpy(my_tags[tag_count], token);
        } else {
            tag_t *new_tag = malloc(sizeof(tag_t));
            strcpy(new_tag->name, my_tags[tag_count - 1]);
            new_tag->parent_tag = current_tag;
            new_tag->depth = depth;
            
            if (root == NULL) {
                root = new_tag;
            }
            
            if (current_tag != NULL) {
                current_tag->child_tags[current_tag->depth] = new_tag;
            }
            
            current_tag = new_tag;
            depth++;
        }
        
        tag_count++;
        token = strtok(NULL, "<>");
    }
    
    return root;

}

void print_xml_tree(tag_t *root) {
    if (root == NULL) {
        return;
    }
    
    printf("%*s<%s>\n", (root->depth) * 4, "", root->name);
    
    for (int i = 0; i < MAX_TAGS; i++) {
        print_xml_tree(root->child_tags[i]);
    }
    
    printf("%*s</%s>\n", (root->depth) * 4, "", root->name);
}