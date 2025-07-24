//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo sys_info;
    long total_ram, free_ram, used_ram;
    char ch;
    
    do {
        sysinfo(&sys_info);
        total_ram = sys_info.totalram / 1024;
        free_ram = sys_info.freeram / 1024;
        used_ram = total_ram - free_ram;
        
        printf("\n****** RAM USAGE MONITOR ******\n");
        printf("Total RAM: %ld KB\n", total_ram);
        printf("Used RAM: %ld KB\n", used_ram);
        printf("Free RAM: %ld KB\n", free_ram);
        
        sleep(1); // Wait for 1 second before checking again
        
        printf("\nDo you want to check RAM usage again? (Y/N) \n");
        scanf(" %c", &ch);
    } while(ch == 'Y' || ch == 'y');
    
    printf("Exiting program...");
    return 0;
}