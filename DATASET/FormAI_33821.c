//FormAI DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struct to hold task information */
struct Task {
    int id;
    int priority;
    int duration;
};

/* Function to print task information */
void printTask(struct Task task) {
    printf("Task ID: %d | Priority: %d | Duration: %d seconds\n", task.id, task.priority, task.duration);
}

/* Function to generate a random task */
struct Task generateTask(int id) {
    struct Task task;
    task.id = id;
    task.priority = rand() % 10 + 1; // Random priority between 1 and 10
    task.duration = rand() % 10 + 1; // Random duration between 1 and 10 seconds
    return task;
}

/* Task Queue */
struct Queue {
    struct Task tasks[100];
    int front;
    int rear;
    int size;
};

/* Function to create a queue */
struct Queue createQueue() {
    struct Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;
    return queue;
}

/* Function to check if queue is empty */
int isEmpty(struct Queue queue) {
    return queue.size == 0;
}

/* Function to check if queue is full */
int isFull(struct Queue queue) {
    return queue.size == 100;
}

/* Function to add a task to the queue */
void enqueue(struct Queue *queue, struct Task task) {
    if (isFull(*queue)) {
        printf("Queue is full. Cannot add task.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % 100;
    queue->tasks[queue->rear] = task;
    queue->size++;
}

/* Function to remove a task from the queue */
struct Task dequeue(struct Queue *queue) {
    if (isEmpty(*queue)) {
        printf("Queue is empty. Cannot dequeue task.\n");
        struct Task emptyTask = { -1, -1, -1};
        return emptyTask;
    }
    struct Task task = queue->tasks[queue->front];
    queue->front = (queue->front + 1) % 100;
    queue->size--;
    return task;
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    struct Queue taskQueue = createQueue(); // Create task queue

    int taskCounter = 1; // Counter to hold current task ID

    printf("Adding 10 random tasks to the queue...\n");
    for (int i = 0; i < 10; i++) {
        struct Task task = generateTask(taskCounter++);
        enqueue(&taskQueue, task);
        printTask(task);
    }

    printf("\nRunning tasks...\n");
    int totalTime = 0;
    while (!isEmpty(taskQueue)) {
        struct Task task = dequeue(&taskQueue);
        printf("\nStarting task...\n");
        printTask(task);
        for (int i = 0; i < task.duration; i++) {
            printf("Task in progress... %d seconds\n", i + 1);
            sleep(1); // Simulate task taking time to complete
        }
        printf("Task complete.\n");
        totalTime += task.duration;
    }

    printf("\nAll tasks complete. Total time taken: %d seconds.\n", totalTime);

    return 0;
}