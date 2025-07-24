//FormAI DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Task struct for our scheduler
typedef struct Task {
    char name[20];
    int priority;
    int deadline;
    int time_to_complete;
} Task;

// Returns a random number between min and max
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Prints the stats for a task
void print_task(Task task) {
    printf("Task: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Deadline: %d\n", task.deadline);
    printf("Time to complete: %d\n", task.time_to_complete);
}

int main() {
    // Seed random generator with current time
    srand(time(NULL));

    // Prepare our tasks (4 in total)
    Task tasks[4];
    strcpy(tasks[0].name, "Hunt for food");
    tasks[0].priority = 1;
    tasks[0].deadline = 2;
    tasks[0].time_to_complete = 1;

    strcpy(tasks[1].name, "Collect firewood");
    tasks[1].priority = 2;
    tasks[1].deadline = 6;
    tasks[1].time_to_complete = 2;

    strcpy(tasks[2].name, "Search for lost sheep");
    tasks[2].priority = 3;
    tasks[2].deadline = 4;
    tasks[2].time_to_complete = 3;

    strcpy(tasks[3].name, "Repair the castle wall");
    tasks[3].priority = 4;
    tasks[3].deadline = 8;
    tasks[3].time_to_complete = 4;

    printf("*** Tasks before scheduling ***\n");
    for (int i=0; i<4; i++) {
        print_task(tasks[i]);
        printf("\n");
    }

    // Schedule the tasks
    for (int i=0; i<4; i++) {
        int index = i;
        int smallest_deadline = tasks[i].deadline;

        // Find the task with the smallest deadline
        for (int j=i+1; j<4; j++) {
            if (tasks[j].deadline < smallest_deadline) {
                index = j;
                smallest_deadline = tasks[j].deadline;
            }
        }

        // Swap the tasks
        Task temp = tasks[i];
        tasks[i] = tasks[index];
        tasks[index] = temp;
    }

    printf("*** Tasks after scheduling ***\n");
    for (int i=0; i<4; i++) {
        print_task(tasks[i]);
        printf("\n");
    }

    // Run the tasks
    for (int i=0; i<4; i++) {
        printf("Starting task: %s\n", tasks[i].name);
        printf("Time to complete: %d\n", tasks[i].time_to_complete);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Deadline: %d\n", tasks[i].deadline);

        // Wait for the task to complete
        int progress = 0;
        while (progress < tasks[i].time_to_complete) {
            progress++;
            printf("Task %s progress: %d/%d\n", tasks[i].name, progress, tasks[i].time_to_complete);
        }

        // Calculate success probability based on priority and deadline
        int success_probability = (tasks[i].priority + tasks[i].deadline) * 10;
        int roll = random_range(1, 100);

        // Check if the task was successful or not
        if (roll <= success_probability) {
            printf("Task %s was successful!\n", tasks[i].name);
        } else {
            printf("Task %s failed. The consequences will be dire!\n", tasks[i].name);
        }

        printf("\n");
    }

    return 0;
}