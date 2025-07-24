//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Implementing circular queue for storing logs
#define MAX_SIZE 10
char queue[MAX_SIZE][100];
int front = -1, rear = -1;

void printQueue() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Logs: ");
    for(int i=front; i != rear; i = (i+1) % MAX_SIZE)
        printf("%s ",queue[i]);
    printf("%s\n", queue[rear]);
}

// Function to detect intrusion
bool detectIntrusion(char* log) {
    int count = 0;
    for(int i=0; i<strlen(log); ++i)
        if(log[i] == ':')
            count++;
    return count > 4;
}

int main() {
    printf("Welcome to Intrusion Detection System\n");
    char log[1000];
    while(true) {
        printf("Enter log: ");
        fgets(log, sizeof(log), stdin);
        log[strcspn(log, "\n")] = 0;    // Removing trailing newline
        if(!detectIntrusion(log)) {
            if(front == -1 && rear == -1)
                front = rear = 0;
            else {
                rear = (rear+1)%MAX_SIZE;
                if(front == rear) {
                    front = (front+1)%MAX_SIZE;
                }
            }
            strcpy(queue[rear], log);
            printQueue();
        }
        else {
            printf("Intrusion detected!\n");
            printf("Logs: ");
            for(int i=front; i != rear; i = (i+1) % MAX_SIZE)
                printf("%s ",queue[i]);
            printf("%s\n", queue[rear]);
            front = -1, rear = -1;
            exit(0);
        }
    }
    return 0;
}