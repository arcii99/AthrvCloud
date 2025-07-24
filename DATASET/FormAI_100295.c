//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODE_NAME_LEN 50
#define MAX_ATTR_NAME_LEN 50
#define MAX_ATTR_VALUE_LEN 100
#define MAX_TAG_SIZE 100
#define MAX_CONTENT_SIZE 500

struct attribute
{
    char name[MAX_ATTR_NAME_LEN];
    char value[MAX_ATTR_VALUE_LEN];
    struct attribute* next;
};

typedef struct attribute Attribute;

struct node
{
    char name[MAX_NODE_NAME_LEN];
    Attribute* attributes;
    char content[MAX_CONTENT_SIZE];
    struct node* parent;
    struct node* children;
    struct node* next;
};

typedef struct node Node;

char* xml_content;
int xml_size;

Node* get_new_node(char* name, Node* parent)
{
    Node* node = (Node *) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->parent = parent;
    node->attributes = NULL;
    strcpy(node->content, "");
    node->children = NULL;
    node->next = NULL;
    return node;
}

Attribute* get_new_attr(char* name, char* value)
{
    Attribute* attr = (Attribute *) malloc(sizeof(Attribute));
    strcpy(attr->name, name);
    strcpy(attr->value, value);
    attr->next = NULL;
    return attr;
}

void add_child(Node* parent, Node* child)
{
    child->next = parent->children;
    parent->children = child;
}

void add_attr(Node* node, char* name, char* value)
{
    Attribute* attr = get_new_attr(name, value);
    attr->next = node->attributes;
    node->attributes = attr;
}

Node* parse_xml()
{
    Node* root = get_new_node("root", NULL);
    Node* current = root;
    char tag[MAX_TAG_SIZE];
    int i = 0, j = 0;
    bool inside_tag = false;
    bool closing_tag = false;
    char attr_name[MAX_ATTR_NAME_LEN];
    char attr_value[MAX_ATTR_VALUE_LEN];
    bool inside_attr_value = false;
    bool inside_attr_name = false;
    while (i < xml_size)
    {
        char c = xml_content[i];
        if (c == '<')
        {
            inside_tag = true;
            j = 0;
            closing_tag = false;
        }
        else if (c == '>')
        {
            inside_tag = false;
            if (closing_tag)
            {
                if (strcmp(tag, current->name) == 0)
                    current = current->parent;
            }
            else
            {
                Node* node = get_new_node(tag, current);
                add_child(current, node);
                current = node;
            }
            for (int k = 0; k < MAX_TAG_SIZE; k++)
                tag[k] = '\0';
            j = 0;
            inside_attr_name = false;
            inside_attr_value = false;
        }
        else if (c == '/')
        {
            closing_tag = true;
        }
        else if (!inside_tag)
        {
            strncat(current->content, &c, 1);
        }
        else if (c == '=')
        {
            inside_attr_value = true;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            if (inside_attr_name)
            {
                inside_attr_name = false;
                attr_name[j] = '\0';
            }
            else if (inside_attr_value)
            {
                inside_attr_value = false;
                attr_value[j] = '\0';
                add_attr(current, attr_name, attr_value);
                for (int k = 0; k < MAX_ATTR_NAME_LEN; k++)
                    attr_name[k] = '\0';
                for (int k = 0; k < MAX_ATTR_VALUE_LEN; k++)
                    attr_value[k] = '\0';
            }
        }
        else
        {
            if (closing_tag && j == 0)
                j++;
            tag[j] = c;
            j++;
            if (inside_attr_name)
                attr_name[j-1] = c;
            else if (inside_attr_value)
                attr_value[j-1] = c;
            else if (c == '=')
                inside_attr_name = true;
        }
        i++;
    }
    return root;
}

void print_tree(Node* root, int level)
{
    for (int i = 0; i < level; i++)
        printf(" ");
    printf("<%s", root->name);
    Attribute* attr = root->attributes;
    while (attr != NULL)
    {
        printf(" %s=\"%s\"", attr->name, attr->value);
        attr = attr->next;
    }
    if (strlen(root->content) == 0 && root->children == NULL)
        printf("/>\n");
    else
    {
        printf(">\n");
        if (strlen(root->content) > 0)
        {
            for (int i = 0; i < level+2; i++)
                printf(" ");
            printf("%s\n", root->content);
        }
        Node* child = root->children;
        while (child != NULL)
        {
            print_tree(child, level+2);
            child = child->next;
        }
        for (int i = 0; i < level; i++)
            printf(" ");
        printf("</%s>\n", root->name);
    }
}

int main()
{
    xml_content = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><menu><item id=\"1\" name=\"Burger\"><price>5.00</price><description>A juicy burger.</description></item><item id=\"2\" name=\"Fries\"><price>2.00</price><description>Crispy fries.</description></item></menu>";
    xml_size = strlen(xml_content);
    Node* root = parse_xml();
    print_tree(root, 0);
    return 0;
}