//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void fcfs(int pid[], int bt[], int n){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\n FCFS Scheduling");
    printf("\nProcess \t Burst Time \t Waiting Time \t Turnaround Time");
    for(int i=0;i<n;i++){
        printf("\n %d \t\t %d \t\t %d \t\t %d",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time=%f",(float)total_wt/(float)n);
    printf("\nAverage turnaround time=%f",(float)total_tat/(float)n);
}

void sjf(int pid[], int bt[], int n){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    insertionSort(bt,n);
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("\n SJF Scheduling");
    printf("\nProcess \t Burst Time \t Waiting Time \t Turnaround Time");
    for(int i=0;i<n;i++){
        printf("\n %d \t\t %d \t\t %d \t\t %d",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time=%f",(float)total_wt/(float)n);
    printf("\nAverage turnaround time=%f",(float)total_tat/(float)n);
}

int main(){
    int n=5;
    int pid[]={1,2,3,4,5};
    int bt[]={8,4,5,3,6};
    fcfs(pid,bt,n);
    sjf(pid,bt,n);
    return 0;
}