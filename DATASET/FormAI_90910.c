//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
  int start;
  int end;
  int profit;
} Job;

int compare_jobs(const void *a, const void *b) {
  Job *job1 = (Job *)a;
  Job *job2 = (Job *)b;
  return job2->profit - job1->profit;
}

int main() {
  int N, M;
  Job jobs[MAX_N];
  int machines[MAX_M] = {0};
  int total_profit = 0;

  printf("Enter the number of jobs: ");
  scanf("%d", &N);
  printf("Enter the number of machines: ");
  scanf("%d", &M);

  printf("Enter the start time, end time, and profit of each job:\n");
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &jobs[i].start, &jobs[i].end, &jobs[i].profit);
  }

  qsort(jobs, N, sizeof(Job), compare_jobs);

  for (int i = 0; i < N; i++) {
    int machine_found = 0;
    for (int j = jobs[i].start; j <= jobs[i].end; j++) {
      if (machines[j] == 0) {
        machines[j] = jobs[i].profit;
        machine_found = 1;
        break;
      }
    }
    if (machine_found == 1) {
      total_profit += jobs[i].profit;
    }
  }

  printf("Total profit: %d\n", total_profit);

  return 0;
}