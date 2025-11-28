#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria

    int i,j,size = addressBook->contactCount;
    printf("\n1.List using name\n2.List using phone\n3.List using email\nEnter your choice: ");
    
    int listOption = sortCriteria;
    Contact temp;

    switch (listOption)
    {
    case 1:
        
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j+1].name) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1]= temp;
            }
        }
    }

        break;

    case 2:
    
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(strcmp(addressBook->contacts[j].phone, addressBook->contacts[j+1].phone) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1]= temp;
            }
        }
    }
        break;

    case 3:
        
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(strcmp(addressBook->contacts[j].email, addressBook->contacts[j+1].email) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1]= temp;
            }
        }
    }
        break;
    
    default:
        printf("Error: Enter valid choice!");
        break;
    }


    printf("\nNumber of Contacts in address phonebook :%d\n\n",addressBook -> contactCount);
    for( i = 0; i< addressBook -> contactCount; i++)
    {
        printf("%s  %s  %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone ,addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    // addressBook->contactCount = 0;
    // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    Contact Dummy;

    //adding name
    printf("\nEnter the name to create contact:");
    getchar();
    scanf("%[^\n]", Dummy.name);

    //adding phone and checking duplicates
    printf("\nEnter the phone for the contact:");
    getchar();
    scanf("%s",  Dummy.phone);

    //phone number validation
    while (strlen(Dummy.phone) != 10)
    {
        printf("Invaild phone number!\n");
        printf("Enter a valid phone number:");
        scanf("%s",  Dummy.phone);
    }

    for( int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp( Dummy.phone,addressBook->contacts[i].phone) == 0)
        {
            printf("\nThe given contact already exists!!\nTry again with new contact\n");
            return;
        }
    } 

    //adding email and checking duplicates
    printf("\nEnter the email for the contact:");
    getchar();
    scanf("%s", Dummy.email);

    //email validation

    while (strchr( Dummy.email, '@') == NULL  || strstr (Dummy.email, ".com") == NULL)
    {
        printf("Invaild email\n");
        printf("Enter a valid email:");
        scanf("%s",  Dummy.email);
    }


    for( int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp( Dummy.email,addressBook->contacts[i].email) == 0)
        {
            printf("\nThe given contact already exists!!\nTry again with new contact");
            return;
        }
    }

    //creating new contact if no duplicates

    strcpy(addressBook->contacts[addressBook->contactCount].name,  Dummy.name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,  Dummy.phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,  Dummy.email);

    printf("\nContact Created!!");
    printf("\n%s  %s  %s\n", addressBook->contacts[addressBook->contactCount].name, addressBook->contacts[addressBook->contactCount].phone ,addressBook->contacts[addressBook->contactCount].email);
    
    //increase contact count
    (addressBook -> contactCount)++;
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int searchOption,i;
    printf("\n1.Search using name\n2.Search using phone\n3.Search using email\nEnter your choice: ");
    scanf("%d", &searchOption);
    getchar();      

    char searchStuff[50];

    switch (searchOption)
    {
    case 1:
        // code for search using name
        printf("\nEnter the name to be searched: ");
        scanf("%[^\n]", searchStuff);

        for(  i=0; i< addressBook -> contactCount; i++)
        {
            if( strcmp(searchStuff,(addressBook -> contacts[i].name)) == 0 )
            {
                printf("%d. %s  %s  %s\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            } 
        }
        return;
        
        printf("Contact not found on given name\n");
        break;

    case 2:
        // code for search using phone
        printf("\nEnter the phone to be searched: ");
        scanf("%[^\n]", searchStuff);


        for(  i=0; i< addressBook -> contactCount; i++)
        {
            if( strcmp(searchStuff,(addressBook -> contacts[i].phone)) == 0 )
            {
                printf("%s  %s  %s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return;
            }
        }

        printf("Contact not found on given phone\n");
        break;

    case 3:
        //code for search using email
        printf("\nEnter the email to be searched: ");
        scanf("%[^\n]", searchStuff);
    

        for(  i=0; i< addressBook -> contactCount; i++)
        {
            if( strcmp(searchStuff,(addressBook -> contacts[i].email)) == 0 )
            {
                printf("%s  %s  %s", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return;
            }
        }

        printf("Contact not found on given email\n");
        break;

    default:
        printf("\nEnter the valid option\n");
        break;
    }
    return;
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */

    printf("\nPick the option to edit contact");
    searchContact(addressBook);

    int i;
    printf("Enter the index of the contact to be edited: ");
    scanf("%d", &i);
  
    printf("1.Edit name\n2.Edit phone\n3.Edit email\n4.Edit all the details\nEnter the Choice:");
    int choice;
    scanf("%d", &choice);
    
    char newEdit[50];
    
    switch (choice)
    {
    case 1:
        /* code for edit name */
        printf("\nEnter the new name:");
        scanf("%s",newEdit);

        strcpy(addressBook ->contacts[i].name,newEdit);
        printf("Name is updated!!\n");
        break;

    case 2:
        /* code for edit phone */
        printf("\nEnter the new phone:");
        scanf("%s",newEdit);

        while (strlen(newEdit) != 10)
        {
            printf("Invaild phone number!\n");
            printf("Enter a valid phone number:");
            scanf("%s",newEdit);
        }

        strcpy(addressBook ->contacts[i].phone,newEdit);
        printf("Phone is updated!!\n");
        break;

    case 3:
        /* code for edit email */
        printf("\nEnter the new email:");
        scanf("%s",newEdit);

        while (strchr( newEdit, '@') == NULL  || strstr (newEdit, ".com") == NULL)
        {
            printf("Invaild email\n");
            printf("Enter a valid email:");
            scanf("%s",newEdit);
        }

        strcpy(addressBook ->contacts[i].email,newEdit);
        printf("Email is updated!!\n");
        break;

    case 4:
        /* code for edit all details */
        //edit for name
        printf("\nEnter the new name:");
        scanf("%s",newEdit);
        getchar();
        strcpy(addressBook ->contacts[i].name,newEdit);

        //edit for phone
        printf("\nEnter the new phone:");
        scanf("%s",newEdit);
        getchar();

        while (strlen(newEdit) != 10)
        {
            printf("Invaild phone number!\n");
            printf("Enter a valid phone number:");
            scanf("%s",newEdit);
        }

        strcpy(addressBook ->contacts[i].phone,newEdit);

        //edit for email
        printf("\nEnter the new email:");
        scanf("%s",newEdit);
        while (strchr( newEdit, '@') == NULL  || strstr (newEdit, ".com") == NULL)
        {
            printf("Invaild email\n");
            printf("Enter a valid email:");
            scanf("%s",newEdit);
        }
        strcpy(addressBook ->contacts[i].email,newEdit);

        printf("All details of the contact is updated!!\n");
        break;

    default:
        printf("Error: Invaild choice\n");
        break;
    }

}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    printf("Pick the option to delete contact\n");
    searchContact(addressBook);
    int i;

    printf("Enter the index of the contact to be deleted: ");
    scanf(" %d", &i);

    printf("\nDo you want to delete the contact\n1.Yes\n2.No\n\nEnter the Choice:");

    int choice;
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        
        for( int j =i; j< addressBook -> contactCount;j++)
        {
            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
            strcpy(addressBook->contacts[j].email, addressBook->contacts[j+1].email);
        }

        (addressBook -> contactCount)--;
        printf("Contact Deleted!!\n");
        break;

    case 2:
        return;
        break;

    default:
        printf("Error : Invalid option");
        break;
    }
   
}
