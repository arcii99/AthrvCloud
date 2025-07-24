//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
int f[]= {0,1,2,3,4};
int burst_time[]= {8,4,9,5,3};
int arrival_time[]= {1,0,2,4,3};
int turn_around_time[5],waiting_time[5],completion_time[5];
struct process
{
    int pid,burst_time,arrival_time;
    int rt;
};
int queue[100],front=-1,rear=0,ready_queue[100],rq_size=0;
void push(struct process x)
{
    queue[++front]=x.pid;
}
void ready_queue_push(int x)
{
    ready_queue[rq_size++]=x;
}
int pop()
{
    if(front==-1 || front>=rear) return -1;
    return queue[rear++];
}
void replace(int i)
{
    int j,min_index=i;
    for(j=0; j<rq_size; j++)
    {
        if(f[ready_queue[j]]<f[ready_queue[min_index]]) min_index=j;
    }
    queue[++front]=ready_queue[min_index];
    for(j=min_index; j<rq_size-1; j++) ready_queue[j]=ready_queue[j+1];
    rq_size--;
    ready_queue_push(i);
}
int main()
{
    int i,n=5,t=0,prev_idle=0,s=0,incoming_process;
    struct process p[5];
    for(i=0; i<5; i++)
    {
        p[i].pid=i;
        p[i].arrival_time=arrival_time[i];
        p[i].burst_time=burst_time[i];
        p[i].rt=burst_time[i];
    }
    while(1)
    {
        incoming_process=-1;
        for(i=0; i<n; i++)
        {
            if(p[i].arrival_time<=t && p[i].rt>0)
            {
                if(incoming_process==-1) incoming_process=i;
                else if(f[i]<f[incoming_process]) incoming_process=i;
            }
        }
        if(incoming_process==-1 && front==-1) break;
        else if(incoming_process==-1) 
        {
            ready_queue_push(pop());
            s=t-prev_idle;
            prev_idle=t;
        }
        else if(front==-1 && incoming_process!=-1)
        {
            ready_queue_push(incoming_process);
            p[incoming_process].rt--;
            if(p[incoming_process].rt==0)
            {
                completion_time[incoming_process]=t+1;
                turn_around_time[incoming_process]=completion_time[incoming_process]-p[incoming_process].arrival_time;
                waiting_time[incoming_process]=turn_around_time[incoming_process]-p[incoming_process].burst_time;
                s=t-p[incoming_process].arrival_time+1;
                prev_idle=t+1;
                incoming_process=-1;
            }
        }
        else
        {
            if(f[incoming_process]<f[queue[rear]])
            {
                ready_queue_push(pop());
                ready_queue_push(incoming_process);
            }
            else ready_queue_push(incoming_process);
        }
        if(rq_size>0)
        {
            int running_process=ready_queue[0];
            p[running_process].rt--;
            if(p[running_process].rt==0)
            {
                completion_time[running_process]=t+1;
                turn_around_time[running_process]=completion_time[running_process]-p[running_process].arrival_time;
                waiting_time[running_process]=turn_around_time[running_process]-p[running_process].burst_time;
                replace(running_process);
            }
            for(i=1; i<rq_size; i++) replace(ready_queue[i]);
        }
        t++;
    }
    printf("Process ID\tResponse Time\tTurnaround Time\tWaiting Time\tCompletion Time\n");
    for(i=0; i<n; i++) printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,s-turn_around_time[i],turn_around_time[i],waiting_time[i],completion_time[i]);
    return 0;
}