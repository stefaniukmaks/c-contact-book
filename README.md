# Contact Manager

A command-line contact manager written in C.

The program allows users to add, view, save, and load contacts. Contacts are stored in a text file so they can be loaded again after the program is closed.

## Features

- Add contacts
- Display contacts
- Save contacts to a file
- Load contacts from a file
- Store names and phone numbers
- Menu-based interface
- Maximum of 100 contacts

## Example

```text
1. Add contact
2. Show contacts
3. Save contacts
4. Load contacts
5. Exit

Choose: 1

Enter a name: John
Enter a number: 123456789
Contact added!

After saving, the contacts are stored in contacts.txt.

Example:

John
123456789
Maxim
987654321

They can then be loaded when the program is running again.

Concepts Practiced

This project helped me practice:

struct
Arrays of structures
Functions
Pointers
Strings
fgets()
strcpy()
strcspn()
atoi()
File I/O
FILE *
fopen()
fprintf()
fgets()
fclose()
Error handling with perror()
Passing variables by pointer
Persistent data storage
How to Compile

Using GCC:

gcc main.c -o contact-manager
Run
./contact-manager
File Storage

Contacts are stored in:

contacts.txt

The file is created automatically when contacts are saved.

Future Improvements
 Delete contacts
 Search contacts
 Edit contacts
 Validate phone numbers
 Support more contact information
 Prevent duplicate contacts
 Improve file format
 Add better input validation
License

This project was created for learning C programming.