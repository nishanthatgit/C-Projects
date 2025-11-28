# C-Projects
# C Address Book Management System

## Overview

This is a simple console-based Address Book application developed in C. It allows a user to manage contacts by performing standard operations like creating, searching, editing, and deleting contacts. The application ensures data persistence by loading and saving contacts to a file.

## Features

The Address Book system includes the following key functionalities:

* **Data Persistence:** Contacts are automatically loaded from and saved to the `contacts.txt` file.
* **Create Contact:** Add a new contact with Name, 10-digit Phone number, and Email.
* **Input Validation:** Validates the phone number must be exactly 10 digits and the email must contain '@' and '.com'.
* **Search Contact:** Search the address book by Name, Phone, or Email.
* **Edit Contact:** Modify the Name, Phone, Email, or all details for an existing contact.
* **Delete Contact:** Remove a contact from the address book.
* **List All Contacts:** Display all stored contacts, with options to sort the list by Name, Phone, or Email.
    * Sorting is implemented using the Bubble Sort algorithm.

## Build and Run

### Prerequisites

You need a C compiler installed on your system (e.g., GCC - GNU Compiler Collection).

### Compilation

Navigate to the project directory in your terminal and compile the source files:

```bash
# Assuming you are in the 'AddressBook-NewDesign' directory
gcc main.c contact.c file.c populate.c -o addressbook