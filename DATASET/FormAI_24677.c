//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char command[100], output[100];
    int ram_usage;
    
    while(1) // continuously monitor RAM usage
    {
        printf("Monitoring RAM usage...\n");
        strcpy(command, "free -m | awk 'NR==2{printf \"Used: %s MB (%.2f%%)\\n\", $3,$3*100/$2 }'"); // command to get RAM usage in MB and %
        FILE* fp = popen(command, "r"); // open command in read mode
        
        if (fp == NULL) // check if command executed correctly
        {
            printf("Error while getting RAM usage.");
            exit(1);
        }
        
        fgets(output, sizeof(output), fp); // read output of command
        pclose(fp); // close command
        
        printf("%s\n", output); // print RAM usage
        
        ram_usage = atoi(output + 6); // convert RAM usage in MB to int
        if(ram_usage > 75) // if RAM usage is over 75%
        {
            printf("RAM usage over 75%%! Killing some processes...\n");
            system("ps -A | grep -v \"monitor\" | awk '{print $1}' | xargs kill -9"); // kill all processes except this monitor program
            printf("Processes killed. RAM usage should now be under control.\n");
        }
        
        sleep(30); // wait for 30 seconds before checking RAM usage again
    }
    
    return 0;
}