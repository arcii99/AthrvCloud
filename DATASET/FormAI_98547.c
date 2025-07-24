//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include<stdio.h>
#include<string.h>

int main()
{
    char text[100];
    int length, i, j;
    printf("Enter the text you want to convert to ASCII art: ");
    scanf("%s",text);

    length = strlen(text);
    for(i=0; i<length; i++)
    {
        printf("  ");
        for(j=0; j<5; j++)
        {
            switch(text[i])
            {
                case 'A':
                    if(j==2 || j==4)
                        printf("*");
                    else if(j==1 || j==3)
                        printf("* ");
                    else
                        printf("***** ");
                    break;
                case 'B':
                    if(j==0 || j==4)
                        printf("**** ");
                    else if(j==1 || j==3)
                        printf("*   * ");
                    else
                        printf("**** ");
                    break;
                case 'C':
                    if(j==0 || j==4)
                        printf("***** ");
                    else
                        printf("*     ");
                    break;
                case 'D':
                    if(j==0 || j==4)
                        printf("**** ");
                    else if(j==1 || j==3)
                        printf("*   * ");
                    else
                        printf("**** ");
                    break;
                case 'E':
                    if(j==0 || j==4)
                        printf("***** ");
                    else
                        printf("*     ");
                    break;
                case 'F':
                    if(j==0)
                        printf("***** ");
                    else if(j==1)
                        printf("*     ");
                    else
                        printf("*     ");
                    break;
                case 'G':
                    if(j==0 || j==4)
                        printf("***** ");
                    else if(j==3)
                        printf("*   * ");
                    else if(j==2)
                        printf("*     ");
                    else
                        printf("***** ");
                    break;
                case 'H':
                    if(j==2)
                        printf("*   * ");
                    else
                        printf("***** ");
                    break;
                case 'I':
                    printf("*     * ");
                    break;
                case 'J':
                    if(j==0)
                        printf("  *  ");
                    else if(j==4)
                        printf("***  ");
                    else if(j==3)
                        printf("  *  ");
                    else
                        printf("* *   ");
                    break;
                case 'K':
                    if(j==2)
                        printf("* * ");
                    else if(j==1 || j==3)
                        printf("*   ");
                    else
                        printf("**** ");
                    break;
                case 'L':
                    if(j==4)
                        printf("***** ");
                    else
                        printf("*     ");
                    break;
                case 'M':
                    if(j==0 || j==4)
                        printf("*   * ");
                    else if(j==1 || j==3)
                        printf("* * * ");
                    else
                        printf("*   * ");
                    break;
                case 'N':
                    if(j==0 || j==4)
                        printf("*   * ");
                    else if(j==1)
                        printf("**  * ");
                    else if(j==2)
                        printf("* * * ");
                    else
                        printf("*  ** ");
                    break;
                case 'O':
                    if(j==0 || j==4)
                        printf("***** ");
                    else
                        printf("*   * ");
                    break;
                case 'P':
                    if(j==0 || j==2)
                        printf("**** ");
                    else if(j==1)
                        printf("*   * ");
                    else
                        printf("*     ");
                    break;
                case 'Q':
                    if(j==0 || j==4)
                        printf("***** ");
                    else if(j==1)
                        printf("*   * ");
                    else if(j==3)
                        printf("  * * ");
                    else
                        printf("    * ");
                    break;
                case 'R':
                    if(j==0 || j==2)
                        printf("**** ");
                    else if(j==1)
                        printf("*   * ");
                    else if(j==3)
                        printf("* *   ");
                    else
                        printf("*   * ");
                    break;
                case 'S':
                    if(j==0 || j==2 || j==4)
                        printf("***** ");
                    else if(j==1)
                        printf("     * ");
                    else
                        printf("*     ");
                    break;
                case 'T':
                    if(j==0)
                        printf("***** ");
                    else
                        printf("*     ");
                    break;
                case 'U':
                    if(j==4)
                        printf("***** ");
                    else
                        printf("*   * ");
                    break;
                case 'V':
                    if(j==4)
                        printf("*   * ");
                    else if(j==3)
                        printf(" * *  ");
                    else if(j==2)
                        printf("  *   ");
                    else
                        printf("* * * ");
                    break;
                case 'W':
                    if(j==4)
                        printf("*   * ");
                    else if(j==3)
                        printf("* * * ");
                    else if(j==2)
                        printf("* * * ");
                    else if(j==1)
                        printf("* * * ");
                    else
                        printf("*   * ");
                    break;
                case 'X':
                    if(j==2)
                        printf("  *   ");
                    else if(j==1 || j==3)
                        printf("*   * ");
                    else
                        printf("* * * ");
                    break;
                case 'Y':
                    if(j==4)
                        printf("*   * ");
                    else if(j==3)
                        printf(" * *  ");
                    else
                        printf("  *   ");
                    break;
                case 'Z':
                    if(j==0 || j==4)
                        printf("***** ");
                    else if(j==3)
                        printf("   *  ");
                    else if(j==2)
                        printf("  *   ");
                    else
                        printf("***** ");
                    break;
                case ' ':
                    printf("    ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}