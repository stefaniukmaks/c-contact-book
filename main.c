#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int number;
} contact;

void addContact(contact contacts[], int index);
void saveContacts(contact contacts[], int count);
void loadContacts(contact **contacts, int *count);
void searchContact(contact contacts[], int count);
void deleteContact(contact **contacts, int *count);
void editContact(contact contacts[], int count);
int main() {
    int choice = 0;
    int contactCount = 0;

    contact *contacts = NULL;

    while (1) {
        printf("\n1. Add contact\n");
        printf("2. Show contacts\n");
        printf("3. Save contacts\n");
        printf("4. Load contacts\n");
        printf("5. Exit\n");
        printf("6. Search contact\n");
        printf("7. Delete contact\n");
        printf("8. Edit contact\n");
        printf("Choose: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                contact *temp = realloc(contacts, (contactCount + 1) * sizeof(contact));
                if(temp == NULL){
                    fprintf(stderr, "Memory allocation failed!\n");
                    free(contacts);
                    return 1;
                }
                contacts = temp;
                addContact(contacts, contactCount);
                contactCount++;
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
                loadContacts(&contacts, &contactCount);
                break;
            case 5:
                free(contacts);
                return 0;
            case 6:
                searchContact(contacts, contactCount);
                break;
            case 7:
                deleteContact(&contacts, &contactCount);
                break;
            case 8:
                editContact(contacts, contactCount);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    

    return 0;
}

void addContact(contact contacts[], int index) {
    printf("Enter a name: ");

    fgets(contacts[index].name, sizeof(contacts[index].name), stdin);

    contacts[index].name[strcspn(contacts[index].name, "\n")] = '\0';

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

void loadContacts(contact **contacts, int *count) {
    
    FILE *pntr = fopen("contacts.txt", "r");

    if (pntr == NULL) {
        perror("Error opening the file!");
        return;
    }

    char line[100];
    char num[100];

    free(*contacts);
    *contacts = NULL;
    *count = 0;

    while (*count < 100 && fgets(line, sizeof(line), pntr) != NULL) {

        contact *temp = realloc(*contacts, (*count + 1) * sizeof(contact));

        if(temp == NULL){
            fprintf(stderr, "Memory allocation failed!\n");
            fclose(pntr);
            return;
        }

        *contacts = temp;

        line[strcspn(line, "\n")] = '\0';

        strcpy((*contacts)[*count].name, line);

        if (fgets(num, sizeof(num), pntr) != NULL) {
            (*contacts)[*count].number = atoi(num);
            (*count)++;
        }
    }
    
    fclose(pntr);
    printf("Contacts loaded successfully!\n");
}

void searchContact(contact contacts[], int count){
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    int choice = 0;
    int found = 0;
    printf("1. Search by a name\n");
    printf("2. Search by a number\n");
    printf("Choose: ");
    scanf("%d", &choice);
    getchar();
    char searchName[50];
    if (choice == 1) {
        printf("\nEnter a name to search: ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = '\0';
        
        for(int i = 0; i < count;i++){
            if(strcmp(contacts[i].name, searchName) == 0){
                printf("Contact found: Name: %s, Number: %d\n", contacts[i].name, contacts[i].number);
                printf("\n");
                found = 1;
                return;
            }
            
        }
            if(!found){
                printf("Contact not found!");
                printf("\n");
            }
    } else if (choice == 2) {
        printf("Enter a number to search: ");
        int searchNumber;

        scanf("%d", &searchNumber);

        for(int j = 0; j < count; j++){

            if(contacts[j].number == searchNumber){

                printf("Contact found: Name: %s, Number: %d\n", contacts[j].name, contacts[j].number);
                found = 1;
                return;
            }

        }
            if(!found){
                
                printf("Contact not found!");
                printf("\n");
            }
    } else {
        printf("Invalid choice.\n");
        return;
    }
}

void deleteContact(contact **contacts, int *count){
    if (*count == 0) {
        printf("No contacts available.\n");
        return;
        
    }
    int choice = 0;
    printf("\n");

    for(int i = 0; i < *count; i++){
        printf("%d. %s - %d\n", i + 1, (*contacts)[i].name, (*contacts)[i].number);
    }
    printf("Enter contact number to delete: ");
    scanf("%d", &choice);

    choice--;

    if (choice < 0 || choice >= *count) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = choice; i < *count - 1; i++) {
        (*contacts)[i] = (*contacts)[i + 1];
    }
        
    (*count)--;
    if (*count == 0) {
    free(*contacts);
    *contacts = NULL;
    printf("Contact deleted successfully!\n");
    return;
}

    contact *temp = realloc(*contacts, *count * sizeof(contact));

    if (temp == NULL) {
    printf("Could not resize contact list.\n");
    return;
}

    *contacts = temp;
}

void editContact(contact contacts[], int count){
    if (count == 0) {
        printf("No contacts available.\n");
        return;
        
    }
    

    int choice = 0;
    
    for(int s = 0; s < count; s++){
        printf("%d. %s - %d\n", s + 1, (contacts)[s].name, (contacts)[s].number);
    }

    printf("Enter contact number: ");
    scanf("%d", &choice); 

    getchar();
    choice--;

    if (choice < 0 || choice >= count) {
        printf("Invalid contact number.\n");
        return;
    }


    
    char changedName[50];
    int changedNum = 0;

    printf("Enter a new name: ");
    fgets(changedName, 50, stdin);
    changedName[strcspn(changedName, "\n")] = '\0';

    printf("Enter new number: ");
    scanf("%d", &changedNum);

    strcpy(contacts[choice].name, changedName);

    contacts[choice].number = changedNum;

    printf("Successfull!");
}