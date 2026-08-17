# Contact Manager

A simple command-line contact manager written in C.

The program allows you to add contacts, store their names and phone numbers, and display the saved contacts.

## Features

- Add a contact
- Store contact names
- Store phone numbers
- Display all contacts
- Menu-based interface
- Prevent adding contacts when the list is full
- Basic input validation

## Example

```text
1. Add contact
2. Show contacts
3. Exit
Choose: 1

Enter a name: John
Enter a number: 123456789
Contact added!

1. Add contact
2. Show contacts
3. Exit
Choose: 2

Contacts:
Name: John, Number: 123456789

Concepts Practiced

This project helped me practice:

struct
Arrays of structures
Functions
Strings
fgets()
scanf()
Loops
switch statements
Input handling
Array indexing
Basic validation
How to Compile

Using GCC:

gcc main.c -o contact-manager
Run
./contact-manager
Future Improvements
 Add more than 100 contacts
 Remove contacts
 Search for a contact
 Edit existing contacts
 Save contacts to a file
 Load contacts when the program starts
 Better phone number validation
License

This project is for learning purposes.



