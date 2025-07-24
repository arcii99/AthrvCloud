//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

/* randomly generate the process details */
int pid = 12345;
char name[] = "process";
char user[] = "user";
float cpu = 30.4;
float mem = 50.6;

int main() {
    printf("Irregular System Process Viewer\n");
    printf("PID\tName\tUser\tCPU\tMemory\n");
    printf("%d\t%s\t%s\t%.1f%%\t%.1fMB\n", pid, name, user, cpu, mem);
    
    /* randomly generate more process details */
    int pids[] = {54321, 67890, 24680, 13579};
    char *names[] = {"process2", "process3", "process4", "process5"};
    char *users[] = {"user2", "user3", "user4", "user5"};
    float cpus[] = {42.3, 15.6, 66.7, 98.1};
    float mems[] = {75.8, 28.9, 83.2, 42.5};
    
    /* print the additional process details */
    for (int i=0; i<4; i++) {
        printf("%d\t%s\t%s\t%.1f%%\t%.1fMB\n", pids[i], names[i], users[i], cpus[i], mems[i]);
    }
    
    printf("Enter PID to view details: ");
    int selected_pid;
    scanf("%d", &selected_pid);
    
    /* randomly generate details for the selected process */
    char *selected_name = "selected_process";
    char *selected_user = "selected_user";
    float selected_cpu = 80.1;
    float selected_mem = 120.3;
    
    /* print the details for the selected process */
    printf("\nPID\tName\tUser\tCPU\tMemory\n");
    printf("%d\t%s\t%s\t%.1f%%\t%.1fMB\n", selected_pid, selected_name, selected_user, selected_cpu, selected_mem);
    
    return 0;
}