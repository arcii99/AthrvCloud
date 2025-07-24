//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Declare Structures
struct Node{
  char tag[20];
  char attributes[50];
  struct Node* child;
  int child_count;
};

struct Stack{
  struct Node* nodes[50];
  int top;
};

// Declare Global variables
char xml_input[1000];
struct Stack node_stack;

// Declare Function Prototypes
int parse_xml(char* xml_input);
void push(struct Node* node);
struct Node* pop();
void free_node(struct Node* node);

// Main Function
int main()
{
  // Initialize stack and input
  node_stack.top = -1;
  strcpy(xml_input, "<person name='John'><age>23</age><location><city>London</city><country>UK</country></location></person>");
  
  // Parse XML and print results
  if(parse_xml(xml_input))
    printf("XML parsing successful!\n\n");
  else
    printf("XML parsing failed.\n\n");
  
  // Free memory
  struct Node* node = NULL;
  while((node = pop()) != NULL)
    free_node(node);
  
  return 0;
}

// Function to parse XML
int parse_xml(char* xml_input)
{
  int i=0;
  struct Node* current_node = NULL;
  
  // Loop through input string
  while(xml_input[i] != '\0')
  {
    // Check for opening tag
    if(xml_input[i] == '<' && xml_input[i+1] != '/')
    {
      // Create new node and set tag and attributes
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      memset(new_node, 0, sizeof(struct Node));
      strcpy(new_node->tag, strtok(&xml_input[i+1], " >"));
      strcpy(new_node->attributes, strtok(NULL, " >"));
      new_node->child_count = 0;
      
      // Add as child of current node and push to stack
      if(current_node != NULL)
      {
        current_node->child = (struct Node*)realloc(current_node->child, (current_node->child_count+1)*sizeof(struct Node));
        current_node->child[current_node->child_count++] = *new_node;
      }
      push(new_node);
      i += strlen(new_node->tag) + strlen(new_node->attributes) + 2;
    }
    
    // Check for closing tag
    else if(xml_input[i] == '<' && xml_input[i+1] == '/')
    {
      // Pop node and check tag match
      struct Node* popped_node = pop();
      if(popped_node != NULL && strcmp(popped_node->tag, strtok(&xml_input[i+2], ">")) == 0)
        current_node = (node_stack.top >= 0) ? node_stack.nodes[node_stack.top] : NULL;
      else
        return 0; // Return failure if tag does not match
      i += strlen(popped_node->tag) + 3;
    }
    
    // Check for text node
    else if(isalpha(xml_input[i]))
    {
      // Create new node and set tag and attributes
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
      memset(new_node, 0, sizeof(struct Node));
      strcpy(new_node->tag, strtok(&xml_input[i], "<"));
      new_node->child_count = 0;
      
      // Add as child of current node
      current_node->child = (struct Node*)realloc(current_node->child, (current_node->child_count+1)*sizeof(struct Node));
      current_node->child[current_node->child_count++] = *new_node;
      i += strlen(new_node->tag);
    }
    
    // Move to next character
    else
      i++;
  }
  
  // Return success
  return 1;
}

// Function to push node to stack
void push(struct Node* node)
{
  if(node_stack.top < 50)
    node_stack.nodes[++node_stack.top] = node;
}

// Function to pop node from stack
struct Node* pop()
{
  if(node_stack.top >= 0)
    return node_stack.nodes[node_stack.top--];
  else
    return NULL;
}

// Function to free memory for a node and its children
void free_node(struct Node* node)
{
  if(node->child_count > 0)
  {
    for(int i=0; i<node->child_count; i++)
      free_node(&node->child[i]);
    free(node->child);
  }
  free(node);
}