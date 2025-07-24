//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 1000

// Struct to store the XML tag information
typedef struct tag{
    char name[MAX];
    char value[MAX];
    struct tag* first_child;
    struct tag* next_sibling;
} TAG;

// Parser function to build the XML tag tree
TAG* build_tree(char* xml_string){
    TAG* root = NULL;
    TAG* curr_tag = NULL;
    char tag_name[MAX];
    char tag_value[MAX];
    int level = 0;

    // Tokenize the XML string
    char* token = strtok(xml_string, "<>");
    while(token != NULL){
        // If the token is a tag opening
        if(token[0] == '<' && token[1] != '/'){
            // Extract the tag name
            sscanf(token, "<%[^>]>", tag_name);
            // Create a new tag node
            TAG* new_tag = (TAG*)malloc(sizeof(TAG));
            strcpy(new_tag->name, tag_name);
            new_tag->value[0] = '\0';
            new_tag->first_child = NULL;
            new_tag->next_sibling = NULL;

            // If this is the first tag, set it as the root
            if(root == NULL){
                root = new_tag;
                curr_tag = new_tag;
            }
            else{
                // If this is a child of the previous tag, set it as a child
                if(level == 1){
                    curr_tag->first_child = new_tag;
                }
                // If this is a sibling of the previous tag, set it as the next sibling
                else{
                    curr_tag->next_sibling = new_tag;
                }
                curr_tag = new_tag;
            }
            // Increment the level of the tag
            level++;
        }
        // If the token is a tag closing
        else if(token[0] == '<' && token[1] == '/'){
            // Decrement the level of the tag
            level--;
            // Move back to the parent tag
            curr_tag = root;
            for(int i=0; i<level; i++){
                curr_tag = curr_tag->first_child;
            }
        }
        // If the token is a tag value
        else{
            // Trim the whitespace from the tag value
            int i=0, j=0;
            while(token[i] != '\0'){
                if(!isspace(token[i])){
                    tag_value[j] = token[i];
                    j++;
                }
                i++;
            }
            tag_value[j] = '\0';
            // Set the tag value
            strcpy(curr_tag->value, tag_value);
        }
        // Get the next token
        token = strtok(NULL, "<>");
    }

    return root;
}

// Function to print the XML tag tree
void print_tree(TAG* root, int level){
    // Print the tag name and value
    for(int i=0; i<level; i++){
        printf("  ");
    }
    printf("%s: %s\n", root->name, root->value);

    // Print the child tags recursively
    TAG* child = root->first_child;
    while(child != NULL){
        print_tree(child, level+1);
        child = child->next_sibling;
    }
}

int main(){
    // Example XML string
    char xml_string[MAX] = "<bookstore><book><title>Harry Potter and the Philosopher's Stone</title><author>J.K. Rowling</author><year>1997</year></book><book><title>Harry Potter and the Chamber of Secrets</title><author>J.K. Rowling</author><year>1998</year></book></bookstore>";
    
    // Build the XML tag tree
    TAG* root = build_tree(xml_string);

    // Print the XML tag tree
    print_tree(root, 0);

    return 0;
}