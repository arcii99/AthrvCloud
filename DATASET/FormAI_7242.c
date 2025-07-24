//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Surprise! Welcome to the system administration script!\n");

    printf("\n========== CPU Info ==========\n");
    system("cat /proc/cpuinfo");

    printf("\n========== RAM Info ==========\n");
    system("cat /proc/meminfo");

    printf("\n========== Disk Space ==========\n");
    system("df -h");

    printf("\n========== Running Processes ==========\n");
    system("ps ax");

    printf("\n========== Network Configuration ==========\n");
    system("ifconfig");

    printf("\n========== Firewall Status ==========\n");
    system("systemctl status firewalld");

    printf("\n========== Integrated GPU Info ==========\n");
    system("lspci | grep -i vga");

    printf("\n========== System Update Check ==========\n");
    system("yum check-update");

    printf("\n========== Active SSH Sessions ==========\n");
    system("w");

    printf("\n========== Disk Usage By Directory ==========\n");
    system("du -hs /* | sort -rh");

    printf("\n========== User Management ==========\n");
    system("cat /etc/passwd");
    system("cat /etc/shadow");

    printf("\n========== Network Connection Status ==========\n");
    system("netstat -tulpn");

    printf("\n========== Current Time ==========\n");
    system("date");

    printf("\n========== Available Memory ==========\n");
    system("free -m | grep Mem");

    printf("\n========== Docker Info ==========\n");
    system("docker info");

    printf("\n========== Active Cron Jobs ==========\n");
    system("crontab -l");

    printf("\nWhew! That was a lot of code to run! But worry not, your system is in good hands. Thank you for using our program!\n");

    return 0;
}