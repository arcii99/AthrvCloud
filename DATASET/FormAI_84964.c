//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Function to calculate checksum
int checksum(char *str) {
    int sum = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        sum += (int) str[i];
    }
    
    return sum % 256;  // return modulo 256 of sum
}

int main() {
    char input[100];
    printf("Enter string to calculate checksum:\n");
    scanf("%s", input);
    
    int result = checksum(input);
    
    printf("\nChecksum of \"%s\" is: %d\n", input, result);
    
    // Print in cyberpunk style
    printf("\n       ___          ___                   ___          ___          ___          ___          ___          ___     \n");
    printf("      /  /\\        /__/\\          ___    /  /\\        /  /\\        /  /\\        /  /\\        /  /\\        /  /\\    \n");
    printf("     /  /::\\       \\  \\:\\        /__/\\  /  /:/_      /  /::\\      /  /::\\      /  /::|      /  /::\\      /  /:/_   \n");
    printf("    /  /:/\\:\\       \\  \\:\\       \\  \\:\\/  /:/ /\\    /  /:/\\:\\    /  /:/\\:\\    /  /:|:|     /  /:/\\:\\    /  /:/ /\\  \n");
    printf("   /  /:/~/::\\  ___  \\__\\:\\       \\  \\::/ /:/_/:/   /  /:/~/::\\  /  /:/~/:/   /  /:/|:|__  /  /:/~/::\\  /  /:/_/::\\ \n");
    printf("  /__/:/ /:/\\:\\/__/\\ |  |:|        \\__\\/ /:/\\/:/___/__/:/ /:/\\:\\/__/:/ /:/___/__/:/ |:| /\\/__/:/ /:/\\:\\/__/:/__\\/\\:\\\n");
    printf("  \\  \\:\\/:/~/:/\\  \\:\\|  |:|           /__/:/ /:/\\:/\\  \\:\\/:/__\\/\\  \\:\\/::::::::\\/__\\_|:|/:/\\ \\:\\/:/__\\/\\  \\:\\~~\\~\\:\\\n");
    printf("   \\  \\::/ /:/  \\  \\:\\__|:|           \\  \\:\\/:/__\\:\\  \\::/       \\  \\::/~~~~/\\  \\:\\/:/:::::/  \\::/       \\  \\:\\  ~\\:\\\n");
    printf("    \\__\\/ /:/    \\__\\::::/             \\  \\::/\\/:/   \\/         \\  \\:\\~~~~\\/\\  \\::/~~~~~   \\/         \\  \\:\\__\\:\\\n");
    printf("      /__/:/          ~~~~               \\__\\/ /:/                \\  \\:\\     \\  \\:\\         \\            \\__\\/\\__\\/\n");
    printf("      \\__\\/                                 \\/                  \\__\\/      \\__\\/          \\                  \n");
    
    return 0;
}