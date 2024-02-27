#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Funkcja do zwracania losowego ruchu gracza komputerowego
int losowy_ruch() {
    return rand() % 3; // Zwracanie 0 dla papieru, 1 dla kamienia, 2 dla nożyc
}

// Funkcja do przekształcania numeru ruchu na nazwę
char* nazwa_ruchu(int ruch) {
    switch (ruch) {
        case 0:
            return "papier";
        case 1:
            return "kamień";
        case 2:
            return "nożyce";
        default:
            return "nieznany";
    }
}

void Zad_6() {
    int wyniki[100]; // Tablica przechowująca wyniki rund (1 - wygrana, 0 - remis, -1 - przegrana)
    char ruchy[100][20]; // Tablica przechowująca ruchy gracza w danych rundach
    int rundy = 0; 
    srand(time(NULL));

    printf("Witaj w grze papier, kamień, nożyce!\n");

    while (1) {
        printf("Wybierz swój ruch (papier/kamień/nożyce) lub wpisz 'scores' aby zobaczyć wyniki: ");
        char wybor[20];
        scanf("%s", wybor);

        if (strcmp(wybor, "scores") == 0) {
            printf("Wyniki:\n");
            for (int i = 0; i < rundy; i++) {
                printf("Runda %d: Twój ruch: %s, Ruch komputera: %s, Wynik: ", i + 1, ruchy[i], nazwa_ruchu(losowy_ruch()));
                if (wyniki[i] == 1)
                    printf("Wygrana\n");
                else if (wyniki[i] == 0)
                    printf("Remis\n");
                else
                    printf("Przegrana\n");
            }
        } else {
            if (strcmp(wybor, "papier") == 0 || strcmp(wybor, "kamień") == 0 || strcmp(wybor, "nożyce") == 0) {
                // Gracz wybrał poprawny ruch, więc generujemy ruch komputera
                int ruch_komputera = losowy_ruch();

                // Zapisywanie ruchów gracza i komputera oraz wyników rundy
                strcpy(ruchy[rundy], wybor);
                if ((strcmp(wybor, "papier") == 0 && ruch_komputera == 1) ||
                    (strcmp(wybor, "kamień") == 0 && ruch_komputera == 2) ||
                    (strcmp(wybor, "nożyce") == 0 && ruch_komputera == 0)) {
                    wyniki[rundy] = 1; // Wygrana
                } else if (ruch_komputera == (strcmp(wybor, "papier") == 0 ? 1 : (strcmp(wybor, "kamień") == 0 ? 2 : 0))) {
                    wyniki[rundy] = 0; // Remis
                } else {
                    wyniki[rundy] = -1; // Przegrana
                }

                rundy++;
            } else {
                printf("Niepoprawny ruch. Spróbuj jeszcze raz.\n");
            }
        }
    }
}

int main()
{

Zad_6();

return 0;

}
