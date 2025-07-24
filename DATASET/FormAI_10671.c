//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
   printf("Welcome to the Happy system administration program!\n");
   printf("This program will make your day happier by automating system administration tasks.\n");
   int choice;
   while(1){
      printf("\nPlease select an option:\n");
      printf("1. Locate and delete all unused files\n");
      printf("2. Optimize disk usage\n");
      printf("3. Check system logs for errors\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice){
         case 1:{
            printf("\nSearching for unused files...\n");
            system("find / -type f -atime +365 -delete");
            printf("Unused files deleted successfully!\n");
            break;
         }
         case 2:{
            printf("\nOptimizing disk usage...\n");
            system("df -h");
            system("sudo apt-get autoclean");
            system("sudo apt-get autoremove");
            printf("Disk usage optimized!\n");
            break;
         }
         case 3:{
            printf("\nChecking system logs for errors...\n");
            system("dmesg | grep error");
            printf("\nSystem logs checked successfully!\n");
            break;
         }
         case 4:{
            printf("\nThank you for using the Happy system administration program. Have a great day ahead!\n");
            exit(0);
         }
         default:{
            printf("\nInvalid choice! Please enter a valid option from the menu.\n");
            break;
         }
      }
   }
   return 0;
}