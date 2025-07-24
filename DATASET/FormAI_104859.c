//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>

int main()
{
    float income, expenses, savings;
    char name[50], job_title[50];
    int age, retirement_age;

    printf("Hi there! My name is Personal Finance Planner. What's your name?\n");
    scanf("%s", name);

    printf("Nice to meet you %s! Can you tell me your job title?\n", name);
    scanf("%s", job_title);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("What is your annual income?\n");
    scanf("%f", &income);

    printf("What are your annual expenses?\n");
    scanf("%f", &expenses);

    savings = income - expenses;

    printf("Based on your responses, it looks like your name is %s and you work as a %s. You are %d years old and have an annual income of %.2f. Your annual expenses are %.2f, leaving you with a savings of %.2f.\n", name, job_title, age, income, expenses, savings);

    printf("At what age do you want to retire?\n");
    scanf("%d", &retirement_age);

    float years_until_retirement = retirement_age - age;
    float retirement_savings_goal = expenses * (years_until_retirement * 12);
    float monthly_savings_goal = retirement_savings_goal / (years_until_retirement * 12);

    printf("To retire at %d, you need to save %.2f by then. That means you need to save %.2f every month until then.\n", retirement_age, retirement_savings_goal, monthly_savings_goal);

    return 0;
}