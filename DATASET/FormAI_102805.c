//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include<stdio.h>

int main(){
    int usedRam = 0;
    int maxRam = 4096;
    int choice;
    int newProcess;

    printf("Welcome to the Happy RAM Monitor!\n\n");

    do{
        printf("Enter a new process memory usage (in MB): ");
        scanf("%d", &newProcess);
        usedRam += newProcess;

        if(usedRam > maxRam){
            printf("Oh no! You've surpassed maximum RAM usage. Please terminate or reduce a process.\n");
            usedRam -= newProcess;
        }else{
            printf("You are currently using %d MB of RAM.\n", usedRam);
        }

        printf("Would you like to add another process? (1 for yes, 0 for no) ");
        scanf("%d", &choice);

    }while(choice != 0);

    printf("\nThank you for using the Happy RAM Monitor! You are currently using %d MB of RAM.\n", usedRam);
    return 0;
}