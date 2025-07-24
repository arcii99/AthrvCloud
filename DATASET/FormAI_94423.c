//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[100];
	int length,i,j;
	printf("Enter the text to convert to ASCII Art:\n");
	fgets(str,100,stdin);
	length=strlen(str)-1;

	for(i=0;i<6;i++)
	{
		for(j=0;j<length*6;j++)
		{
			//Smileys!
			switch(rand()%5)
			{
				case 0: 
					putchar('O');
					break;
				case 1:
					putchar('-');
					break;
				case 2:
					putchar('_');
					break;
				case 3:
					putchar('(');
					break;
				case 4:
					putchar(')');
					break;
			}
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    _%c_",str[i]);
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("  /     \\");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf(" |   %c%c%c   |",rand()%10+33,rand()%10+33,rand()%10+33);
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf(" \\_     _/");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("   |   |");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("   |   |");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("   |   |");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("   |   |");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("   |   |");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("  /     \\");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf(" |   %c%c%c   |",rand()%10+33,rand()%10+33,rand()%10+33);
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf(" \\_     _/");
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	for(i=0;i<length;i++)
	{
		printf("    |%c|",rand()%10+97); //Random letter
	}
	printf("\n");
	
	printf("\n\nThere you go!! ASCII Art of your text that is sure to make you smile :D");
	return 0;
}