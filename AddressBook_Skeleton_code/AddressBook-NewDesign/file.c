#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr = fopen("contacts.txt", "w");

    fprintf(fptr,"#%d#\n", addressBook->contactCount);

    for( int i = 0; i< addressBook -> contactCount; i++)
    {
        fprintf(fptr,"%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone ,addressBook->contacts[i].email);
    }

    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    char str[100];
    FILE *fptr = fopen("contacts.txt", "r");

    if(fptr == NULL)
    {
        printf("File is not present\n");
    }

    else
    {
        fscanf(fptr, " %[^\n]", str);
        int size = atoi(strtok(&str[1], "#"));
        addressBook -> contactCount = size;

        for( int i =0;i<size;i++)
        {
            fscanf(fptr," %[^\n]",str);
            strcpy(addressBook->contacts[i].name, strtok(str, ","));
            strcpy(addressBook->contacts[i].phone, strtok(NULL, ","));
            strcpy(addressBook->contacts[i].email, strtok(NULL, ","));
        }
    }
}
