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
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Funkcja usuwająca element z listy na podstawie konkretnego indeksu
void remove_by_index(Node** head_ref, int index) 
{
    if (*head_ref == NULL) 
    {
        printf("Lista jest pusta. Nie ma czego usunąć.\n");
        return;
    }

    if (index == 0) 
    {
        Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    Node* prev_node = *head_ref;
    for (int i = 0; prev_node != NULL && i < index - 1; i++) 
    {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL || prev_node->next == NULL) 
    {
        printf("Podany indeks jest nieprawidłowy.\n");
        return;
    }

    Node* temp = prev_node->next;
    prev_node->next = temp->next;

    free(temp);
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

void Zad_4() 
{
    Node* head = NULL;

    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Lista przed usunięciem elementu o indeksie 1: ");
    printList(head);

    remove_by_index(&head, 1);

    printf("Lista po usunięciu elementu o indeksie 1: ");
    printList(head);
}

int main()
{
    Zad_4();
    
    return 0;
}
