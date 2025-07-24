//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for storing resume information
struct resume_node {
    char* name;
    int age;
    char* education;
    char* skills;
    char* work_experience;
    struct resume_node* next;
};

// Create a function to parse the resume information and create a linked list
struct resume_node* parse_resume(char* resume_text) {
    struct resume_node* head = NULL;
    struct resume_node* current = NULL;

    // Split the resume text into an array of strings based on the new line character
    char* lines[1000];
    int line_count = 0;
    char* line = strtok(resume_text, "\n");
    while (line != NULL) {
        lines[line_count++] = line;
        line = strtok(NULL, "\n");
    }

    // Loop through each line in the array and create a new node for the linked list
    for (int i = 0; i < line_count; i++) {
        char* line = lines[i];
        struct resume_node* node = malloc(sizeof(struct resume_node));

        // Extract the name, age, education, skills, and work experience from the line
        char* token = strtok(line, ",");
        node->name = malloc(strlen(token) + 1);
        strcpy(node->name, token);

        token = strtok(NULL, ",");
        node->age = atoi(token);

        token = strtok(NULL, ",");
        node->education = malloc(strlen(token) + 1);
        strcpy(node->education, token);

        token = strtok(NULL, ",");
        node->skills = malloc(strlen(token) + 1);
        strcpy(node->skills, token);

        token = strtok(NULL, ",");
        node->work_experience = malloc(strlen(token) + 1);
        strcpy(node->work_experience, token);

        node->next = NULL;

        // Add the node to the linked list
        if (head == NULL) {
            head = node;
            current = head;
        } else {
            current->next = node;
            current = current->next;
        }
    }

    return head;
}

// Create a function to print the resume information in reverse order
void print_resume_reverse(struct resume_node* node) {
    if (node == NULL) {
        return;
    }

    print_resume_reverse(node->next);

    printf("%s, %d, %s, %s, %s\n", node->name, node->age, node->education, node->skills, node->work_experience);
}

int main() {
    char* resume_text = "John Doe,25,Bachelor's Degree,C,C++,Java\nJane Doe,30,Master's Degree,Python,JavaScript,SQL";

    struct resume_node* head = parse_resume(resume_text);
    print_resume_reverse(head);

    return 0;
}