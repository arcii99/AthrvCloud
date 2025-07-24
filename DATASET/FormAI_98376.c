//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int task_id;
    char task_name[50];
    int priority;
    int duration;
} Task;

typedef struct node {
    Task task;
    struct node* next;
} Node;

typedef struct queue {
    Node *front, *rear;
    int size;
} Queue;

void initialize_queue(Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue *q, Task t) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->task = t;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

Task dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        exit(1);
    }

    Node *temp_node = q->front;
    Task t = temp_node->task;

    q->front = q->front->next;
    q->size--;
    free(temp_node);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return t;
}

int is_queue_empty(Queue *q) {
    return q->front == NULL;
}

void display_task(Task t) {
    printf("Task ID: %d\n", t.task_id);
    printf("Task Name: %s\n", t.task_name);
    printf("Task Priority: %d\n", t.priority);
    printf("Task Duration: %d\n\n", t.duration);
}

void display_queue(Queue *q) {
    Node *temp_node = q->front;
    while (temp_node != NULL) {
        display_task(temp_node->task);
        temp_node = temp_node->next;
    }
}

void insert_task(Queue queues[], Task t) {
    int queue_index = t.priority - 1;
    enqueue(&queues[queue_index], t);
}

void execute_task(Task t) {
    printf("Executing Task %d - %s for %d seconds...\n", t.task_id, t.task_name, t.duration);
    sleep(t.duration);
    printf("Task %d - %s completed!\n", t.task_id, t.task_name);
}

void run_scheduler(Queue queues[], int num_queues) {
    srand(time(NULL));
    while (1) {
        int queue_index = rand() % num_queues;
        if (!is_queue_empty(&queues[queue_index])) {
            Task t = dequeue(&queues[queue_index]);
            execute_task(t);
            break;
        }
    }
}

int main() {
    int num_queues = 3;
    Queue queues[num_queues];

    for (int i = 0; i < num_queues; i++) {
        initialize_queue(&queues[i]);
    }

    Task t1 = {1, "Email Response", 1, 5};
    Task t2 = {2, "Phone Call", 2, 7};
    Task t3 = {3, "Report Generation", 3, 10};
    Task t4 = {4, "Meeting", 1, 8};

    insert_task(queues, t1);
    insert_task(queues, t2);
    insert_task(queues, t3);
    insert_task(queues, t4);

    printf("Before scheduling:\n\n");
    for (int i = 0; i < num_queues; i++) {
        printf("Queue %d:\n", i+1);
        display_queue(&queues[i]);
        printf("\n");
    }

    run_scheduler(queues, num_queues);

    printf("\nAfter scheduling:\n\n");
    for (int i = 0; i < num_queues; i++) {
        printf("Queue %d:\n", i+1);
        display_queue(&queues[i]);
        printf("\n");
    }

    return 0;
}