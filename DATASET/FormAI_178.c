//FormAI DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include<stdio.h>

int main(){

    printf("Welcome to the C System boot optimizer!\n");
    printf("Please enter the boot time in seconds: ");
    int boot_time;
    scanf("%d", &boot_time);

    if(boot_time < 60){
        printf("Your system is already optimized for fast boot time.");
    }
    else if(boot_time >= 60 && boot_time < 120){
        printf("Your boot time is a bit slow. Here are some optimization tweaks:\n");
        printf("- Disable unnecessary startup programs.\n");
        printf("- Check for malware infections.\n");
        printf("- Defragment your disk drives.\n");
    }
    else if(boot_time >= 120 && boot_time < 180){
        printf("Your boot time is quite slow. Here are some optimization tweaks:\n");
        printf("- Disable unnecessary startup programs.\n");
        printf("- Check for malware infections.\n");
        printf("- Defragment your disk drives.\n");
        printf("- Upgrade to a faster storage device (e.g. SSD).\n");
    }
    else if(boot_time >= 180){
        printf("Your boot time is unacceptable. Here are some optimization tweaks:\n");
        printf("- Disable unnecessary startup programs.\n");
        printf("- Check for malware infections.\n");
        printf("- Defragment your disk drives.\n");
        printf("- Upgrade to a faster storage device (e.g. SSD).\n");
        printf("- Increase your system's RAM.\n");
    }
    return 0;
}