#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int number;
} contact;

void addContact(contact contacts[], int index);

int main() {
    int choice = 0;
    int contactCount = 0;

    contact contacts[2];

    while (1) {
        printf("\n1. Add contact\n");
        printf("2. Show contacts\n");
        printf("3. Exit\n");
        printf("Choose: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                if (contactCount < 100) {
                    addContact(contacts, contactCount);
                    contactCount++;
                } else {
                    printf("Contact list is full!\n");
                }
                break;

            case 2:
                printf("\nContacts:\n");

                for (int i = 0; i < contactCount; i++) {
                    printf("Name: %s, Number: %d\n",
                           contacts[i].name,
                           contacts[i].number);
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addContact(contact contacts[], int index) {
    printf("Enter a name: ");

    fgets(contacts[index].name,
          sizeof(contacts[index].name),
          stdin);

    contacts[index].name[
        strcspn(contacts[index].name, "\n")
    ] = '\0';

    printf("Enter a number: ");
    scanf("%d", &contacts[index].number);
    getchar();

    printf("Contact added!\n");
}