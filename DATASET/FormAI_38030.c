//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
    int completed;
};

void main(){
    int n,i,j,time_quanta,sum_bt=0,sum_turnaround_time=0,sum_waiting_time=0;
    float average_turnaround_time,average_waiting_time;
  
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
  
    struct process p[n];
  
    for(i=0;i<n;i++){
        printf("\nEnter details of process %d\n",i+1);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d",&p[i].burst_time);
        p[i].pid=i+1;
        p[i].remaining_time=p[i].burst_time;
        p[i].completed=0;
        sum_bt+=p[i].burst_time;
    }
  
    printf("\nEnter time quantum: ");
    scanf("%d",&time_quanta);
  
    int current_time=0,completed_processes=0;
  
    printf("\nGantt Chart:\n\n");
  
    while(completed_processes!=n){
        for(i=0;i<n;i++){
            if(p[i].remaining_time<=time_quanta && p[i].completed==0){
                current_time+=p[i].remaining_time;
                p[i].remaining_time=0;
                p[i].completed=1;
                printf("|  P%d  |",p[i].pid);
                p[i].turnaround_time=current_time-p[i].arrival_time;
                p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
                sum_turnaround_time+=p[i].turnaround_time;
                sum_waiting_time+=p[i].waiting_time;
                completed_processes++;
            }
            else if(p[i].completed==0){
                current_time+=time_quanta;
                p[i].remaining_time-=time_quanta;
                printf("|  P%d  |",p[i].pid);
            }
        }
    }
  
    printf("\n\nProcess  Burst Time  Arrival Time  Turnaround Time  Waiting Time\n");
  
    for(i=0;i<n;i++){
        printf("   P%d         %d           %d             %d               %d\n",
            p[i].pid,p[i].burst_time,p[i].arrival_time,p[i].turnaround_time,p[i].waiting_time);
    }
  
    average_turnaround_time=(float)sum_turnaround_time/n;
    average_waiting_time=(float)sum_waiting_time/n;
  
    printf("\nAverage Turnaround Time: %0.2f",average_turnaround_time);
    printf("\nAverage Waiting Time: %0.2f",average_waiting_time);
}