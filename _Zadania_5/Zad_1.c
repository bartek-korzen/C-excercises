#include <stdio.h>
#include <stdlib.h>

// Struktura reprezentująca elementy listy
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Funkcja dodająca nowy element na początek listy
void addFirst(Node** head_ref, int new_data) 
{
    // Utwórz nowy element
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Błąd alokacji pamięci!\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node) 
{
    while (node != NULL) 
    {
        printf("%d, ", node->data);
        node = node->next;
    }
}

void Zad_1() 
{
    Node* head = NULL;

    addFirst(&head, 3);
    addFirst(&head, 5);
    addFirst(&head, 7);

    printf("Lista po dodaniu elementów na początek: ");
    printList(head);
}

int main()
{
    Zad_1();
    
    return 0;
}
