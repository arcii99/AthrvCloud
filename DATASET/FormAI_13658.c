//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function declarations
void generate_random_string(char [], int);
int calculate_typo_count(char [], char []);
int get_typing_speed(int, int);

int main()
{
    int input_len, random_len, typo_count, typing_speed;
    char input_str[200], random_str[200];
    clock_t start, end;
    
    //generate random string
    srand(time(NULL));
    random_len = rand() % 50 + 50;     //random string length between 50 and 100
    generate_random_string(random_str, random_len);
    
    //get user input string
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following string as fast and accurately as you can:\n\n%s\n\n", random_str);
    printf("Press enter when you're finished...\n");
    fgets(input_str, 200, stdin);
    
    //calculate typo count and typing speed
    input_len = strlen(input_str);
    typo_count = calculate_typo_count(input_str, random_str);
    typing_speed = get_typing_speed(input_len, typo_count);
    
    //display results
    printf("\n\nResults:\n");
    printf("Typing speed: %d characters per minute\n", typing_speed);
    printf("Typos: %d\n", typo_count);
    
    return 0;
}

//function to generate random string
void generate_random_string(char str[], int len)
{
    int i, ascii_val;
    
    for(i=0; i<len; i++)
    {
        ascii_val = rand() % 94 + 33;   //random ascii value between 33 and 126
        str[i] = (char)ascii_val;
    }
    str[i] = '\0';
}

//function to calculate typo count
int calculate_typo_count(char input[], char random[])
{
    int i, typos=0;
    
    for(i=0; random[i]!='\0' && input[i]!='\0'; i++)
    {
        if(input[i] != random[i])
            typos++;
    }
    typos += abs((int)strlen(input) - (int)strlen(random));
    
    return typos;
}

//function to calculate typing speed
int get_typing_speed(int len, int typos)
{
    int speed;
    float time_taken;
    
    time_taken = (float)clock()/CLOCKS_PER_SEC/60;
    speed = (len - typos)/time_taken;
    
    return speed;
}