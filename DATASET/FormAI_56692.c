//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include<stdio.h>

//Defining a recursive function to calculate the total cost
float calc_cost(int n){
    float cost;
    if(n==0)
        //Base case, if the number of items is 0, return 0 cost
        return 0;
    else{
        int item_no, quantity;
        //Taking input of item number and quantity for each item
        printf("Enter item number and quantity for item %d : ",n);
        scanf("%d %d",&item_no, &quantity);
        switch(item_no){
            case 1: cost = quantity * 10.0;
                    break;
            case 2: cost = quantity * 20.0;
                    break;
            case 3: cost = quantity * 30.0;
                    break;
            default:cost = 0.0; //If entered item number is invalid, set the cost to 0
        }
        //Recursive call to the same function for the remaining items
        return cost + calc_cost(n-1);
    }
}
int main(){
    int n;
    printf("Welcome to C Cafe\n");
    printf("Enter the number of items: ");
    scanf("%d",&n);
    //Calling the calc_cost function to calculate the total cost
    float total_cost = calc_cost(n);
    printf("Total cost is %.2f\n",total_cost);
    printf("Thank you for visiting C Cafe\n");
    return 0;
}