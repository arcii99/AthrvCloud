//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Use current time as seed for random generator

  // Initialize arrival and burst times for 5 processes randomly
  int arrival_times[5], burst_times[5];
  for (int i = 0; i < 5; i++) {
    arrival_times[i] = rand() % 10;
    burst_times[i] = rand() % 5 + 1;
  }

  printf("Surreal CPU Scheduling Algorithm Results:\n");

  // First-Come, First-Served (FCFS)
  printf("FCFS (First-Come, First-Served):\n");

  int current_time = arrival_times[0];
  for (int i = 0; i < 5; i++) {
    printf("Process %d: %d - %d\n", i+1, current_time, current_time + burst_times[i]);
    current_time += burst_times[i];
  }

  // Shortest Job First (SJF)
  printf("SJF (Shortest Job First):\n");

  int remaining_burst_times[5], completed = 0;
  for (int i = 0; i < 5; i++) {
    remaining_burst_times[i] = burst_times[i];
  }

  while (completed < 5) {
    // Find the process with the shortest remaining burst time
    int shortest_time = 100, shortest_index;
    for (int i = 0; i < 5; i++) {
      if (arrival_times[i] <= current_time && remaining_burst_times[i] < shortest_time) {
        shortest_time = remaining_burst_times[i];
        shortest_index = i;
      }
    }

    printf("Process %d: %d - %d\n", shortest_index+1, current_time, current_time + shortest_time);

    current_time += shortest_time;
    remaining_burst_times[shortest_index] = 0;
    completed++;
  }

  // Round Robin
  printf("RR (Round Robin):\n");

  int quantum = 2;
  int remaining_times[5];
  for (int i = 0; i < 5; i++) {
    remaining_times[i] = burst_times[i];
  }

  while (completed < 5) {
    for (int i = 0; i < 5; i++) {
      if (arrival_times[i] <= current_time && remaining_times[i] > 0) {
        if (remaining_times[i] <= quantum) {
          printf("Process %d: %d - %d\n", i+1, current_time, current_time + remaining_times[i]);
          current_time += remaining_times[i];
          remaining_times[i] = 0;
          completed++;
        } else {
          printf("Process %d: %d - %d\n", i+1, current_time, current_time + quantum);
          current_time += quantum;
          remaining_times[i] -= quantum;
        }
      }
    }
  }

  return 0;
}