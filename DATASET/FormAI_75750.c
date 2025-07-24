//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    CYBERPUNK TASK SCHEDULER
*/

typedef struct Task {
    char name[50];
    int priority;
    int time_to_complete;
} Task;

typedef struct ListNode {
    Task task;
    struct ListNode *next;
} ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;

void create_task(char name[], int priority, int time_to_complete) {
    Task new_task;
    strcpy(new_task.name, name);
    new_task.priority = priority;
    new_task.time_to_complete = time_to_complete;

    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->task = new_task;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
}

void delete_task(char name[]) {
    ListNode *current_node = head;
    ListNode *previous_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->task.name, name) == 0) {
            if (current_node == head) {
                head = current_node->next;
            }
            else if (current_node == tail) {
                tail = previous_node;
                tail->next = NULL;
            }
            else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

void display_tasks() {
    int index = 1;
    ListNode *current_node = head;

    printf("CURRENT TASKS:\n");
    while (current_node != NULL) {
        printf("%d. %s (Priority: %d, Time to complete: %d min)\n", index, current_node->task.name, current_node->task.priority, current_node->task.time_to_complete);
        current_node = current_node->next;
        index++;
    }
}

void execute_tasks() {
    while (head != NULL) {
        ListNode *highest_priority_node = head;
        ListNode *previous_node = head;
        ListNode *current_node = head->next;

        while (current_node != NULL) {
            if (current_node->task.priority > highest_priority_node->task.priority) {
                highest_priority_node = current_node;
                previous_node = current_node;
            }
            previous_node = current_node;
            current_node = current_node->next;
        }

        printf("Executing task: %s\n", highest_priority_node->task.name);
        sleep(highest_priority_node->task.time_to_complete * 60);
        delete_task(highest_priority_node->task.name);
    }
}

int main() {
    // add some tasks to the scheduler
    create_task("Steal corporate secrets", 10, 20);
    create_task("Hack government database", 8, 30);
    create_task("Infiltrate rival gang's hideout", 5, 10);
    create_task("Assassinate enemy target", 9, 15);
    create_task("Rescue kidnapped ally", 7, 25);

    // display tasks
    display_tasks();

    // execute tasks
    execute_tasks();

    printf("All tasks complete.\n");

    return 0;
}