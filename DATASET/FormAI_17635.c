//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include<stdio.h>

struct finance {
    char item[20];
    float amount;
};

int main() {
    int num_items;
    float total_expenses = 0;
    printf("How many items do you want to add to your finance planner?\n");
    scanf("%d", &num_items);
    struct finance planner[num_items];

    //filling up the planner
    for (int i = 0; i < num_items; i++) {
        printf("\nEnter Item Name: ");
        scanf("%s", planner[i].item);
        printf("Enter Amount: ");
        scanf("%f", &planner[i].amount);
        total_expenses += planner[i].amount;
    }

    //displaying the planner
    printf("\n\n---------------Your Finance Planner---------------\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s |\n", "Item", "Amount");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("| %-20s | %-10.2f |\n", planner[i].item, planner[i].amount);
    }
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10.2f |\n", "Total Expenses", total_expenses);
    printf("--------------------------------------------------\n");
    return 0;
}