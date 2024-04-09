#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Funkcja dodająca nowy element na koniec listy
void append(Node** head_ref, int new_data) 
{
    // Utwórz nowy element
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Błąd alokacji pamięci!\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = NULL;

    // Jeśli lista jest pusta, nowy element staje się głową listy
    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    // W przeciwnym razie znajdź ostatni element listy
    Node* last = *head_ref;
    while (last->next != NULL) 
    {
        last = last->next;
    }

    last->next = new_node;
}

// Funkcja usuwająca ostatni element z listy
void removeLast(Node** head_ref) 
{
    if (*head_ref == NULL) 
    {
        printf("Lista jest pusta. Nie ma czego usunąć.\n");
        return;
    }

    // Jeśli lista zawiera tylko jeden element, usuń go
    if ((*head_ref)->next == NULL) 
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    // Znajdź przedostatni element listy
    Node* second_last = *head_ref;
    while (second_last->next->next != NULL) 
    {
        second_last = second_last->next;
    }

    free(second_last->next);

    // Ustaw wskaźnik przedostatniego elementu na NULL, aby zakończyć listę
    second_last->next = NULL;
}

void printList(Node* node) 
{
    while (node != NULL) 
    {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("\n");
}

void Zad_3() 
{
    Node* head = NULL;

    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Lista przed usunięciem ostatniego elementu: ");
    printList(head);

    removeLast(&head);

    printf("Lista po usunięciu ostatniego elementu: ");
    printList(head);
}

int main()
{
    Zad_3();
    
    return 0;
}
