//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
int magic_func(int a, int b) // A cryptic function to be used later
{
    return (a * b) / (a + b);
}

void parse(const char* input) // A cryptic syntax parsing function
{
    int len = strlen(input); // Length of the input string
    int i = 0, j = 0; // Counter variables for loop

    // A cryptic loop to parse through the input string
    for (i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] == 'a') // If the current character is 'a'
        {
            if (input[i+1] == '+') // Check if there is an addition sign after 'a'
            {
                int a = input[i+2] - '0'; // Convert the next character to an integer
                int b = input[i+4] - '0'; // Convert the character after two indices to an integer
                
                printf("%d\n", magic_func(a, b)); // Call the magic function and print the result
                j += 4; // Increase the counter variable to skip over the next 4 characters
            }
        }
        else if (input[i] == 'b') // If the current character is 'b'
        {
            // Do some cryptic operations with 'b'
        }
        else if (input[i] == 'c') // If the current character is 'c'
        {
            // Do some other cryptic operations with 'c'
        }
        else // If none of the above conditions are met
        {
            // Do some default cryptic operation
        }
    }
}

int main() {
    const char* input_str = "a+b=3 c-d e+f=b"; // A cryptic input string
    parse(input_str); // Parse the input string

    return 0; // End the program successfully
}