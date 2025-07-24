//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#define MAX_BIDS 10
#define MAX_LEN 50
typedef struct {
    char name[MAX_LEN];
    int amount;
} bid;
int main()
{
    int i,n=0,max=0,second=0,max_index=0,second_index=0;
    char item[MAX_LEN];
    bid bids[MAX_BIDS];
    printf("Enter name of the item to be auctioned: ");
    fgets(item,MAX_LEN,stdin);
    printf("Starting bid for %s is $10\n\n",item);
    while(n<MAX_BIDS)
    {
        printf("Enter name of bidder %d: ",n+1);
        fgets(bids[n].name,MAX_LEN,stdin);
        printf("Enter bid amount: ");
        scanf("%d",&bids[n].amount);
        getchar(); //to consume the newline character left by scanf
        printf("%s has placed a bid of $%d on %s\n\n",bids[n].name,bids[n].amount,item);
        if(bids[n].amount>max)
        {
            second=max;
            second_index=max_index;
            max=bids[n].amount;
            max_index=n;
        }
        else if(bids[n].amount>second)
        {
            second=bids[n].amount;
            second_index=n;
        }
        n++;
        printf("Current highest bid is $%d by %s\n",max,bids[max_index].name);
        printf("Second highest bid is $%d by %s\n\n",second,bids[second_index].name);
    }
    printf("\n\nAuction has ended for %s\n",item);
    printf("%s sold to %s for $%d\n",item,bids[max_index].name,max);
    return 0;
}