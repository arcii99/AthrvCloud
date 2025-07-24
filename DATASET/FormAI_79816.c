//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the XML Parsing program!\n");
    printf("Initializing parser....\n");

    int num_tags = 0;
    char* tag = (char*)malloc(sizeof(char)*20);
    char** values = (char**)malloc(sizeof(char*)*20);
    for(int i=0;i<20;i++)
        values[i] = (char*)malloc(sizeof(char)*20);

    printf("Enter the number of tags for parsing: ");
    scanf("%d",&num_tags);

    printf("\nAwesome! Enter the tags below:\n");
    for(int i=0;i<num_tags;i++)
    {
        printf("Enter tag %d: ",i+1);
        scanf("%s",tag);
        for(int j=0;j<20;j++)
            printf("-");
        printf("\nYou entered: <%s>\n",tag);
        printf("Now enter the value for tag <%s>: ",tag);
        scanf("%s",values[i]);
        for(int j=0;j<20;j++)
            printf("-");
        printf("\nValue for <%s> is set to: %s\n\n",tag,values[i]);
    }

    printf("\n***Parsing successful!***\n");
    printf("\nHere is the parsed data:\n");
    printf("-----------------------------------------\n");
    for(int i=0;i<num_tags;i++)
        printf("<%s>%s</%s>\n",tag,values[i],tag);
    printf("-----------------------------------------\n");

    printf("\nThank you for using the XML Parser program!\n");
    free(tag);
    for(int i=0;i<20;i++)
        free(values[i]);
    free(values);
    return 0;
}