//FormAI DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include<stdio.h>
#include<string.h>

int main() {
    int num_of_items, i;
    float total_amount = 0;

    printf("Wow! Let's track your expenses today!\n");
    printf("How many items have you purchased today?\n");
    scanf("%d", &num_of_items);
    
    char items[num_of_items][50];
    float amounts[num_of_items];

    for(i = 0; i < num_of_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i]);
        printf("Enter the amount of item %d (%s): ", i+1, items[i]);
        scanf("%f", &amounts[i]);
        total_amount += amounts[i];
    }

    printf("\nYour expenses for today are as follows:\n");

    for(i = 0; i < num_of_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i], amounts[i]);
    }
    
    printf("Wow! You spent a total of $%.2f today. That's a huge amount!\n", total_amount);

    return 0;
}