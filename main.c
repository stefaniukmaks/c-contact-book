#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int number;
} contact;

void addContact(contact contacts[], int index);
void saveContacts(contact contacts[], int count);
void loadContacts(contact contacts[], int *count);
int main() {
    int choice = 0;
    int contactCount = 0;

    contact contacts[100];

    while (1) {
        printf("\n1. Add contact\n");
        printf("2. Show contacts\n");
        printf("3. Save contacts\n");
        printf("4. Load contacts\n");
        printf("5. Exit\n");
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
                saveContacts(contacts, contactCount);
                break;
            case 4:
                loadContacts(contacts, &contactCount);
                break;
            case 5:
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

void saveContacts(contact contacts[], int count){
    printf("Saving contacts...\n");
    FILE *pntr = fopen("contacts.txt", "w");
    if(pntr == NULL){
        perror("Error opening the file!");
        return;
    }
    for(int i = 0; i < count; i++){
        fprintf(pntr, "%s\n", contacts[i].name);
        fprintf(pntr, "%d\n", contacts[i].number);
    }
    fclose(pntr);
}

void loadContacts(contact contacts[], int *count) {
    FILE *pntr = fopen("contacts.txt", "r");

    if (pntr == NULL) {
        perror("Error opening the file!");
        return;
    }

    char line[100];
    char num[100];

    while (*count < 100 && fgets(line, sizeof(line), pntr) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(contacts[*count].name, line);
        if (fgets(num, sizeof(num), pntr) != NULL) {
            contacts[*count].number = atoi(num);
            (*count)++;
        }
    }

    fclose(pntr);
    printf("Contacts loaded successfully!\n");
}