#include <iostream>
#include <stdio.h>

int main(){
    std::cout << "[1] °C -> °F" << std::endl;
    std::cout << "[2] °F -> °C" << std::endl;
    char answer;
    std::cin >> answer;

    int nCelsius;
    int nFahrenheit;

    if (answer == '1'){
        std::cout << "Введите температуру по Цельсию: ";
        std::cin >> nCelsius;

        nFahrenheit = nCelsius * 9 / 5 + 32;
        std::cout << nCelsius << "°C ≈ " << nFahrenheit << "°F" << std::endl;
    }
    else if (answer == '2'){
        std::cout << "Введите температуру по Фаренгейту: ";
        std::cin >> nFahrenheit;

        nCelsius = (nFahrenheit - 32) * 5 / 9;
        std::cout << nFahrenheit << "°F ≈ " << nCelsius << "°C" << std::endl;
    }

    return 0;
}
