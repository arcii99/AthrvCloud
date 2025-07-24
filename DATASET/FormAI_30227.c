//FormAI DATASET v1.0 Category: System boot optimizer ; Style: imaginative
// Welcome to BootOptimizer 9000, the most advanced system boot optimizer!
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int bootTime;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to BootOptimizer 9000!\n");
    printf("Please enter your current boot time in seconds: ");
    scanf("%d", &bootTime);

    int optimizedTime = bootTime - (rand() % 30 + 10); // generate a random delay of 10-40 seconds

    if(optimizedTime < 0){
        optimizedTime = 0; // make sure optimized time doesn't go negative
    }

    printf("BootOptimizer 9000 has optimized your system boot time from %d seconds to %d seconds.\n", bootTime, optimizedTime);

    printf("Do you want to apply this optimization permanently? (y/n): ");
    char choice;
    scanf(" %c", &choice); // add space before %c to ignore the new line character

    if(choice == 'y'){
        printf("Applying permanent optimization...\n");
        FILE *fp;
        fp = fopen("boot.ini", "w");
        fprintf(fp, "boot_delay=%d", optimizedTime);
        fclose(fp);
        printf("Permanent optimization applied successfully!\n");
    } else {
        printf("Optimization not applied.\n");
    }

    printf("Thank you for choosing BootOptimizer 9000!\n");

    return 0;
}