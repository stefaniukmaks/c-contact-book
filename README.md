# Contact Manager

A command-line contact manager written in C.

This project allows users to create, manage, search, edit, delete, save, and load contacts. It uses dynamic memory allocation and file I/O to keep contacts available between program runs.

## Features

- Add contacts
- Display all contacts
- Search contacts by name
- Search contacts by phone number
- Edit existing contacts
- Delete contacts
- Save contacts to a file
- Load contacts from a file
- Dynamic memory allocation
- Menu-based command-line interface
- Maximum of 100 contacts
- Basic error handling

## Example

```text
1. Add contact
2. Show contacts
3. Save contacts
4. Load contacts
5. Exit
6. Search contact
7. Delete contact
8. Edit contact

Choose: 1

Enter a name: John
Enter a number: 123456789

Contact added!

Searching:

Choose: 6


1. Search by a name
2. Search by a number


Choose: 1
Enter a name to search: John


Contact found: Name: John, Number: 123456789

Editing:

Choose: 8


1. John - 123456789


Enter contact number: 1
Enter a new name: Johnny
Enter new number: 987654321


Successful!


File Storage

Contacts are stored in:

contacts.txt

The file is created automatically when contacts are saved.

Example:

John
123456789
Maxim
987654321

The contacts can be loaded again after restarting the program.

contacts.txt is ignored by Git because it contains local contact data.

Concepts Practiced

This project helped me practice:

C Fundamentals
struct
Arrays
Arrays of structures
Functions
switch
Loops
Conditional statements
Memory Management
Pointers
Pointer-to-pointer (contact **)
malloc()
realloc()
free()
Dynamic arrays
Strings
Character arrays
fgets()
strcpy()
strcmp()
strcspn()
File I/O
FILE *
fopen()
fprintf()
fgets()
fclose()
Reading and writing files
Persistent data storage
Error Handling
Checking malloc() / realloc() failures
Checking file opening errors
perror()
Handling invalid contact indexes
How to Compile

Make sure GCC is installed.

Compile the program:

gcc -Wall -Wextra -g main.c -o contact-manager

Run it:

./contact-manager
Project Structure
c-contact-book/
├── main.c
├── README.md
├── .gitignore
└── contacts.txt

contacts.txt is a local data file and should not be committed to Git.

Future Improvements

Possible improvements for the project:

 Better input validation
 Validate phone numbers
 Prevent duplicate contacts
 Case-insensitive search
 Sort contacts alphabetically
 Support more contact information
 Improve the file format
 Separate the project into multiple .c and .h files
 Add colored terminal output
 Improve error handling
 Add confirmation before deleting a contact
What I Learned

While building this project, I practiced working with structures, pointers, dynamic memory allocation, strings, and file I/O in C.

One of the biggest parts of the project was learning how to use realloc() and contact ** to dynamically resize and modify the contact list.

License

This project was created for learning and practicing C programming.