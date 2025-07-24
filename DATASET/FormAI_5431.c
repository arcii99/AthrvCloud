//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>

#define N 5

int process[N]={1,2,3,4,5};
int burst_time[N]={20,25,15,30,10};
int arrival_time[N]={0,10,20,25,30};
int completion_time[N];
int turn_around_time[N];
int waiting_time[N];
int quantum=5;
int time=0;
int queue[N];
int front=-1,rear=-1;

void enqueue(int process_id)
{
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=process_id;
}

int dequeue()
{
    int temp=queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return temp;
}

void round_robin()
{
    int remaining_burst_time[N];
    for(int i=0;i<N;i++)
        remaining_burst_time[i]=burst_time[i];
    while(front!=-1)
    {
        int curr_process=dequeue();
        if(remaining_burst_time[curr_process]<=quantum)
        {
            time+=remaining_burst_time[curr_process];
            completion_time[curr_process]=time;
            for(int i=0;i<N;i++)
            {
                if(i!=curr_process && arrival_time[i]<=time && remaining_burst_time[i]!=0)
                    enqueue(i);
            }
        }
        else
        {
            time+=quantum;
            remaining_burst_time[curr_process]-=quantum;
            for(int i=0;i<N;i++)
            {
                if(i!=curr_process && arrival_time[i]<=time && remaining_burst_time[i]!=0)
                    enqueue(i);
            }
            enqueue(curr_process);
        }
        if(front==-1 && rear!=-1)
            enqueue(N);
    }
}

void medieval_print()
{
    printf("\n");
    printf(" /$$$$$$   /$$$$$$  /$$$$$$$  /$$$$$$$  /$$   /$$  /$$$$$$ \n");
    printf("|_  $$_/  /$$__  $$| $$__  $$| $$__  $$| $$$ | $$ /$$__  $$\n");
    printf("  | $$   | $$  \\ $$| $$  \\ $$| $$  \\ $$| $$$$| $$| $$  \\ $$\n");
    printf("  | $$   | $$  | $$| $$  | $$| $$  | $$| $$ $$ $$| $$  | $$\n");
    printf("  | $$   | $$  | $$| $$  | $$| $$  | $$| $$  $$$$| $$  | $$\n");
    printf("  | $$   | $$  | $$| $$  | $$| $$  | $$| $$\\  $$$| $$  | $$\n");
    printf(" /$$$$$$|  $$$$$$/| $$  | $$| $$$$$$$/| $$ \\  $$|  $$$$$$/\n");
    printf("|______/ \\______/ |__/  |__/|_______/ |__/  \\__/ \\______/ \n");
    printf("\n");
}

int main()
{
    medieval_print();
    round_robin();
    printf(" -------------------------------------------------------------------\n");
    printf("| Process | Completion Time | Turnaround Time | Waiting Time |  \n");
    printf("|---------|----------------|----------------|--------------|\n");
    for(int i=0;i<N;i++)
    {
        turn_around_time[i]=completion_time[i]-arrival_time[i];
        waiting_time[i]=turn_around_time[i]-burst_time[i];
        printf("|    %d    |        %d       |       %d        |       %d     |\n",process[i],completion_time[i],turn_around_time[i],waiting_time[i]);
    }
    printf(" -------------------------------------------------------------------\n");
    return 0;
}