//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define MAX_CARS 100

typedef struct car {
    int direction;
    int position;
} Car;

typedef struct queue {
    Car cars[MAX_CARS];
    int start;
    int end;
} Queue;

void init_queue(Queue *queue) {
    queue->start = 0;
    queue->end = 0;
}

int is_queue_empty(Queue *queue) {
    return queue->start == queue->end;
}

int is_queue_full(Queue *queue) {
    return (queue->end + 1) % MAX_CARS == queue->start;
}

void enqueue(Queue *queue, Car car) {
    if (is_queue_full(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->cars[queue->end] = car;
    queue->end = (queue->end + 1) % MAX_CARS;
}

Car dequeue(Queue *queue) {
    if (is_queue_empty(queue)) {
        printf("Queue is empty!\n");
        Car empty_car = {0, 0};
        return empty_car;
    }
    Car car = queue->cars[queue->start];
    queue->start = (queue->start + 1) % MAX_CARS;
    return car;
}

int main() {
    int green_light = NORTH;

    Queue north_queue;
    init_queue(&north_queue);

    Queue east_queue;
    init_queue(&east_queue);

    Queue south_queue;
    init_queue(&south_queue);

    Queue west_queue;
    init_queue(&west_queue);

    int time = 0;

    while (time < 100) {
        // Add cars to queues
        if (time % 10 == 0) {
            if (rand() % 2 == 0) {
                enqueue(&north_queue, (Car){NORTH, rand() % 10});
            }
            if (rand() % 2 == 0) {
                enqueue(&east_queue, (Car){EAST, rand() % 10});
            }
            if (rand() % 2 == 0) {
                enqueue(&south_queue, (Car){SOUTH, rand() % 10});
            }
            if (rand() % 2 == 0) {
                enqueue(&west_queue, (Car){WEST, rand() % 10});
            }
        }

        // Change traffic signal
        if (time % 20 == 0) {
            green_light = (green_light + 1) % 4;
        }

        // Move cars through intersection
        Car car;
        switch (green_light) {
            case NORTH:
                if (!is_queue_empty(&north_queue)) {
                    car = dequeue(&north_queue);
                    printf("Car at position %d going north through intersection.\n", car.position);
                }
                break;
            case EAST:
                if (!is_queue_empty(&east_queue)) {
                    car = dequeue(&east_queue);
                    printf("Car at position %d going east through intersection.\n", car.position);
                }
                break;
            case SOUTH:
                if (!is_queue_empty(&south_queue)) {
                    car = dequeue(&south_queue);
                    printf("Car at position %d going south through intersection.\n", car.position);
                }
                break;
            case WEST:
                if (!is_queue_empty(&west_queue)) {
                    car = dequeue(&west_queue);
                    printf("Car at position %d going west through intersection.\n", car.position);
                }
                break;
        }

        time++;
    }

    return 0;
}