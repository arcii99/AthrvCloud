//FormAI DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a person
struct person {
    char name[20];
    int age;
    float height;
};

// Define a struct for a family
struct family {
    char last_name[20];
    struct person members[5];
    int num_members;
};

// Function to add a new member to a family
void add_member(struct family *fam, char name[20], int age, float height) {
    struct person new_member;
    strcpy(new_member.name, name);
    new_member.age = age;
    new_member.height = height;
    fam->members[fam->num_members] = new_member;
    fam->num_members ++;
    printf("%s added to the family %s\n", name, fam->last_name);
}

int main() {
    // Create a new family
    struct family smith_family;
    strcpy(smith_family.last_name, "Smith");
    smith_family.num_members = 0;

    // Add members to the family
    add_member(&smith_family, "John", 30, 6.2);
    add_member(&smith_family, "Julie", 26, 5.8);
    add_member(&smith_family, "Jimmy", 8, 3.9);

    // Print out the members of the family
    printf("The members of the %s family are: \n", smith_family.last_name);
    int i;
    for (i = 0; i < smith_family.num_members; i++) {
        printf("%d. %s, %d years old, %.1f feet tall\n", i+1, smith_family.members[i].name, smith_family.members[i].age, smith_family.members[i].height);
    }

    return 0;
}