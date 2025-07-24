//FormAI DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    int id;
    int delay;
    void (*func)(void);
    struct Task *next;
} Task;

Task *head = NULL;
int task_count = 0;

void add_task(Task *new_task) {
    if (head == NULL) {
        head = new_task;
        return;
    }

    Task *current_task = head;
    while (current_task->next != NULL) {
        current_task = current_task->next;
    }
    current_task->next = new_task;
}

void remove_task(int id) {
    if (head == NULL) {
        printf("No tasks to remove.\n");
        return;
    }

    if (head->id == id) {
        head = head->next;
        free(head);
        return;
    }

    Task *current_task = head;
    while (current_task->next != NULL && current_task->next->id != id) {
        current_task = current_task->next;
    }

    if (current_task->next == NULL) {
        printf("Task not found.\n");
        return;
    }

    Task *temp = current_task->next;
    current_task->next = current_task->next->next;
    free(temp);
}

void execute_task(Task *task) {
    task->func();
}

void execute_all_tasks() {
    Task *current_task = head;
    while (current_task != NULL) {
        if (current_task->delay == 0) {
            execute_task(current_task);
            remove_task(current_task->id);
            task_count--;
        } else {
            current_task->delay--;
        }
        current_task = current_task->next;
    }
}

void print_menu() {
    printf("\n");
    printf("------------ MENU ------------\n");
    printf("1. Add task\n");
    printf("2. Remove task\n");
    printf("3. Show tasks\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

void task1() {
    printf("Task 1 executed!\n");
}

void task2() {
    printf("Task 2 executed!\n");
}

void task3() {
    printf("Task 3 executed!\n");
}

int main() {
    srand(time(NULL));

    int menu_choice;
    int task_id = 0;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                task_id++;
                int delay = rand() % 10;
                Task *new_task = (Task *) malloc(sizeof(Task));
                new_task->id = task_id;
                new_task->delay = delay;
                int task_choice = rand() % 3;
                switch (task_choice) {
                    case 0:
                        new_task->func = task1;
                        break;
                    case 1:
                        new_task->func = task2;
                        break;
                    case 2:
                        new_task->func = task3;
                        break;
                }
                add_task(new_task);
                printf("Task added with ID: %d\n", new_task->id);
                task_count++;
                break;
            case 2:
                if (task_count > 0) {
                    printf("Enter task ID to remove: ");
                    int id_to_remove;
                    scanf("%d", &id_to_remove);
                    remove_task(id_to_remove);
                    task_count--;
                } else {
                    printf("No tasks to remove.\n");
                }
                break;
            case 3:
                printf("\n");
                printf("------ TASKS ------\n");
                Task *current_task = head;
                while (current_task != NULL) {
                    printf("Task ID: %d, Delay: %d\n", current_task->id, current_task->delay);
                    current_task = current_task->next;
                }
                printf("--------------------\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        execute_all_tasks();
    }
}