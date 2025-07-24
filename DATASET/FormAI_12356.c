//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
  int n, burstTime[20], waitingTime[20], turnAroundTime[20], temp;
  float avgWaitingTime = 0, avgTurnAroundTime = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the burst time for each process: \n");
  for(int i = 0; i < n; i++) {
    printf("Process %d:", i+1);
    scanf("%d", &burstTime[i]);
  }
  //SJF scheduling algorithm
  for(int i = 0; i < n-1; i++) {
    for(int j = i; j < n; j++) {
      if(burstTime[i] > burstTime[j]) {
        temp = burstTime[i];
        burstTime[i] = burstTime[j];
        burstTime[j] = temp;
      }
    }
  }
  waitingTime[0] = 0;
  turnAroundTime[0] = burstTime[0];
  for(int i = 1; i < n; i++) {
    waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    turnAroundTime[i] = waitingTime[i] + burstTime[i];
  }
  printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time");
  for(int i = 0; i < n; i++) {
    printf("\nP[%d]\t%d\t\t%d\t\t%d", i+1, burstTime[i], waitingTime[i], turnAroundTime[i]);
    avgWaitingTime += waitingTime[i];
    avgTurnAroundTime += turnAroundTime[i];
  }
  avgWaitingTime /= n;
  avgTurnAroundTime /= n;
  printf("\n\nAverage Waiting Time: %f", avgWaitingTime);
  printf("\nAverage Turn Around Time: %f\n", avgTurnAroundTime);
  return 0;
}