#include<stdio.h>
#include<iostream>

int main(int nNumberOfArgs, char* pszArgs[])
{
    int nNCelsius;
    std::cout << "Введите температуру по Цельсию: ";
    std::cin >> nNCelsius;

    int nNFactor;
    nNFactor = 212 - 32;

    int nFahrenheit;
    nFahrenheit = nNFactor * nNCelsius/100+32;

    std::cout << "Температура по Фаренгейту: ";
    std::cout << nFahrenheit << std::endl;

    return 0;
}