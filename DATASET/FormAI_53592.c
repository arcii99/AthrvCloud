//FormAI DATASET v1.0 Category: Text processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000] = "Mr. Sherlock Holmes was a man of unique and peculiar talents. One of his most notable abilities was his incredible attention to detail. This made him a master of deduction, allowing him to solve even the most complex of crimes. However, his skills were not solely limited to crime-solving. In fact, one of his favorite pastimes was processing text.";
    char *keyword = "text";
    int count = 0;

    // Step 1: Find all occurrences of the keyword in the message
    char *ptr = strstr(message, keyword);

    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + strlen(keyword), keyword); // Move the pointer to the next occurrence of the keyword
    }

    // Step 2: Print the number of times the keyword appears in the message
    printf("Ah, Watson, I see that the keyword '%s' appears %d times in the message.\n", keyword, count);

    // Step 3: Remove all instances of the keyword from the message
    ptr = strstr(message, keyword);

    while (ptr != NULL) {
        memset(ptr, ' ', strlen(keyword)); // Replace the string with spaces
        ptr = strstr(ptr + strlen(keyword), keyword); // Move the pointer to the next occurrence of the keyword
    }

    // Step 4: Print the updated message
    printf("\nAnd now, Watson, what remains of the original message?\n");
    printf("%s\n", message);

    return 0;
}