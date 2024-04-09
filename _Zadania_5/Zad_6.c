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

    if (*head_ref == NULL) 
    {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) 
    {
        last = last->next;
    }

    last->next = new_node;
}

// Funkcja dodająca nowy element na określonym indeksie
void insertAtIndex(Node** head_ref, int index, int new_data) 
{
    if (index < 0) 
    {
        printf("Podany indeks jest nieprawidłowy.\n");
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Błąd alokacji pamięci!\n");
        return;
    }
    new_node->data = new_data;

    // Jeśli indeks jest równy 0, nowy element staje się głową listy
    if (index == 0) 
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // Znajdź węzeł przed miejscem, gdzie należy wstawić nowy element
    Node* prev_node = *head_ref;
    for (int i = 0; prev_node != NULL && i < index - 1; i++) {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL) 
    {
        printf("Podany indeks jest większy niż długość listy.\n");
        return;
    }

    // Wstaw nowy element pomiędzy poprzednim a następnym węzłem
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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

void Zad_6() 
{
    Node* head = NULL;

    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Lista przed dodaniem elementu na indeksie 1: ");
    printList(head);

    insertAtIndex(&head, 1, 4);

    printf("Lista po dodaniu elementu na indeksie 1: ");
    printList(head);
}

int main()
{
    Zad_6();
    
    return 0;
}
