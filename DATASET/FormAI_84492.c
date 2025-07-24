//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include<stdio.h>

int main(){

    char processname[] = {'P', 'R', 'O', 'C', 'E', 'S', 'S'};
    int arrivaltime[] = {0, 1, 2, 3, 4, 5, 6};
    int bursttime[] = {5, 2, 4, 3, 2, 1, 6};
    int remainingtime[] = {5, 2, 4, 3, 2, 1, 6};
    int completiontime[] = {0, 0, 0, 0, 0, 0, 0};
    int waitingtime[] = {0, 0, 0, 0, 0, 0, 0};
    int turnaroundtime[] = {0, 0, 0, 0, 0, 0, 0};
    int quantum = 2;

    printf("\n\tCPU Scheduling Algorithm - Round Robin\n\n");

    printf("Process Name\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\t Turnaround Time\n");

    int i = 0, time = 0, flag = 0;

    while(1){
        flag = 0;

        for(int j=0; j<7; j++){
            if(remainingtime[j] > 0){

                if(remainingtime[j] > quantum){
                    flag = 1;
                    remainingtime[j] -= quantum;
                    time += quantum;
                }
                else{
                    flag = 1;
                    time += remainingtime[j];
                    completiontime[j] = time;
                    remainingtime[j] = 0;
                }

                printf("\t%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processname[j], 
                    arrivaltime[j], bursttime[j], completiontime[j], completiontime[j]-arrivaltime[j]-bursttime[j], completiontime[j]-arrivaltime[j]);

            }
        }

        if(flag == 0){
            break;
        }
    }

    return 0;
}