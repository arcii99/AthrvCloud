//FormAI DATASET v1.0 Category: Browser Plugin ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_URL_LENGTH 256

// Function prototypes
void display_menu();
void navigate_to_page(char* current_url);
void display_error_menu();
bool is_valid_url(char* url);

int main()
{
    // Variable declarations
    char current_url[MAX_URL_LENGTH];
    bool is_running = true;
    
    // Initial page
    strcpy(current_url, "https://www.google.com");
    
    // Main loop
    while(is_running)
    {
        // Display menu
        display_menu();
        
        // Get user choice
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        // Handle user choice
        switch(choice)
        {
            case 1:
                navigate_to_page(current_url);
                break;
            case 2:
                printf("\nExiting program...\n");
                is_running = false;
                break;
            default:
                display_error_menu();
        }
    }
    
    return 0;
}

// Function to display menu
void display_menu()
{
    printf("\n---------------\n");
    printf("C Browser Plugin\n");
    printf("---------------\n");
    printf("1. Navigate to page\n");
    printf("2. Exit\n");
}

// Function to navigate to a new page
void navigate_to_page(char* current_url)
{
    // Get new URL from user
    char new_url[MAX_URL_LENGTH];
    printf("\nEnter URL: ");
    scanf("%s", new_url);
    
    // Check if URL is valid
    if(is_valid_url(new_url))
    {
        // Update current URL
        strcpy(current_url, new_url);
        printf("\nNavigating to %s...\n", current_url);
    }
    else
    {
        printf("\nInvalid URL!\n");
    }
}

// Function to display error menu
void display_error_menu()
{
    printf("\nInvalid choice! Please enter a valid choice.\n");
}

// Function to check if a URL is valid
bool is_valid_url(char* url)
{
    // Check if URL starts with "http://" or "https://"
    if(strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0)
    {
        // Check if URL contains a valid domain name (e.g. "google.com")
        char* domain_start = strstr(url, "://") + 3;
        if(strstr(domain_start, ".") != NULL)
        {
            return true;
        }
    }
    
    return false;
}