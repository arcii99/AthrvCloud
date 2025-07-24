//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main() 
{ 
    char c;
    int count = 0;

    printf("Welcome to the post-apocalyptic RAM usage monitor!\n\n");
    printf("This program will monitor your RAM usage to ensure you're making the most of your resources in these tough times.\n\n");

    while(1) 
    { 
        system("clear"); // clear the screen

        FILE* fp = fopen("/proc/meminfo", "r"); // open the meminfo file

        if(fp == NULL) 
        { 
            printf("Error opening file\n"); 
            exit(0); 
        } 

        // read the meminfo file line by line
        while(fgets(&c, sizeof(c), fp)) 
        { 
            count++;

            // print out the line every 10th time
            if(count == 10) 
            { 
                printf("%s", &c); 
                count = 0; 
            } 
        } 

        // close the file
        fclose(fp); 

        // wait for 1 second before checking again
        sleep(1); 
    } 

    return 0; 
}