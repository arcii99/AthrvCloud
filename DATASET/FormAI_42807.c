//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include<stdio.h>
#define MAX 100
//Function to sort the bags according to their destination
void sort_luggage_dest(char luggage[][MAX], int n)
{
    int i, j;
    char temp[MAX];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(luggage[i], luggage[j])>0)
            {
                strcpy(temp, luggage[i]);
                strcpy(luggage[i], luggage[j]);
                strcpy(luggage[j], temp);
            }
        }
    }
}

//Function to display the bags
void display_luggage(char luggage[][MAX], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%s\n", luggage[i]);
    }
}

int main()
{
    int i, n;
    char luggage[MAX][MAX];
    printf("Enter the number of bags: ");
    scanf("%d", &n);
    printf("Enter the destination of the bags:\n");
    for(i=0; i<n; i++)
    {
        scanf("%s", luggage[i]);
    }
    printf("List of bags before sorting:\n");
    display_luggage(luggage, n);
    sort_luggage_dest(luggage, n);
    printf("List of bags after sorting:\n");
    display_luggage(luggage, n);
    return 0;
}