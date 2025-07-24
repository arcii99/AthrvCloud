//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 256

int current_pos = 0;                // keeps track of the current position in the json string
char json_string[MAX_SIZE];         // stores the input json string 

// function declarations 

void parse_object();
void parse_array();
void parse_string();
void parse_number();
void parse_bool();
void parse_null();
void parse_value();

// main function - entry point

int main()
{
    printf("Enter the JSON string: \n");
    fgets(json_string, MAX_SIZE, stdin);
    parse_value();              // calls the main parsing function to parse the json value
    printf("Parsing completed successfully!\n");
    return 0;
}

// helper function to check the validity of the token 

int check_token(char token)
{
    if(json_string[current_pos] == token)
    {
        return 1;
    }
    else
    {
        printf("Error: Invalid token %c at pos %d\n", token, current_pos);
        return 0;
    }
}

// the main parsing function for parsing json value 

void parse_value()
{
    if(json_string[current_pos] == '{')
    {
        parse_object();             // case for object
    }
    else if(json_string[current_pos] == '[')
    {
        parse_array();              // case for array
    }
    else if(json_string[current_pos] == '\"')
    {
        parse_string();             // case for string
    }
    else if(isdigit(json_string[current_pos]))
    {
        parse_number();             // case for number
    }
    else if(json_string[current_pos] == 't' || json_string[current_pos] == 'f')
    {
        parse_bool();               // case for boolean
    }
    else if(json_string[current_pos] == 'n')
    {
        parse_null();               // case for null
    }
}

// function for parsing json object 

void parse_object()
{
    if(check_token('{'))
    {
        current_pos++;              // move to next token
        while(json_string[current_pos] != '}')
        {
            parse_string();         // parsing object key
            if(!check_token(':'))
            {
                return;             // return if invalid token
            }
            current_pos++;
            parse_value();          // parsing object value
            if(json_string[current_pos] == ',')
            {
                current_pos++;      // move to next token if comma exists
                continue;
            }
        }
        current_pos++;              // move to next token after parsing object
    }
}

// function for parsing json array 

void parse_array()
{
    if(check_token('['))
    {
        current_pos++;              // move to next token
        while(json_string[current_pos] != ']')
        {
            parse_value();          // parsing each array element
            if(json_string[current_pos] == ',')
            {
                current_pos++;      // move to next token if comma exists
                continue;
            }
        }
        current_pos++;              // move to next token after parsing array
    }
}

// function for parsing json string 

void parse_string()
{
    if(check_token('\"'))
    {
        current_pos++;              // move to next token
        while(json_string[current_pos] != '\"')
        {
            current_pos++;          
        }
        current_pos++;              // move to next token after parsing string
    }
}

// function for parsing json number 

void parse_number()
{
    while(isdigit(json_string[current_pos]))
    {
        current_pos++;              // keep moving till we reach non-digit token
    }
    if(json_string[current_pos] == '.')
    {
        current_pos++;              // move to next token if decimal point exists
        while(isdigit(json_string[current_pos]))
        {
            current_pos++;          
        }
    }
}

// function for parsing json boolean 

void parse_bool()
{
    if(json_string[current_pos] == 't')
    {
        if(check_token('t') && check_token('r') && check_token('u') && check_token('e'))
        {
            current_pos++;          // move to next token after parsing boolean
        }
    }
    else if(json_string[current_pos] == 'f')
    {
        if(check_token('f') && check_token('a') && check_token('l') && check_token('s') && check_token('e'))
        {
            current_pos++;          // move to next token after parsing boolean
        }
    }
}

// function for parsing json null 

void parse_null()
{
    if(check_token('n') && check_token('u') && check_token('l') && check_token('l'))
    {
        current_pos++;              // move to next token after parsing null
    }
}