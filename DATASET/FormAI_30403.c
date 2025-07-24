//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
//CYBERPUNK STYLE GREEDY ALGORITHM

#include <stdio.h>
#include <stdlib.h>

//Function to sort the array in descending order
void Sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Function to find the maximum profit that can be earned with k times transaction
int MaxProfit(int price[], int n, int k)
{
    //If there are no elements in the array, return 0
    if (n == 0)
        return 0;
    
    //If k is greater than half the size of array, then there is no need to repeat transaction k times
    if (k > n/2)
        k = n/2;
        
    int profit = 0;
  
    //Calculating the profit of k times transaction
    for (int i = 0; i < k; i++)
    {
        int buy = 0, sell = 0;
        int j = 0;
        while (j < n-1)
        {
            //Finding the local minimum
            while (j < n-1 && price[j+1] <= price[j])
                j++;
            buy = j;
            
            //Finding the local maximum
            while (j < n && price[j+1] >= price[j])
                j++;
            sell = j;
            
            //Calculating the profit after each transaction
            profit += price[sell] - price[buy];
        }
    }
    return profit;
}

int main()
{
    int n = 10; //Total number of elements
    int price[] = {10, 22, 5, 75, 65, 80, 85, 92, 45, 65}; //Array of prices
    int k = 3; //Number of times transaction can be performed
   
    //Printing the prices before sorting
    printf("Prices before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", price[i]);
    
    //Sorting the prices in descending order
    Sort(price, n);
    
    //Printing the prices after sorting
    printf("\nPrices after sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", price[i]);

    //Calculating the maximum profit that can be earned with k times transaction
    int max_profit = MaxProfit(price, n, k);
    printf("\nMaximum profit with %d transaction: %d", k, max_profit);
    
    return 0;
}