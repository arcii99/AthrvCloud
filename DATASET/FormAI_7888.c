//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include<stdio.h>  
#include<stdlib.h>  
int main()  
{  
    int n,i,qty,choice;
    float rate,total=0.0;  
    char item[20];  
    printf("Welcome to C Cafe Billing System!\n");  
    
    do{
        printf("\nEnter number of items: ");  
        scanf("%d",&n);  
        for(i=1;i<=n;i++)  
        {  
            printf("\n%d. Enter Item Name: ",i);  
            scanf("%s",&item);  
            printf("\nEnter Quantity: ");  
            scanf("%d",&qty);  
            printf("\nEnter Rate: ");  
            scanf("%f",&rate);  
            total+=qty*rate;  
        }  
        printf("\nTotal Amount to be paid: Rs.%.2f\n",total);  
        printf("\nDo you want to place another order? Press 1 for YES, 0 for NO.\n");
        scanf("%d",&choice);
        total=0;
    }while(choice!=0);
    printf("\nThank you for using C Cafe Billing System!\n");  
    return 0;  
}