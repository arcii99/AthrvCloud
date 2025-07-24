//FormAI DATASET v1.0 Category: System boot optimizer ; Style: creative
#include <stdio.h>
#define MAX_BOOT_TIME 60
#define MIN_OPTIMIZED_BOOT_TIME 5

int main()
{
    int boot_time;
    printf("Enter current boot time: ");
    scanf("%d", &boot_time);
    
    if (boot_time > MAX_BOOT_TIME)
    {
        printf("Starting boot optimization...\n");
        int optimized_boot_time = boot_time - MIN_OPTIMIZED_BOOT_TIME;
        printf("Optimized boot time: %d\n", optimized_boot_time);
        
        if (optimized_boot_time <= MIN_OPTIMIZED_BOOT_TIME)
        {
            printf("Optimization done! Rebooting system...\n");
            system("reboot");
        }
        else
        {
            printf("Re-optimizing...\n");
            int re_optimized_boot_time = optimized_boot_time - MIN_OPTIMIZED_BOOT_TIME;
            printf("Re-optimized boot time: %d\n", re_optimized_boot_time);
            
            if (re_optimized_boot_time <= MIN_OPTIMIZED_BOOT_TIME)
            {
                printf("Re-optimization complete! Rebooting system...\n");
                system("reboot");
            }
            else
            {
                printf("Boot optimization failed. Manually optimize system or contact support.\n");
            }
        }
    }
    else
    {
        printf("System boot time is within acceptable range. No optimization needed.");
    }
    
    return 0;
}