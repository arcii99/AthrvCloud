//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include<stdio.h>
#include<string.h>

//Function to sanitize the URL
void sanitizeUrl(char* url)
{
    int len = strlen(url);
    int i,j,k;

    //Remove whitespace from the URL
    for(i=0; i<len; i++)
    {
        if(url[i] == ' ')
        {
            for(j=i; j<len; j++)
            {
                url[j] = url[j+1];
            }
            len--;
        }
    }

    //Make sure the URL starts with http:// or https://
    if(strncmp(url,"http://",7) != 0 && strncmp(url,"https://",8) != 0)
    {
        char temp[10];
        strncpy(temp,url,7);
        temp[7] = '\0';
        if(strcmp(temp,"http://") != 0)
        {
            //Add http:// to the start of the URL
            for(k=len; k>=0; k--)
            {
                url[k+7] = url[k];
            }
            strncpy(url,"http://",7);
        }
    }

    //Remove any extra slashes from the URL
    for(i=7; i<len; i++)
    {
        if(url[i] == '/' && url[i+1] == '/')
        {
            for(j=i; j<len; j++)
            {
                url[j] = url[j+1];
            }
            len--;
        }
    }

    //Remove any single dots in the URL
    for(i=7; i<len; i++)
    {
        if(url[i] == '.' && url[i+1] == '/')
        {
            for(j=i; j<len; j++)
            {
                url[j] = url[j+2];
            }
            len -= 2;
        }
    }

    //Remove any double dots in the URL
    for(i=7; i<len; i++)
    {
        if(url[i] == '.' && url[i+1] == '.' && url[i+2] == '/')
        {
            for(j=i; j>7; j--)
            {
                if(url[j] == '/')
                {
                    for(k=j; k<len; k++)
                    {
                        url[k] = url[k+3];
                    }
                    len -= 3;
                    break;
                }
            }
        }
    }
}

//Main function to test the sanitizeUrl function
int main()
{
    char url[1000];

    //Get the URL from the user
    printf("Enter a URL: ");
    fgets(url,1000,stdin);

    //Sanitize the URL
    sanitizeUrl(url);

    //Print the sanitized URL
    printf("Sanitized URL: %s",url);

    return 0;
}