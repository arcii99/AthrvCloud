//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

void check(char buffer[], int size);

int main()
{
    char buffer[MAX_SIZE];
  
    while(1)
    {
        printf("\nEnter command: ");
        fgets(buffer, MAX_SIZE, stdin);
    
        check(buffer, strlen(buffer));
    }

    return 0;
}

void check(char buffer[], int size)
{   
    int i; 
    int count = 0;
    char keywords[10][10]={"rm", "sudo", "passwd", "netstat", "ps", "top", "kill", "reboot", "shutdown", "system"};

    buffer[size-1]='\0';
    
    for (i=0; i<10; i++)
    {
           if (strstr(buffer,keywords[i]))
           {
                count++;
           }
    }
    
    if (count >= 3)
    {
        printf("\033[0;31m"); // Changes text color to red
        printf("\nALERT: Intrusion detected\n"); 
        printf("\033[0m\n"); // Changes text color back to default
        exit(0);
    }
}