//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, s, area; 
	
	// Medieval-style input prompts
	printf("Hear ye! Hear ye! Let us calculate the area of a triangle!\n");
	printf("What is the length of the first side, in meters? ");
	scanf("%f", &a);
	printf("What is the length of the second side, in meters? ");
	scanf("%f", &b);
	printf("And what is the length of the third side, in meters? ");
	scanf("%f", &c);
	
	// Medieval-style calculations
	s = (a+b+c)/2;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	
	// Medieval-style output
	printf("By my calculations, the area of this triangle be %.2f square meters.\n", area);
	printf("I hope you are satisfied with my calculations, milord/milady!\n");
	
	return 0;
}