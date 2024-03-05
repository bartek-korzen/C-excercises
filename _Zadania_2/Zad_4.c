#include <stdio.h>
#include <string.h>

struct Student 
{
    char name[50];
    float grade;
};

// Funkcja zamieniająca miejscami dwa elementy tablicy struktur Student
void swap(struct Student *a, struct Student *b) 
{
    struct Student x = *a;
    *a = *b;
    *b = x;
}

// Funkcja sortująca tablicę struktur Student
void sortStudents(struct Student *tab, int n) 
{
    // Sortowanie studentów ocenami malejąco
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (tab[j].grade < tab[j + 1].grade) 
            {
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
    
    // Sortowanie studentów z tą samą oceną w kolejności alfabetycznej
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (tab[j].grade == tab[j + 1].grade) 
            {
                if (strcmp(tab[j].name, tab[j + 1].name) > 0) 
                {
                    swap(&tab[j], &tab[j + 1]);
                }
            }
        }
    }
}

void Zad_4() 
{
    
    struct Student students[] = 
    {
        {"Anna", 2.0}, {"Michał", 3.0}, {"Katarzyna", 4.0}, {"Piotr", 5.0}, {"Małgorzata", 4.5}, {"Jan", 2.0}, {"Agnieszka", 2.0}, {"Krzysztof", 3.5}, {"Joanna", 3.5},
        {"Tomasz", 4.5}, {"Barbara", 3.0}, {"Paweł", 2.0}, {"Magdalena", 3.0}, {"Andrzej", 2.0}, {"Dorota", 5.0}, {"Oskar", 2.0}, {"Ewa", 4.5}, {"Izydor", 2.0},
        {"Marta", 3.5}, {"Marek", 4.5}, {"Beata", 3.5}, {"Rafał", 3.0}, {"Aleksandra", 2.0}, {"Grzegorz", 3.0}, {"Monika", 4.0}, {"Marcin", 5.0}, {"Izabela", 2.0},
        {"Ireneusz", 3.5}, {"Justyna", 4.5}, {"Artur", 3.5}, {"Natalia", 4.5}, {"Jacek", 4.5}, {"Elżbieta", 2.0}, {"Adam", 2.0}, {"Iwona", 5.0}, {"Szymon", 5.0},
        {"Kinga", 5.0}, {"Damian", 3.0}, {"Aleksander", 2.0}, {"Teresa", 3.0}, {"Adrian", 3.5}, {"Izabela", 4.5}, {"Bożena", 3.5}, {"Ryszard", 4.0}, {"Urszula", 2.0},
        {"Mateusz", 3.0}, {"Anna", 4.0}, {"Mirosław", 5.0}, {"Katarzyna", 5.0}, {"Dariusz", 5.0}, {"Danuta", 2.0}, {"Robert", 3.5}, {"Aleksandra", 4.5}, {"Wojciech", 3.5},
        {"Halina", 5.0}, {"Leszek", 2.0}, {"Marzena", 3.0}, {"Józef", 4.0}, {"Ewa", 5.0}, {"Sylwia", 2.0}, {"Kazimierz", 3.5}, {"Irena", 2.0}, {"Rafał", 3.5},
        {"Joanna", 4.5}, {"Mariusz", 2.0}, {"Agnieszka", 4.0}, {"Tomasz", 5.0}, {"Elżbieta", 3.0}, {"Bartłomiej", 4.0}, {"Kamila", 5.0}, {"Andrzej", 4.0}, {"Bożena", 4.5},
        {"Arkadiusz", 2.0}, {"Dorota", 3.5}, {"Paweł", 4.5}, {"Monika", 2.0}, {"Jolanta", 3.0}, {"Radosław", 2.0}, {"Beata", 3.0}, {"Piotr", 4.0}, {"Agata", 5.0}, {"Stefan", 2.0},
        {"Urszula", 3.5}, {"Sebastian", 4.0}, {"Anna", 3.5}, {"Marek", 4.5}, {"Katarzyna", 3.5}, {"Krzysztof", 2.0}, {"Marta", 2.0}, {"Mateusz", 3.0}, {"Aleksandra", 4.0},
        {"Tomasz", 5.0}, {"Małgorzata", 3.0}, {"Michał", 2.0}, {"Ewa", 3.5}, {"Szymon", 3.5}, {"Dominika", 4.5}, {"Robert", 4.5}, {"Marzena", 2.0}, {"Zuzanna", 2.0},
    };
    int n = sizeof(students) / sizeof(students[0]);

    sortStudents(students, n);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %.2f\n", students[i].name, students[i].grade);
    }

}

int main()
{
    Zad_4();
    
    return 0;
}
