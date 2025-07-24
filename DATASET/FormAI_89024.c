//FormAI DATASET v1.0 Category: Ebook reader ; Style: active
#include<stdio.h>

//Defining a structure for the ebook information
struct ebook{
  	char title[100];
  	char author[100];
  	int year_published;
  	float price;
  	char format[20];
};

int main(){

  	//Initializing an array of ebook structures
	struct ebook e[3];

	//Populating the array with ebook information
	strcpy(e[0].title, "Introduction to C Programming");
	strcpy(e[0].author, "John Doe");
	e[0].year_published = 2020;
	e[0].price = 9.99;
	strcpy(e[0].format, "pdf");

	strcpy(e[1].title, "Data Structures and Algorithms in C");
	strcpy(e[1].author, "Jane Smith");
	e[1].year_published = 2018;
	e[1].price = 14.99;
	strcpy(e[1].format, "epub");

	strcpy(e[2].title, "Beginning C++");
	strcpy(e[2].author, "Mike Johnson");
	e[2].year_published = 2019;
	e[2].price = 12.99;
	strcpy(e[2].format, "mobi");

	//Initializing variables to store user input
	int choice;
	char format[20];

	//Prompting user to choose a book format to display
	printf("Enter the format of the ebook to display (pdf, epub, mobi): ");
	scanf("%s", format);

	//Displaying all ebooks of the chosen format
	for(int i = 0; i < 3; i++){
		if(strcmp(e[i].format, format) == 0){
			printf("%s by %s, published in %d, costs $%.2f in %s\n", e[i].title, e[i].author, e[i].year_published, e[i].price, e[i].format);
		}
	}

	return 0;
}