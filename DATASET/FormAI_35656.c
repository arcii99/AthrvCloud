//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int income, rent, food, savings;
    int left_over = 0;

    printf("Greetings, kind sir or madam. May I inquire as to thy name?\n");
    scanf("%s", name);

    printf("Hail, %s. Pray tell, how much gold doth thou earn per month?\n", name);
    scanf("%d", &income);

    printf("I see. And how much gold doth thou spend on rent, peradventure?\n");
    scanf("%d", &rent);

    printf("And how much gold is spent on victuals and other necessities, worthy %s?\n", name);
    scanf("%d", &food);

    printf("Finally, how much gold is saved for the future, esteemed %s?\n", name);
    scanf("%d", &savings);

    left_over = income - rent - food - savings;

    printf("Verily, here is thy personal finance plan:\n");
    printf("-----------------------------------------\n");
    printf("Income:\t\t%d\n", income);
    printf("Rent:\t\t%d\n", rent);
    printf("Food:\t\t%d\n", food);
    printf("Savings:\t%d\n", savings);

    if (left_over > 0) {
        printf("Left over:\t%d\n", left_over);
        printf("Might I suggest that thou tuck away more gold, %s, to prepare for the unknown future?\n", name);
    } else if (left_over < 0) {
        printf("Deficit:\t%d\n", -left_over);
        printf("Might I suggest that thou cut back on expenses, %s, so as to not deplete thy coffers?\n", name);
    } else {
        printf("No left over.\nGood work, %s, for budgeting thy finances so prudently!\n", name);
    }

    return 0;
}