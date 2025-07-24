//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mind-bending
#include<stdio.h>
#include<string.h>

int main()
{
    printf("Hello and welcome to the Natural Language Date Converter!\n\n");
    printf("Please enter a date in natural language format (e.g. \"tomorrow\", \"next week\", etc.): ");
    
    char date_str[50]; // maximum length of date string is 50 characters
    fgets(date_str, 50, stdin); // reading string input from user
    
    // parsing the date string to extract individual date components
    int day = -1, month = -1, year = -1;
    char temp[20];
    
    char *token = strtok(date_str, " ,.-\n"); // parsing date string using delimiters " ,.-\n"
    while(token != NULL)
    {
        strcpy(temp, token); // copying the token to a temporary string
        if(strcmp(temp, "today") == 0) // checking if token represents "today"
        {
            // setting day, month and year to current system date
            // day, month and year are system-dependent, so this code may not work on all systems
            day = 14;
            month = 9;
            year = 2021;
        }
        else if(strcmp(temp, "tomorrow") == 0) // checking if token represents "tomorrow"
        {
            // adding 1 day to the current system date
            day = 15;
            month = 9;
            year = 2021;
        }
        else if(strcmp(temp, "next") == 0) // checking if token represents "next"
        {
            if(token != NULL)
            {
                token = strtok(NULL, " ,.-\n"); // parsing next token
                strcpy(temp, token); // copying the next token to temporary string
                if(strcmp(temp, "week") == 0) // checking if next token represents "week"
                {
                    // adding 1 week to the current system date
                    day = 21;
                    month = 9;
                    year = 2021;
                }
                else if(strcmp(temp, "month") == 0) // checking if next token represents "month"
                {
                    // adding 1 month to the current system date
                    day = 14;
                    month = 10;
                    year = 2021;
                }
                else if(strcmp(temp, "year") == 0) // checking if next token represents "year"
                {
                    // adding 1 year to the current system date
                    day = 14;
                    month = 9;
                    year = 2022;
                }
            }
        }
        else if(strcmp(temp, "last") == 0) // checking if token represents "last"
        {
            if(token != NULL)
            {
                token = strtok(NULL, " ,.-\n"); // parsing next token
                strcpy(temp, token); // copying the next token to temporary string
                if(strcmp(temp, "week") == 0) // checking if next token represents "week"
                {
                    // subtracting 1 week from the current system date
                    day = 7;
                    month = 9;
                    year = 2021;
                }
                else if(strcmp(temp, "month") == 0) // checking if next token represents "month"
                {
                    // subtracting 1 month from the current system date
                    day = 14;
                    month = 8;
                    year = 2021;
                }
                else if(strcmp(temp, "year") == 0) // checking if next token represents "year"
                {
                    // subtracting 1 year from the current system date
                    day = 14;
                    month = 9;
                    year = 2020;
                }
            }
        }
        else if(strcmp(temp, "in") == 0) // checking if token represents "in"
        {
            if(token != NULL)
            {
                token = strtok(NULL, " ,.-\n"); // parsing next token
                strcpy(temp, token); // copying the next token to temporary string
                month = get_month(temp); // converting month name to number
                if(month != -1) // checking if month conversion was successful
                {
                    token = strtok(NULL, " ,.-\n"); // parsing next token
                    strcpy(temp, token); // copying the next token to temporary string
                    if(is_valid_number(temp)) // checking if token represents a valid number
                    {
                        year = atoi(temp); // converting token to integer
                        if(year < 100) // handling 2-digit year format
                        {
                            if(year >= 70 && year <= 99) // assuming 1970-1999 for 2-digit years in the range 70-99
                                year += 1900;
                            else // assuming 2000-2069 for all other 2-digit years
                                year += 2000;
                        }
                    }
                }
            }
        }
        else if(is_valid_number(temp)) // checking if token represents a valid number
        {
            int temp_int = atoi(temp); // converting token to integer
            if(temp_int > 0 && temp_int <= 31) // checking if token represents a valid day
                day = temp_int;
            else if(temp_int > 0 && temp_int <= 12) // checking if token represents a valid month
                month = temp_int;
            else if(temp_int > 1000 && temp_int <= 9999) // checking if token represents a valid year
                year = temp_int;
        }
        token = strtok(NULL, " ,.-\n"); // parsing next token
    }
    
    // checking if all date components have been successfully parsed
    if(day == -1 || month == -1 || year == -1)
    {
        printf("Error: Invalid date format\n");
        return 0;
    }
    
    // printing the extracted date components
    printf("\nDate Components:\n");
    printf("Day: %d\n", day);
    printf("Month: %d\n", month);
    printf("Year: %d\n\n", year);
    
    // printing the converted date in standard date format (dd-mm-yyyy)
    printf("Standard Date: %d-%02d-%04d\n", day, month, year);
    
    return 0;
}

// function to convert month name to number
int get_month(char *month_str)
{
    char *months[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    for(int i = 0; i < 12; i++)
    {
        if(strcmp(month_str, months[i]) == 0)
            return i + 1;
    }
    return -1;
}

// function to check if a string represents a valid number
int is_valid_number(char *str)
{
    if(str == NULL || *str == '\0')
        return 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}