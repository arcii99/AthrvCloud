//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

int main()
{
    char rule[10][30], packet[30];
    int i, j, n;

    printf("Enter number of rules in the Firewall: ");
    scanf("%d", &n);

    printf("\nEnter the Firewall rules:\n");
    for(i=0; i<n; i++)
    {
        scanf("%s", rule[i]); //reading the rules
    }

    printf("\nEnter the packet to be checked: ");
    scanf("%s", packet); //reading the packet

    for(i=0; i<n; i++) //iterating through the rules
    {
        int match = 1; //initializing match as true
        for(j=0; j<strlen(packet); j++) //iterating through the packet
        {
            if(packet[j] != rule[i][j])
            {
                match = 0; //if a character mismatches, change match to false and break
                break;
            }
        }
        if(match == 1) //if match is still true, the packet is allowed
        {
            printf("\nPacket Allowed according to Rule: %s", rule[i]);
            break;
        }
    }

    if(i == n) //if all rules are checked and no match was found, deny packet
    {
        printf("\nPacket Denied");
    }

    return 0;
}