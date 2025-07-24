//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include<stdio.h> 
#include<stdlib.h> 

// defining a structure to hold process information
struct process 
{ 
   int pid; // process ID 
   int bt; // burst time
   int at; // arrival time
}; 

// function for sorting processes based on their arrival time
int sort_by_arrival(const void *a, const void *b) 
{ 
    struct process *p1 = (struct process *)a; 
    struct process *p2 = (struct process *)b; 
    return p1->at - p2->at; 
} 

// function for implementing Priority scheduling algorithm
void priority_scheduling(struct process *pr, int n) 
{ 
    // sort the processes based on their arrival time
    qsort(pr, n, sizeof(struct process), sort_by_arrival); 
    
    //calculate wait time for each process
    int wt[n], total_wt = 0, rt[n], total_rt = 0, tt[n], total_tt = 0;
    for(int i=0;i<n;i++)
    {
        rt[i]=pr[i].bt;
    }
    
    int current_time = pr[0].at;
    int completed_processes = 0;
    
    while(completed_processes < n)
    {
        // Find process with highest priority among the available processes at current time
        int max_priority = -1;
        int chosen_process = -1;
        for(int i=0; i<n; i++)
        {
            if(pr[i].at <= current_time && rt[i] > 0 && pr[i].pid != chosen_process)
            {
                if(pr[i].bt > max_priority)
                {
                    max_priority = pr[i].bt;
                    chosen_process = pr[i].pid;
                }
            }
        }
        
        // update wait time and remaining time
        if(chosen_process != -1)
        {
            wt[chosen_process] = current_time - pr[chosen_process].at;
            rt[chosen_process] = 0;
            total_wt += wt[chosen_process];
            tt[chosen_process] = pr[chosen_process].bt + wt[chosen_process];
            total_tt += tt[chosen_process];
            completed_processes++;
        }
        else
        {
            current_time++;
        }
    }
    
    // print the results
    printf("Process\t\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",pr[i].pid,wt[pr[i].pid],tt[pr[i].pid]);
    }
    printf("Average Waiting Time = %.2f\n",(float)total_wt/n);
    printf("Average Turnaround Time = %.2f\n",(float)total_tt/n);
}

void main() 
{ 
    struct process pr[4] = {{0, 3, 0}, {1, 6, 2}, {2, 4, 3}, {3, 2, 5}}; // example processes
    
    printf("Processes before applying Priority Scheduling\n");
    printf("Process\t\tBurst Time\tArrival Time\n");
    for(int i=0;i<4;i++) 
    { 
        printf("%d\t\t%d\t\t%d\n",pr[i].pid,pr[i].bt,pr[i].at); 
    } 
    
    printf("\n\nApplying Priority Scheduling...\n");
    priority_scheduling(pr, 4); // call the function for implementing priority scheduling
}