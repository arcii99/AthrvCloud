//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include<stdio.h>
#include<string.h>

void printArt(char* text);
// Function to print ASCII art of given text

int main()
{
    char input[20];

    // Taking input from the user
    printf("Enter the text: ");
    scanf("%s", input);

    // Passing the input to printArt function
    printArt(input);

    return 0;
}

void printArt(char* text)
{
    int i, j, n;
    char c;

    // Converting text to uppercase
    for(i=0;i<strlen(text);i++)
        text[i] = toupper(text[i]);

    // Looping through each character in the text
    for(i=0;i<strlen(text);i++)
    {
        c = text[i];
        n = (int)c;

        // Checking if character is uppercase alphabet or a space
        if(n >= 65 && n <= 90 || n == 32)
        {
            // Looping through each row of ASCII art for the character
            for(j=0;j<7;j++)
            {
                // Switch case to print corresponding ASCII art row
                switch(c)
                {
                    case 'A': printf("    # # #    \n   #       #   \n  #         #  \n #           # \n#             #\n#             #\n#             #\n\n"); break;
                    case 'B': printf("# # # # # \n#         # \n#        #\n# # # # # \n#        #\n#         # \n# # # # #\n\n"); break;
                    case 'C': printf("  # # # # # #  \n#                   \n#                   \n#                   \n#                   \n#                   \n  # # # # # #  \n\n"); break;
                    case 'D': printf("# # # # #\n#         #\n#         #\n#         #\n#         #\n#         #\n# # # # #\n\n"); break;
                    case 'E': printf("# # # # # # #\n#                        \n#                        \n#                        \n#                        \n#                        \n# # # # # # #\n\n"); break;
                    case 'F': printf("# # # # # # #\n#                        \n#                        \n# # # #                 \n#                        \n#                        \n#                        \n\n"); break;
                    case 'G': printf("    # # # # #   \n  #                        \n#                new line                   \n#              #                             \n#                #                           \n  # # # # #  # #      \n\n"); break;
                    case 'H': printf("#             #\n#             #\n#             #\n# # # # # #\n#             #\n#             #\n#             #\n\n"); break;
                    case 'I': printf("# # # # # #  \n      #                new line                        \n      #\n      #\n      #\n      #\n# # # # # #\n\n"); break;
                    case 'J': printf("    # # # # # #   \n        #                           \n        #                           \n        #                           \n#     #                           \n#     #                           \n##    #\n\n"); break;
                    case 'K': printf("#         #\n#     #    \n#   #      \n# #        \n#   #      \n#     #    \n#         #\n\n"); break;
                    case 'L': printf("#               \n#               \n#               \n#               \n#               \n#               \n# # # # # # #\n\n"); break;
                    case 'M': printf("#             #\n# #         # #\n#     # #     #\n#         #         #\n#                   #\n#                   #\n#                   #\n\n"); break;
                    case 'N': printf("#             #\n# #         #\n#    #      #\n#        # #\n#             #\n#                #\n#                   #\n\n"); break;
                    case 'O': printf("     # # # # #     \n  #            # new line                        \n#                  #                      \n#                  #\n#                  #\n  #            #\n     # # # # #     \n\n"); break;
                    case 'P': printf("# # # # # # #\n#                          \n#                          \n# # # # # # #\n#                                     \n#                                     \n#                                     \n\n"); break;
                    case 'Q': printf("# # # # # #  \n#                     \n#                     \n#                     \n#                     \n#        #    \n#        #  \n\n"); break;
                    case 'R': printf("# # # # # # #\n#                          \n#                          \n# # # # # # #\n#        #\n#          #\n#            #\n\n"); break;
                    case 'S': printf("    # # # # # #\n  #                          \n#                 \n    # # # # # #\n                #                 \n                #                 \n# # # # # # #\n\n"); break;
                    case 'T': printf("# # # # # # #\n          #                      \n          #                     \n          #                     \n          #                     \n          #                     \n          #                     \n\n"); break;
                    case 'U': printf("#                 #\n#                 #\n#                 #\n#                 #\n#                 #\n  # # # # # #\n\n"); break;
                    case 'V': printf("#                   #\n  #               #\n    #          #\n      #     #\n          #  \n            #\n\n"); break;
                    case 'W': printf("#                   #\n#                   #\n#           #       #\n#       #      #     #\n#           #       #\n#                   #\n#                   #\n\n"); break;
                    case 'X': printf("#                   #\n  #               #\n    #          #\n      #      #\n    #          #\n  #               #\n#                   #\n\n"); break;
                    case 'Y': printf("#             #\n  #         #\n    #     #\n      # #\n        #\n        #\n\n"); break;
                    case 'Z': printf("# # # # # # #\n                 #           \n                #            \n              #             \n           #                \n        #                   \n# # # # # # #\n\n"); break;
                    case ' ': printf("\n\n\n\n\n\n\n"); break;
                }
            }
        }
    }
}