//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include<stdio.h>

int main(){

// Welcome Message

puts("\nWelcome to C Disk Space Analyzer by [Your Name]!\n");

// Initializing the necessary variables

int totalSpace, usedSpace, remainingSpace;

// Getting the values for the variables

printf("Enter the total space of your disk in GB:\n");
scanf("%d", &totalSpace);

printf("Enter the used space of your disk in GB:\n");
scanf("%d", &usedSpace);

// Calculating the remaining space

remainingSpace = totalSpace - usedSpace;

// Displaying the output

printf("\nTotal space in your disk is %d GB\n", totalSpace);
printf("Used space in your disk is %d GB\n", usedSpace);
printf("Remaining space in your disk is %d GB\n", remainingSpace);

// Checking if the space is enough for new files

if(remainingSpace > 5){

printf("\nYou have enough disk space to save new files!\n");

}

else{

printf("\nSorry, you do not have enough space to save new files.");

}

return 0;

}