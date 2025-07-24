//FormAI DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_logo();
void display_loading(int n);
void run_startup_optimizer();

int main()
{
    display_logo();
    run_startup_optimizer();
    return 0;
}

void display_logo()
{
    printf("******************************\n");
    printf("*    C System Optimizer     *\n");
    printf("******************************\n");
    printf("\n");
}

void display_loading(int n)
{
    int i;
    printf("Optimizing ");
    for (i = 0; i < n; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void run_startup_optimizer()
{
    srand(time(NULL));
    
    // Randomly shuffle boot order
    int boot_order[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int x = rand() % 4;
        int temp = boot_order[i];
        boot_order[i] = boot_order[x];
        boot_order[x] = temp;
    }
    
    printf("Optimizing startup programs...\n");
    for (int i = 0; i < 4; i++) {
        switch (boot_order[i]) {
            case 0:
                printf("   Disabling Microsoft Teams startup\n");
                break;
            case 1:
                printf("   Disabling Slack startup\n");
                break;
            case 2:
                printf("   Disabling Spotify startup\n");
                break;
            case 3:
                printf("   Disabling Chrome startup\n");
                break;
        }
        display_loading(3);
    }
    
    printf("Startup optimization complete!\n");
}