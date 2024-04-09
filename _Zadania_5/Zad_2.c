#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca element listy
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Funkcja dodająca nowy element na początek listy
void push(Node** head_ref, int new_data) 
{
    // Utwórz nowy element
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci!\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Funkcja usuwająca pierwszy element z listy
void pop(Node** head_ref) 
{
    if (*head_ref == NULL) 
    {
        printf("Lista jest pusta. Nie ma czego usunąć.\n");
        return;
    }

    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
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

void Zad_2() 
{
    Node* head = NULL;

    push(&head, 3);
    push(&head, 5);
    push(&head, 7);

    printf("Lista przed usunięciem pierwszego elementu: ");
    printList(head);
    
    pop(&head);

    printf("Lista po usunięciu pierwszego elementu: ");
    printList(head);
}

int main()
{
    Zad_2();
    
    return 0;
}
