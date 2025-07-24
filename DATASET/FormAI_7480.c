//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    char cmd[50];
    int cpu_usage, rand_num, i;
    srand(time(0));

    printf("Welcome to the CPU Usage Monitor!\n");
    while(1){
        rand_num = rand() % 10 + 1;
        if(rand_num == 1){
            printf("Your CPU usage is currently at: ");
            sprintf(cmd, "ps aux | awk 'NR != 1 { s +=$3 }; END {print s}'");
            cpu_usage = system(cmd);
            printf("%d%%\n", cpu_usage);
        }
        else if(rand_num == 2){
            printf("Your system uptime is: ");
            sprintf(cmd, "uptime | awk '{print $3}'");
            system(cmd);
        }
        else if(rand_num == 3){
            printf("Your system load average is: ");
            sprintf(cmd, "uptime | awk '{print $10}' | cut -d, -f1");
            system(cmd);
        }
        else if(rand_num == 4){
            printf("Your RAM usage is currently at: ");
            sprintf(cmd, "free | awk '/Mem/{printf(\"%d%%\",$3/$2*100.0)}'");
            system(cmd);
            printf("\n");
        }
        else if(rand_num == 5){
            printf("Top 5 processes by CPU usage: \n");
            sprintf(cmd, "ps aux --sort=-%cpu | awk 'NR<=6 {print $0}'");
            system(cmd);
        }
        else if(rand_num == 6){
            printf("Top 5 processes by memory usage: \n");
            sprintf(cmd, "ps aux --sort=-%mem | awk 'NR<=6 {print $0}'");
            system(cmd);
        }
        else if(rand_num == 7){
            printf("Your disk usage is currently at: ");
            sprintf(cmd, "df -h | awk '$NF==\"/\"{printf \"%d%%\", $3/$2*100}'");
            system(cmd);
            printf("\n");
        }
        else if(rand_num == 8){
            printf("Current users connected: ");
            sprintf(cmd, "who | wc -l");
            system(cmd);
            printf("\n");
        }
        else if(rand_num == 9){
            printf("Your system IP addresses: ");
            sprintf(cmd, "hostname -I");
            system(cmd);
        }
        else if(rand_num == 10){
            printf("Current date and time: ");
            sprintf(cmd, "date");
            system(cmd);
        }
        sleep(5);
    }
    return 0;
}