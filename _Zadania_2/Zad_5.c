#include <stdio.h>
#include <string.h>

struct Contact 
{
    char name[50];
    char last_name[50];
    char phone_number[9];
};

struct Contact adress_book[100];
int contact_count = 0;

// Funkcja dodająca nowy kontakt do książki adresowej
void addContact() 
{
    if (contact_count >= 100) 
    {
        printf("Ksiazka adresowa jest pelna.\n");
        return;
    }

    struct Contact new_contact;

    printf("Podaj imie: ");
    scanf("%s", new_contact.name);
    printf("Podaj nazwisko: ");
    scanf("%s", new_contact.last_name);
    
    // Wprowadzanie numeru telefonu i sprawdzenie, czy składa się z 9 cyfr
    do 
    {
        printf("Podaj numer telefonu: ");
        scanf("%s", new_contact.phone_number);
        if (strlen(new_contact.phone_number) != 9) 
        {
            printf("Numer telefonu musi skladac sie z 9 cyfr.\n");
        }
    } while (strlen(new_contact.phone_number) != 9);

    adress_book[contact_count++] = new_contact;

    printf("Kontakt dodany pomyslnie.\n");
}


// Funkcja wyszukująca kontakt po nazwisku
void findContact(char last_name[]) 
{
    int znaleziono = 0;
    for (int i = 0; i < contact_count; i++) 
    {
        if (strcmp(adress_book[i].last_name, last_name) == 0) 
        {
            printf("Znaleziono kontakt:\n");
            printf("\n");
            printf("Imie: %s\n", adress_book[i].name);
            printf("Nazwisko: %s\n", adress_book[i].last_name);
            printf("Numer telefonu: %s\n", adress_book[i].phone_number);
            znaleziono = 1;
        }
    }
    if (!znaleziono) 
    {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja usuwająca kontakt po nazwisku
void deleteContact(char last_name[]) 
{
    int found = 0;
    for (int i = 0; i < contact_count; i++) \
    {
        if (strcmp(adress_book[i].last_name, last_name) == 0) 
        {
            for (int j = i; j < contact_count - 1; j++) 
            {
                adress_book[j] = adress_book[j + 1];
            }
            contact_count--;
            printf("Kontakt usuniety pomyslnie.\n");
            found = 1;
        }
    }
    if (!found) 
    {
        printf("Nie znaleziono kontaktu o podanym nazwisku.\n");
    }
}

// Funkcja wypisująca wszystkie kontakty w książce adresowej
void listContacts() 
{
    if (contact_count == 0) 
    {
        printf("Ksiazka adresowa jest pusta.\n");
        return;
    }

    printf("Lista wszystkich kontaktow:\n");
    for (int i = 0; i < contact_count; i++) 
    {
        printf("\n");
        printf("Kontakt %d:\n", i + 1);
        printf("Imie: %s\n", adress_book[i].name);
        printf("Nazwisko: %s\n", adress_book[i].last_name);
        printf("Numer telefonu: %s\n", adress_book[i].phone_number);
    }
}

void Zad_5() 
{
    int option;
    char last_name[50];

    do 
    {
        printf("\nMENU:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt po nazwisku\n");
        printf("3. Usun kontakt po nazwisku\n");
        printf("4. Wypisz wszystkie kontakty\n");
        printf("0. Wyjdz\n");
        printf("\n");
        printf("Opcja: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) 
        {
            case 1:
                addContact();
                break;
            case 2:
                printf("Podaj nazwisko: ");
                scanf("%s", last_name);
                findContact(last_name);
                break;
            case 3:
                printf("Podaj nazwisko: ");
                scanf("%s", last_name);
                deleteContact(last_name);
                break;
            case 4:
                listContacts();
                break;
            case 0:
                printf("Koniec programu.\n");
                break;
            default:
                printf("Niepoprawna opcja.\n");
        }
    } while (option != 0);
}

int main()
{
    Zad_5();
    
    return 0;
}
