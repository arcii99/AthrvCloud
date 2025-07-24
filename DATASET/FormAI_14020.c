//FormAI DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100
#define NUM_COMPANIES 5

// Define a struct to hold the company details
struct Company {
    char name[MAX_LEN];
    float share_price;
    float prev_close_price;
    float percent_change;
};

typedef struct Company Company;

// Function to get user input
void get_input(char *input) {
    printf("Enter a company name to track:\n");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\r\n")] = 0; // Remove newline character
}

// Function to convert string to uppercase
void to_uppercase(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = toupper(str[i]);
    }
}

// Function to find company and update details
int update_company(Company *companies, char *name){
    to_uppercase(name); // Convert name to uppercase
    for(int i = 0; i < NUM_COMPANIES; i++){
        char upper_name[MAX_LEN];
        strcpy(upper_name, companies[i].name);
        to_uppercase(upper_name);
        if(strcmp(upper_name, name) == 0){ // If company is found
            printf("Enter today's share price for %s:\n", companies[i].name);
            scanf("%f", &companies[i].share_price);
            printf("Enter yesterday's share price for %s:\n", companies[i].name);
            scanf("%f", &companies[i].prev_close_price);
            companies[i].percent_change = ((companies[i].share_price - companies[i].prev_close_price) / companies[i].prev_close_price) * 100;
            return 1;
        }
    }
    return 0; // Company not found
}

// Function to display company details
void display_company(Company company){
    printf("\nCompany Name: %s\n", company.name);
    printf("Share Price: %.2f\n", company.share_price);
    printf("Previous Close Price: %.2f\n", company.prev_close_price);
    printf("Percent Change: %.2f%%\n", company.percent_change);
}

int main(){
    // Initialize company details
    Company companies[NUM_COMPANIES] = {
        {.name = "APPLE", .share_price = 126.03, .prev_close_price = 123.08},
        {.name = "GOOGLE", .share_price = 2354.28, .prev_close_price = 2345.89},
        {.name = "MICROSOFT", .share_price = 250.14, .prev_close_price = 251.86},
        {.name = "FACEBOOK", .share_price = 314.63, .prev_close_price = 315.57},
        {.name = "TESLA", .share_price = 672.37, .prev_close_price = 677.02}
    };

    char input[MAX_LEN];
    while(1){
        get_input(input);
        if(strcmp(input, "QUIT") == 0) break;
        if(update_company(companies, input) == 0){ // If company is not found
            printf("Company not found. Please try again.\n");
        }
        else{
            for(int i = 0; i < NUM_COMPANIES; i++){ // Display all company details
                display_company(companies[i]);
            }
        }
    }
    return 0;
}