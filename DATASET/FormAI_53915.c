//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n, k;
    char input[MAX_LEN];
  
    printf("Please input an array of positive integers separated by comma: ");
    fgets(input, MAX_LEN, stdin);
    
    printf("Please input the value of k: ");
    scanf("%d", &k);
    
    n = strlen(input);
    int nums[n];
    int count = 0;
    
    char* token = strtok(input, ",");
    while (token != NULL)
    {
        nums[count++] = atoi(token);
        token = strtok(NULL, ",");
    }
    
    qsort(nums, n, sizeof(int), compare);
    
    int sum = 0;
    int i = n - 1;
    while (k > 0)
    {
        sum += nums[i];
        i--;
        k--;
    }
  
    printf("The sum of the highest %d values is: %d", count, sum);
  
    return 0;
}