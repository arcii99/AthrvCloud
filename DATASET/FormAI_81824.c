//FormAI DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Define task structure */
typedef struct task {
    int id;
    char name[50];
    int priority;
} Task;

/* Define node structure for doubly linked list */
typedef struct node {
    Task task;
    struct node *prev;
    struct node *next;
} Node;

/* Define global variables for doubly linked list and total number of tasks */
Node *head = NULL;
Node *tail = NULL;
int num_tasks = 0;

/* Function to insert a task into the scheduler */
void insert_task(int id, char name[], int priority) {
    /* Create new task and set data */
    Task new_task;
    new_task.id = id;
    strcpy(new_task.name, name);
    new_task.priority = priority;
    
    /* Create new node and set data */
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->task = new_task;
    new_node->next = NULL;
    
    /* Check if list is empty */
    if (head == NULL) {
        tail = new_node;
        head = tail;
        num_tasks++;
    } else {
        /* Traverse list to find position to insert new node */
        Node *current = head;
        
        while (current != NULL) {
            if (new_task.priority > current->task.priority) {
                /* Insert node before current node */
                if (current == head) {
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                    num_tasks++;
                } else {
                    new_node->prev = current->prev;
                    new_node->next = current;
                    current->prev->next = new_node;
                    current->prev = new_node;
                    num_tasks++;
                }
                
                break;
            } else if (current == tail) {
                /* Insert node at end of list */
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
                num_tasks++;
                break;
            }
            
            current = current->next;
        }
    }
}

/* Function to remove a task from the scheduler */
void remove_task(int id) {
    /* Traverse list to find task with given id */
    Node *current = head;
    
    while (current != NULL) {
        if (current->task.id == id) {
            /* Remove node from list */
            if (current == head) {
                head = current->next;
                head->prev = NULL;
                num_tasks--;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = NULL;
                num_tasks--;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                num_tasks--;
            }
            
            free(current);
            printf("Task with ID %d has been removed.\n", id);
            return;
        }
        
        current = current->next;
    }
    
    /* Task with given id was not found */
    printf("Task with ID %d does not exist.\n", id);
}

/* Function to print all tasks in the scheduler */
void print_tasks() {
    /* Traverse list and print task information */
    Node *current = head;
    
    printf("Total number of tasks: %d\n", num_tasks);
    
    while (current != NULL) {
        printf("Task ID: %d\n", current->task.id);
        printf("Task Name: %s\n", current->task.name);
        printf("Task Priority: %d\n", current->task.priority);
        printf("\n");
        
        current = current->next;
    }
}

int main() {
    /* Insert tasks into scheduler */
    insert_task(1, "Task A", 2);
    insert_task(2, "Task B", 3);
    insert_task(3, "Task C", 1);
    insert_task(4, "Task D", 2);
    
    /* Print tasks in scheduler */
    print_tasks();
    
    /* Remove task from scheduler */
    remove_task(2);
    
    /* Print tasks in scheduler */
    print_tasks();
    
    /* Remove task that does not exist */
    remove_task(5);
    
    /* Print tasks in scheduler */
    print_tasks();
    
    return 0;
}