//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
//A C Secure Password Generator Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//function declarations
void get_password_details(int* password_length, int* uppercase_count, int* lowercase_count, int* number_count, int* special_count);
char* generate_password(int password_length, int uppercase_count, int lowercase_count, int number_count, int special_count);

int main(void)
{
    //seed random number generator
    srand(time(NULL));
    
    //variables to store password details
    int password_length, uppercase_count, lowercase_count, number_count, special_count;
    
    //get password details from user
    get_password_details(&password_length, &uppercase_count, &lowercase_count, &number_count, &special_count);
    
    //generate password
    char* password = generate_password(password_length, uppercase_count, lowercase_count, number_count, special_count);
    
    //print generated password
    printf("Your secure password is: %s\n", password);
    
    //free allocated memory
    free(password);
    
    return 0;
}

void get_password_details(int* password_length, int* uppercase_count, int* lowercase_count, int* number_count, int* special_count)
{
    //prompt user for password length
    printf("Enter desired password length (minimum 8 characters): ");
    scanf("%d", password_length);
    
    //ensure password length is at least 8 characters
    if (*password_length < 8)
    {
        printf("Password length must be at least 8 characters.\n");
        //retry getting password length
        get_password_details(password_length, uppercase_count, lowercase_count, number_count, special_count);
        return;
    }
    
    //prompt user for number of uppercase letters
    printf("Enter desired number of uppercase letters: ");
    scanf("%d", uppercase_count);
    
    //prompt user for number of lowercase letters
    printf("Enter desired number of lowercase letters: ");
    scanf("%d", lowercase_count);
    
    //prompt user for number of digits
    printf("Enter desired number of digits: ");
    scanf("%d", number_count);
    
    //prompt user for number of special characters
    printf("Enter desired number of special characters: ");
    scanf("%d", special_count);
    
    //ensure password requirements can be met
    if (*uppercase_count + *lowercase_count + *number_count + *special_count > *password_length)
    {
        printf("Password requirements cannot be met within desired password length.\n");
        //retry getting password details
        get_password_details(password_length, uppercase_count, lowercase_count, number_count, special_count);
        return;
    }
}

char* generate_password(int password_length, int uppercase_count, int lowercase_count, int number_count, int special_count)
{
    //allocate memory for password string
    char* password = (char*)malloc(sizeof(char)*(password_length + 1));
    password[password_length] = '\0'; //set null terminator
    
    //array of available character types
    char available_characters[][13] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz", "0123456789", "~!@#$%^&*()_+-="};
    int num_available_character_types = 4; //number of available character types
    
    //char arrays to store characters for each type of character
    char uppercase_letters[27] = {'\0'};
    char lowercase_letters[27] = {'\0'};
    char numbers[11] = {'\0'};
    char special_characters[15] = {'\0'};
    
    //fill char arrays with available characters
    strcat(uppercase_letters, available_characters[0]);
    strcat(lowercase_letters, available_characters[1]);
    strcat(numbers, available_characters[2]);
    strcat(special_characters, available_characters[3]);
    
    //variables to keep track of how many characters have been added to password
    int password_uppercase_count = 0;
    int password_lowercase_count = 0;
    int password_number_count = 0;
    int password_special_count = 0;
    
    //loop through each character of password
    for (int i = 0; i < password_length; i++)
    {
        //choose a random character type
        int random_character_type = rand() % num_available_character_types;
        
        //choose a random character from the chosen character type
        char random_character = available_characters[random_character_type][rand() % strlen(available_characters[random_character_type])];
        
        //if chosen character is an uppercase letter and there are still available uppercase letters to use
        if (isupper(random_character) && password_uppercase_count < uppercase_count)
        {
            //add it to password and increment counter
            password[i] = random_character;
            password_uppercase_count++;
        }
        //if chosen character is a lowercase letter and there are still available lowercase letters to use
        else if (islower(random_character) && password_lowercase_count < lowercase_count)
        {
            //add it to password and increment counter
            password[i] = random_character;
            password_lowercase_count++;
        }
        //if chosen character is a number and there are still available numbers to use
        else if (isdigit(random_character) && password_number_count < number_count)
        {
            //add it to password and increment counter
            password[i] = random_character;
            password_number_count++;
        }
        //if chosen character is a special character and there are still available special characters to use
        else if (!isalnum(random_character) && password_special_count < special_count)
        {
            //add it to password and increment counter
            password[i] = random_character;
            password_special_count++;
        }
        //otherwise, choose another character
        else
        {
            i--; //decrement i to try again with same index
        }
    }
    
    //if not enough uppercase letters were added, add random ones until requirement is met
    while (password_uppercase_count < uppercase_count)
    {
        int random_index = rand() % strlen(uppercase_letters);
        password[rand() % password_length] = uppercase_letters[random_index];
        password_uppercase_count++;
    }
    
    //if not enough lowercase letters were added, add random ones until requirement is met
    while (password_lowercase_count < lowercase_count)
    {
        int random_index = rand() % strlen(lowercase_letters);
        password[rand() % password_length] = lowercase_letters[random_index];
        password_lowercase_count++;
    }
    
    //if not enough numbers were added, add random ones until requirement is met
    while (password_number_count < number_count)
    {
        int random_index = rand() % strlen(numbers);
        password[rand() % password_length] = numbers[random_index];
        password_number_count++;
    }
    
    //if not enough special characters were added, add random ones until requirement is met
    while (password_special_count < special_count)
    {
        int random_index = rand() % strlen(special_characters);
        password[rand() % password_length] = special_characters[random_index];
        password_special_count++;
    }
    
    //shuffle password characters randomly
    for (int i = password_length-1; i >= 1; i--)
    {
        int j = rand() % (i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    return password;
}