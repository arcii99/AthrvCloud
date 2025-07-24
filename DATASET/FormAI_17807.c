//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include<stdio.h>
#include<string.h>

int main(){
    char date_in[20];
    printf("Enter the date in natural language: ");
    fgets(date_in, 20, stdin); // Reading input from user
    
    if (strcmp(date_in, "today") == 0){
        printf("The date is: %s", __DATE__); // __DATE__ macro gives current date
    }
    
    else if (strcmp(date_in, "tomorrow") == 0){
        printf("The date is: %s", __DATE__); // Grabbing the current date
        int day, month, year;
        sscanf(__DATE__, "%s %d %d", &month, &day, &year); // Extracting the parts of the current date
        day += 1; // Adding one day
        printf("The date tomorrow is: %d %s %d \n", day, month, year); // Printing the modified date
    }
    
    else{
        printf("Invalid or unsupported natural language date. \n");
    }

    return 0;
}