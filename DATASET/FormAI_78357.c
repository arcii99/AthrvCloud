//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
/* 
	"The Case of the Missing Data Structure"
	by Detective Sherlock Holmes

	A visualization of how data structures can solve a mystery.

	In this program, we will use a linked list data structure to store clues and suspects.
	Our task is to find the culprit in a burglary case.

	Holmes: "Watson, we have a problem. A burglary took place last night at Mr. Smith's house.
			We must find the culprit. We have gathered some clues and suspects. Let's get to work."

	Watson: "I'm all ears, Holmes. What do we have?"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a clue
typedef struct Clue {
	char *description;
	struct Clue *next;
} Clue;

// Define a struct for a suspect
typedef struct Suspect {
	char *name;
	struct Suspect *next;
} Suspect;

// Function to add a new clue to the linked list
void add_clue(Clue **head, char *description) {
	if (*head == NULL) {
		*head = malloc(sizeof(Clue));
		(*head)->description = description;
		(*head)->next = NULL;
	} else {
		Clue *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = malloc(sizeof(Clue));
		temp->next->description = description;
		temp->next->next = NULL;
	}
}

// Function to add a new suspect to the linked list
void add_suspect(Suspect **head, char *name) {
	if (*head == NULL) {
		*head = malloc(sizeof(Suspect));
		(*head)->name = name;
		(*head)->next = NULL;
	} else {
		Suspect *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = malloc(sizeof(Suspect));
		temp->next->name = name;
		temp->next->next = NULL;
	}
}

int main(void) {
	// Create empty linked lists for clues and suspects
	Clue *clue_head = NULL;
	Suspect *suspect_head = NULL;

	// Add clues and suspects
	add_clue(&clue_head, "Broken window");
	add_clue(&clue_head, "Footprints");
	add_clue(&clue_head, "Stolen jewels");
	add_suspect(&suspect_head, "John");
	add_suspect(&suspect_head, "Mary");
	add_suspect(&suspect_head, "Bob");
	add_suspect(&suspect_head, "Tom");

	// Display clues and suspects to the user
	printf("Here are the clues we have gathered:\n");
	Clue *clue_temp = clue_head;
	while (clue_temp != NULL) {
		printf("- %s\n", clue_temp->description);
		clue_temp = clue_temp->next;
	}

	printf("\nHere are the suspects we need to investigate:\n");
	Suspect *suspect_temp = suspect_head;
	while (suspect_temp != NULL) {
		printf("- %s\n", suspect_temp->name);
		suspect_temp = suspect_temp->next;
	}

	// Ask the user for their analysis of the clues
	printf("\nBased on these clues, who do you think the culprit is?\n");
	char *culprit_name = malloc(256);
	fgets(culprit_name, 256, stdin);
	culprit_name[strlen(culprit_name) - 1] = '\0'; // Remove the newline character

	// Check if the user's guess matches any of the suspects
	Suspect *culprit_temp = suspect_head;
	while (culprit_temp != NULL) {
		if (strcmp(culprit_temp->name, culprit_name) == 0) {
			printf("Congratulations, you have solved the case! %s is the culprit.\n", culprit_temp->name);
			break;
		}
		culprit_temp = culprit_temp->next;
	}

	// Free memory
	clue_temp = clue_head;
	while (clue_temp != NULL) {
		Clue *temp = clue_temp;
		clue_temp = clue_temp->next;
		free(temp->description);
		free(temp);
	}

	suspect_temp = suspect_head;
	while (suspect_temp != NULL) {
		Suspect *temp = suspect_temp;
		suspect_temp = suspect_temp->next;
		free(temp->name);
		free(temp);
	}

	free(culprit_name);

	return 0;
}