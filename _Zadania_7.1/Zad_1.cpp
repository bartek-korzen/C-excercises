#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int calculateEnergyValue(std::string line) 
{
    int firstDigit = -1, lastDigit = -1;

    for (char c : line) 
    {
        if (isdigit(c)) 
        {
            firstDigit = c - '0';
            break;
        }
    }

    for (int i = line.length() - 1; i >= 0; i--) 
    {
        if (isdigit(line[i])) 
        {
            lastDigit = line[i] - '0';
            break;
        }
    }
    
    if (firstDigit != -1 && lastDigit != -1) 
    {
        return firstDigit * 10 + lastDigit;
    } 
    else 
    {
        return 0;
    }
}

int Zad_1() 
{
    std::ifstream file("input.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Nie można otworzyć pliku input.txt" << std::endl;
        return 1;
    }

    int totalEnergy = 0;
    std::string line;

    while (std::getline(file, line)) 
    {
        int energyValue = calculateEnergyValue(line);
        totalEnergy += energyValue;
    }

    file.close();
    std::cout << "Suma wszystkich wartości energetycznych: " << totalEnergy << std::endl;

    return 0;
}

int main()
{
    Zad_1();

    return 0;
}
