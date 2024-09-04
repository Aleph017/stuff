#include <locale>
#include <random>
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    string hera_status[] = {"шокирована", "наглая", "спит", "ест"};

    srand(time(NULL));
    int i = 0 + rand() % 4;
    cout << "На данный момент Гера " << hera_status[i] << endl;
}