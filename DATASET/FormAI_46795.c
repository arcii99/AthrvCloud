//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>

int main() {

    char *text = "ASCII ART";
    char *alphabet[26][5] = {{" #####    \n", "#     #   \n", "#     #   \n", "#     #   \n", " #####    \n"},
	                          {"  ####    \n", " #    #   \n", "#      #  \n", "#######  \n", "#      #  \n"}, 
	                          {" #####    \n", "#     #   \n", "#     #   \n", " #####    \n", "#         \n"},
	                          {"######    \n", "#         \n", "#####     \n", "#         \n", "######    \n"}, 
	                          {"#######   \n", "#         \n", "#####     \n", "#         \n", "#         \n"}, 
	                          {" #####    \n", "#         \n", "#   ###   \n", "#     #   \n", " #####    \n"}, 
	                          {"#     #   \n", "#    ##   \n", "##### #   \n", "#     #   \n", "#     #   \n"},
	                          {"#         \n", "#         \n", "########  \n", "#         \n", "#         \n"}, 
	                          {"  ###     \n", "   #      \n", "   #      \n", "   #      \n", "  #       \n"}, 
	                          {"    #     \n", "    #     \n", "    #     \n", "#   #     \n", " ###      \n"}, 
	                          {"#     #   \n", "#   # #   \n", "# #   #   \n", "#  #  #   \n", "#    #    \n"}, 
	                          {"#         \n", "########  \n", "#         \n", "#         \n", "#         \n"},
	                          {"      #   \n", "      #   \n", "      #   \n", "      #   \n", "#######   \n"}, 
	                          {"#    #    \n", "#   #     \n", "####      \n", "#   #     \n", "#    #    \n"}, 
	                          {"#         \n", "#         \n", "#         \n", "#         \n", "#######   \n"}, 
	                          {"#     #   \n", "##   ##   \n", "# # # #   \n", "#  #  #   \n", "#     #   \n"}, 
	                          {"#     #   \n", "##   #    \n", "# #  #    \n", "#  # #    \n", "#   ##    \n"}, 
	                          {" #####    \n", "#     #   \n", "#     #   \n", "#     #   \n", " #####    \n"}, 
	                          {" ######   \n", "#     #   \n", "######   \n", "#         \n", "#         \n"}, 
	                          {" #####    \n", "#     #   \n", " #####    \n", "     #    \n", " #####    \n"}, 
	                          {" ######   \n", "#     #   \n", "######   \n", "#     #   \n", "#     #   \n"}, 
	                          {"########  \n", "     #    \n", "    #     \n", "   #      \n", "  #       \n"}, 
	                          {"#     #   \n", "#     #   \n", " #####    \n", "#     #   \n", "#     #   \n"}, 
	                          {"#     #   \n", "#     #   \n", " #   #    \n", "  # #     \n", "   #      \n"}, 
	                          {"#     #   \n", " #   #    \n", "  # #     \n", "   #      \n", "   #      \n"}, 
	                          {"#######   \n", "    #     \n", "   #      \n", "  #       \n", "#######   \n"}, 
	                          {"   ###    \n", "  #   #   \n", " #     #  \n", "  #   #   \n", "   ###    \n"}};

    int row = 5, col = 0;
    int i = 0;

    // loop through each row of text
    for(row = 0; row < 5; row++) {
        // loop through each letter of text
        for(i = 0; text[i] != '\0'; i++) {
            char c = text[i];
            // check if letter is uppercase
            if(c >= 'A' && c <= 'Z') {
                // print each row of uppercase letter
                printf("%s", alphabet[c - 'A'][row]);
            }
            // check if letter is lowercase
            else if(c >= 'a' && c <= 'z') {
                // print each row of uppercase letter
                printf("%s", alphabet[c - 'a'][row]);
            }
            // if character is not a letter, print a space
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}