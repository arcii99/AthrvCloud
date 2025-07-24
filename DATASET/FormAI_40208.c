//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 50
#define MAX_ATT_SIZE 50

typedef struct _xml_attribute
{
    char* name;
    char* value;
    struct _xml_attribute* next;
} xml_attribute;

typedef struct _xml_node
{
    char* tag;
    xml_attribute* attributes;
    struct _xml_node* children;
    struct _xml_node* next;
} xml_node;

xml_node* parse_xml(FILE* file);
xml_node* parse_element(FILE* file);
xml_attribute* parse_attributes(FILE* file);
char* parse_value(FILE* file, char end_char);

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return -1;
    }
    
    FILE* file = fopen(argv[1], "r");
    if(file == NULL)
    {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return -1;
    }
    
    xml_node* root_node = parse_xml(file);
    fclose(file);
    
    printf("XML Parsed Successfully!\n");
    // TODO: Do something with the parsed XML
    
    return 0;
}

xml_node* parse_xml(FILE* file)
{
    xml_node* root = NULL;
    xml_node* node = NULL;
    char ch;
    
    // skip until start of XML tag
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == '<')
        {
            ch = fgetc(file);
            if(ch == '?') // skip processing instruction
            {
                while((ch = fgetc(file)) != EOF)
                {
                    if(ch == '?')
                    {
                        ch = fgetc(file);
                        if(ch == '>')
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                ungetc(ch, file);
                root = parse_element(file);
                node = root;
                break;
            }
        }
    }
    
    // parse remaining elements
    while((node != NULL) && (ch = fgetc(file)) != EOF)
    {
        if(ch == '<')
        {
            ch = fgetc(file);
            if(ch == '/')
            {
                // end tag
                char tag[MAX_TAG_SIZE];
                int i = 0;
                while((ch = fgetc(file)) != EOF)
                {
                    if(ch == '>')
                    {
                        tag[i] = '\0';
                        break;
                    }
                    tag[i++] = ch;
                }
                
                if(strcmp(tag, node->tag) != 0)
                {
                    fprintf(stderr, "Error: Expected end tag for %s, but got end tag for %s\n", node->tag, tag);
                    return NULL;
                }
                
                node = node->next;
            }
            else
            {
                ungetc(ch, file);
                xml_node* child = parse_element(file);
                
                if(node == NULL)
                {
                    fprintf(stderr, "Error: Unexpected element %s outside of root XML tag\n", child->tag);
                    return NULL;
                }
                
                if(node->children == NULL)
                {
                    node->children = child;
                }
                else
                {
                    xml_node* current = node->children;
                    while(current->next != NULL)
                    {
                        current = current->next;
                    }
                    current->next = child;
                }
                
                if(child->next != NULL)
                {
                    fprintf(stderr, "Error: Unexpected multiple child elements for %s\n", node->tag);
                    return NULL;
                }
                
                node = child;
            }
        }
        else if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
        {
            continue;
        }
        else
        {
            fprintf(stderr, "Error: Unexpected character %c\n", ch);
            return NULL;
        }
    }
    
    return root;
}

xml_node* parse_element(FILE* file)
{
    char ch;
    char tag[MAX_TAG_SIZE];
    int i = 0;
    
    // read tag name
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\t')
        {
            tag[i] = '\0';
            parse_attributes(file); // ignore attributes for processing instructions
            break;
        }
        else if(ch == '>' || ch == '/')
        {
            tag[i] = '\0';
            break;
        }
        else
        {
            tag[i++] = ch;
        }
    }
    
    if(ch == '/')
    {
        // self-closing tag
        xml_node* node = (xml_node*) malloc(sizeof(xml_node));
        node->tag = (char*) malloc(strlen(tag) + 1);
        strcpy(node->tag, tag);
        node->attributes = NULL;
        node->children = NULL;
        node->next = NULL;
        return node;
    }
    
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->tag = (char*) malloc(strlen(tag) + 1);
    strcpy(node->tag, tag);
    node->attributes = parse_attributes(file);
    node->children = NULL;
    node->next = NULL;
    
    return node;
}

xml_attribute* parse_attributes(FILE* file)
{
    xml_attribute* head = NULL;
    xml_attribute* current = NULL;
    char ch;
    
    // skip whitespace
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == ' ' || ch == '\t')
        {
            continue;
        }
        else
        {
            ungetc(ch, file);
            break;
        }
    }
    
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == '/')
        {
            // end of attributes
            ch = fgetc(file);
            if(ch != '>')
            {
                fprintf(stderr, "Error: Expected end of tag, but got %c\n", ch);
                return NULL;
            }
            
            break;
        }
        else if(ch == '>')
        {
            // end of tag
            break;
        }
        else if(ch == ' ' || ch == '\t')
        {
            // next attribute
            continue;
        }
        else
        {
            xml_attribute* attr = (xml_attribute*) malloc(sizeof(xml_attribute));
            attr->name = (char*) malloc(MAX_ATT_SIZE);
            attr->value = NULL;
            attr->next = NULL;
            
            // read attribute name
            int i = 0;
            while((ch = fgetc(file)) != EOF)
            {
                if(ch == ' ' || ch == '\t' || ch == '=')
                {
                    attr->name[i] = '\0';
                    break;
                }
                else
                {
                    attr->name[i++] = ch;
                }
            }
            
            // skip whitespace
            while((ch = fgetc(file)) != EOF)
            {
                if(ch == ' ' || ch == '\t')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            if(ch != '=')
            {
                fprintf(stderr, "Error: Expected attribute value, but got %c\n", ch);
                return NULL;
            }
            
            // skip whitespace
            while((ch = fgetc(file)) != EOF)
            {
                if(ch == ' ' || ch == '\t')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            
            if(ch != '"' && ch != '\'')
            {
                fprintf(stderr, "Error: Attribute value must be enclosed with quotation marks\n");
                return NULL;
            }
            
            attr->value = parse_value(file, ch);
            
            if(head == NULL)
            {
                head = attr;
            }
            else if(current != NULL)
            {
                current->next = attr;
            }
            current = attr;
        }
    }
    
    return head;
}

char* parse_value(FILE* file, char end_char)
{
    char ch;
    char* value = (char*) malloc(MAX_ATT_SIZE);
    int i = 0;
    
    while((ch = fgetc(file)) != EOF)
    {
        if(ch == end_char)
        {
            break;
        }
        else
        {
            value[i++] = ch;
        }
    }
    
    value[i] = '\0';
    
    return value;
}