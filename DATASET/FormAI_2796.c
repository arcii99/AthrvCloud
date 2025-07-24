//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*calculate the checksum of an input string*/
unsigned int calculate_checksum(char *input_string, unsigned int string_length) {
    unsigned int checksum = 0;
    for(int i = 0; i < string_length; i++) {
        checksum += (unsigned int)input_string[i];
    }
    return checksum;
}

int main() {
    char input_string[256];
    unsigned int string_length;
    printf("Enter a string to calculate the checksum: ");
    scanf("%s", input_string);
    string_length = strlen(input_string);
    unsigned int checksum = calculate_checksum(input_string, string_length);
    printf("The checksum of the input string '%s' is %u\n", input_string, checksum);
    
    return 0;
}