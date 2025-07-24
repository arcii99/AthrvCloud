//FormAI DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_TASKS_PER_TIME_SLOT 10
#define TIME_SLOTS_PER_DAY 24

typedef struct Task
{
    int id;
    char name[50];
    int time_slot;
    bool is_completed;
} Task;

void print_all_tasks(Task all_tasks[], int num_tasks)
{
    printf("ID\tName\t\t\tTime Slot\tCompleted\n");
    for (int i = 0; i < num_tasks; i++)
    {
        printf("%d\t%-20s%d\t\t%s\n", all_tasks[i].id, all_tasks[i].name, all_tasks[i].time_slot,
               all_tasks[i].is_completed ? "Yes" : "No");
    }
}

void print_tasks_for_time_slot(Task all_tasks[], int num_tasks, int time_slot)
{
    printf("Tasks for Time Slot %d:\n", time_slot);
    printf("ID\tName\t\t\tCompleted\n");
    for (int i = 0; i < num_tasks; i++)
    {
        if (all_tasks[i].time_slot == time_slot)
        {
            printf("%d\t%-20s%s\n", all_tasks[i].id, all_tasks[i].name,
                   all_tasks[i].is_completed ? "Yes" : "No");
        }
    }
}

void mark_task_as_completed(Task all_tasks[], int num_tasks, int task_id)
{
    for (int i = 0; i < num_tasks; i++)
    {
        if (all_tasks[i].id == task_id)
        {
            all_tasks[i].is_completed = true;
        }
    }
}

int main()
{
    srand(time(0)); //seed the random number generator based on current time
    int num_tasks = 50;
    Task all_tasks[num_tasks];
    const char *task_names[] = {"Clean the house", "Do laundry", "Buy groceries", "Make dinner", "Take out the trash",
                                "Read a book", "Watch a movie", "Go for a walk", "Exercise", "Call a friend"};

    // Initialize tasks with random time slots and names from the list of task names
    for (int i = 0; i < num_tasks; i++)
    {
        all_tasks[i].id = i + 1;
        int time_slot = rand() % TIME_SLOTS_PER_DAY;
        all_tasks[i].time_slot = time_slot;
        strcpy(all_tasks[i].name, task_names[rand() % 10]);
        all_tasks[i].is_completed = false;
    }

    printf("Welcome to the Task Scheduler!\n");
    int choice = 0;
    do
    {
        printf("\nMenu:\n");
        printf("1. View all tasks\n");
        printf("2. View tasks for a specific time slot\n");
        printf("3. Mark a task as completed\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                print_all_tasks(all_tasks, num_tasks);
                break;
            case 2:
                printf("Enter the time slot (0-23): ");
                int time_slot;
                scanf("%d", &time_slot);
                print_tasks_for_time_slot(all_tasks, num_tasks, time_slot);
                break;
            case 3:
                printf("Enter the ID of the task to mark as completed: ");
                int task_id;
                scanf("%d", &task_id);
                mark_task_as_completed(all_tasks, num_tasks, task_id);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}