//FormAI DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int optimize_boot(int boot_time, int num_options, int* options);

int main()
{
    int boot_time = 100;
    int num_options = 5;
    int options[] = { 10, 20, 30, 40, 50 };
    int optimized_time = optimize_boot(boot_time, num_options, options);
    printf("Optimized boot time: %d seconds", optimized_time);
    return 0;
}

int optimize_boot(int boot_time, int num_options, int* options)
{
    if (num_options == 1)
    {
        if (boot_time % options[0] == 0)
            return boot_time / options[0];
        else
            return -1;
    }
    
    int best_time = -1;
    
    for (int i = 0; i < num_options; i++)
    {
        int sub_time = optimize_boot(boot_time, num_options - 1, options);
        if (sub_time != -1)
        {
            int total_time = sub_time * options[i];
            if (best_time == -1 || total_time < best_time)
                best_time = total_time;
        }
        
        int temp = options[0];
        options[0] = options[i];
        options[i] = temp;
    }
    
    return best_time;
}