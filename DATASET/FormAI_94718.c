//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char log[100];
    int count=0;
    FILE *fp;
    fp=fopen("log.txt","r");
    if(fp==NULL)
    {
        printf("Error opening the file!");
        return 0;
    }
    else
    {
        while(fgets(log,100,fp)!=NULL) // reading logs line by line
        {
            char *tokens[10]; 
            int i=0;
            char *token=strtok(log," "); // splitting the log into tokens based on ' '
            while(token!=NULL)
            {
                tokens[i++]=token; // storing all the tokens in an array
                token=strtok(NULL," ");
            }
            if((strstr(tokens[5],"ATTACK")!=NULL) || (strstr(tokens[6],"ATTACK")!=NULL)) // checking for attack keyword in the log
            {
                printf("\nSuspicious activity detected! The log is as follows\n%s",log);
                printf("\nFurther detailed analysis will be done in some time!");
                count++; // counting number of attacks
            }
        }
        if(count==0) // if no attacks are detected
        {
            printf("\nNo attacks detected!");
        }
    }
    return 0;
}