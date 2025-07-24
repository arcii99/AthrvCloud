//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include<stdio.h>

int main()
{
    int n;
    printf("Enter the number of baggage: "); //ask the user for the number of baggage
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter weight of baggage %d: ",i+1); //ask the user for the weight of each baggage
        scanf("%d",&arr[i]);
    }
    
    int totalWeight=0;
    for(int i=0;i<n;i++)
    {
        totalWeight+=arr[i]; //calculate the total weight of the baggage
    }
    
    printf("Total weight of the baggage: %d\n",totalWeight);
    
    if(totalWeight>25000)
    {
        printf("Baggage overweight. Please remove some items.\n");
    }
    else
    {
        printf("Baggage accepted. Please proceed to the gate.\n");
    }
    
    return 0;
}