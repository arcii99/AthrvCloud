//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void displayMenu(){
    printf("------ SYSTEM ADMINISTRATION MENU ------\n");
    printf("1- Check disk space\n");
    printf("2- Check RAM usage\n");
    printf("3- Check CPU usage\n");
    printf("4- Restart server\n");
    printf("5- Exit\n");
    printf("---------------------------------------\n");
}

void checkDiskSpace(){
    system("df -h");
}

void checkRAMUsage(){
    system("free -m");
}

void checkCPUUsage(){
    system("top");
}

void restartServer(){
    printf("Are you sure you want to restart the server? [Y/N]: ");
    char choice = getchar();
    if(choice == 'Y' || choice == 'y'){
        system("shutdown -r now");
    }else{
        printf("Restart cancelled.\n");
    }
}

int main(){
    char userChoice;

    do{
        displayMenu();
        printf("Enter your choice: ");
        userChoice = getchar();
        getchar(); // Clear the input buffer

        switch(userChoice){
            case '1': checkDiskSpace(); break;
            case '2': checkRAMUsage(); break;
            case '3': checkCPUUsage(); break;
            case '4': restartServer(); break;
            case '5': printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    }while(userChoice != '5');

    return 0;
}