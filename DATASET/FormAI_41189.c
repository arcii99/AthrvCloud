//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    time_t time;
    char description[100];
} Task;

void print_task(Task t) {
    printf("ID: %d\n", t.id);
    printf("Time: %s", ctime(&t.time));
    printf("Description: %s\n\n", t.description);
}

int main() {
    // Create an array of tasks to be executed
    Task tasks[5] = {{1, 1630341600, "Run daily backups"}, 
                     {2, 1630392000, "Send report to boss"}, 
                     {3, 1630424400, "Update website content"}, 
                     {4, 1630438800, "Run database maintenance"}, 
                     {5, 1630401600, "Attend meeting with clients"}};
                     
    // Get current time and calculate time until next hour
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    int seconds_to_next_hour = 60 - timeinfo->tm_sec;
    
    // Schedule tasks
    printf("Scheduling tasks...\n\n");
    for (int i = 0; i < 5; i++) {
        time_t task_time = tasks[i].time - seconds_to_next_hour;
        printf("Task #%d scheduled for %s", tasks[i].id, ctime(&task_time));
    }
    
    // Simulate task execution
    printf("\nExecuting tasks...\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Executing task #%d...\n", tasks[i].id);
        print_task(tasks[i]);
    }
    
    return 0;
}