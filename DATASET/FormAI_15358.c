//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include<stdio.h>
#define N 20
 
// Function to find the average waiting time and average turn around time
void findAvgTime(int processes[], int n, int bt[], int quantum){
    int wt[n], tat[n], i, total_wt = 0, total_tat = 0;
 
    // Copy the burst time into another array to keep track of the remaining burst time
    int rem_bt[n];
    for (i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
    int t = 0; // Current time
 
    // Keep traversing the processes until all are done
    while (1){
        int done = 1;  // Checks if all processes are done
 
        // Traverse all processes one by one repeatedly
        for (i = 0 ; i < n; i++){
            // If the remaining burst time of the current process is greater than the quantum
            if (rem_bt[i] > 0){
                done = 0;  // Process is not done yet
 
                // If the burst time is less than or equal to the quantum, finish the process
                if (rem_bt[i] <= quantum){
                    t += rem_bt[i];  // Add the burst time to the current time
 
                    // Set the waiting time for the current process
                    wt[i] = t - bt[i];
 
                    // Set the turn around time for the current process
                    tat[i] = t;
 
                    // Update the remaining burst time to 0 for the current process
                    rem_bt[i] = 0;
                }
                else{
                    // If the burst time is greater than the quantum, use up the quantum time
                    t += quantum;
 
                    // Update the remaining burst time for the current process
                    rem_bt[i] -= quantum;
                }
            }
        }
        if (done == 1)  // Break the loop if all processes are done
          break;
    }
 
    // Calculate the total waiting time and turn around time by adding up their individual values
    for (i = 0; i < n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
    }
 
    // Calculate the average waiting time and turn around time and print it out
    float avg_wait_time = (float) total_wt / (float) n;
    float avg_tat = (float) total_tat / (float) n;
    printf("Average waiting time = %f\n", avg_wait_time);
    printf("Average turnaround time = %f\n", avg_tat);
}
 
 
// Driver code
int main(){
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    int burst_time[] = {10, 5, 8};
 
    int quantum = 2;
    findAvgTime(processes, n, burst_time, quantum);
    return 0;
}