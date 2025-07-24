//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

int recursive_function(int n)
{
	if(n==1)
	{
		printf("I am Brave!\n");
		return 1;
	}
	
	recursive_function(n-1);
	
	if(n % 3 == 0)
	{
		printf("I am Fierce!\n");
	}
	
	if(n % 5 == 0)
	{
		printf("I am Strong!\n");
	}
	
	return 0;
}

int main()
{
	int n;
	printf("Enter a natural number:\n");
	scanf("%d", &n);
	
	recursive_function(n);
	
	return 0;
}