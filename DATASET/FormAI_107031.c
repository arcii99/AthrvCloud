//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("Welcome to C RAM Usage Monitor!\n");
    int total_ram = 0, free_ram = 0, used_ram = 0;
    char cmd[50] = "free -m | grep Mem";
    FILE *fp = popen(cmd, "r");
    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "Mem: %d %d %d",
            &total_ram, &used_ram, &free_ram);
    }
    pclose(fp);
    printf("Total RAM: %dMB\n", total_ram);
    printf("Used RAM: %dMB\n", used_ram);
    printf("Free RAM: %dMB\n", free_ram);
    while(1){
        printf("\nRefreshing...\n");
        sleep(5);
        FILE *fp = popen(cmd, "r");
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            sscanf(buffer, "Mem: %d %d %d",
                &total_ram, &used_ram, &free_ram);
        }
        pclose(fp);
        printf("Total RAM: %dMB | Used RAM: %dMB | Free RAM: %dMB\n",total_ram, used_ram, free_ram);
    }
    return 0;
}