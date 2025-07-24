//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int pid, burst_time;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

void print(Process p[], int size) {
    printf("PID\tBurst Time\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%d\n", p[i].pid, p[i].burst_time);
    }
}

void fcfs(Process p[], int size) {
    printf("\nFirst Come First Serve:\n");
    int t = 0;
    float waiting_time = 0, turnaround_time = 0;
    for(int i=0; i<size; i++) {
        if(t < p[i].burst_time) t = p[i].burst_time;
        else t += p[i].burst_time;
        waiting_time += t - p[i].burst_time;
        turnaround_time += t;
    }
    waiting_time /= size;
    turnaround_time /= size;
    printf("Average waiting time: %.2f\nAverage turnaround time: %.2f\n", waiting_time, turnaround_time);
}

void sjf(Process p[], int size) {
    printf("\nShortest Job First:\n");
    int t = 0;
    float waiting_time = 0, turnaround_time = 0;
    for(int i=0; i<size; i++) {
        int min = i;
        for(int j=i+1; j<size; j++) {
            if(p[j].burst_time < p[min].burst_time) min = j;
        }
        swap(&p[i], &p[min]);
        if(t < p[i].burst_time) t = p[i].burst_time;
        else t += p[i].burst_time;
        waiting_time += t - p[i].burst_time;
        turnaround_time += t;
    }
    waiting_time /= size;
    turnaround_time /= size;
    printf("Average waiting time: %.2f\nAverage turnaround time: %.2f\n", waiting_time, turnaround_time);
}

void rr(Process p[], int size, int q) {
    printf("\nRound Robin:\n");
    int rem[size];
    for(int i=0; i<size; i++) rem[i] = p[i].burst_time;
    int t = 0;
    float waiting_time = 0, turnaround_time = 0;
    int count = 0;
    while(1) {
        int done = 1;
        for(int i=0; i<size; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > q) {
                    t += q;
                    rem[i] -= q;
                }
                else {
                    t += rem[i];
                    waiting_time += t - p[i].burst_time;
                    turnaround_time += t;
                    rem[i] = 0;
                    count++;
                }
            }
        }
        if(done == 1) break;
    }
    waiting_time /= size;
    turnaround_time /= size;
    printf("Average waiting time: %.2f\nAverage turnaround time: %.2f\n", waiting_time, turnaround_time);
}

int main() {
    srand(time(NULL));
    Process p[SIZE];
    for(int i=0; i<SIZE; i++) {
        p[i].pid = i+1;
        p[i].burst_time = rand() % 10 + 1;
    }
    printf("Before sorting:\n");
    print(p, SIZE);
    fcfs(p, SIZE);
    sjf(p, SIZE);
    rr(p, SIZE, 2);
    return 0;
}