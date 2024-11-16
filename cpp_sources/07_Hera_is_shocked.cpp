#include <iostream>

using namespace std;

struct cat
{
    bool isShocked;
};

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cat Hera;
    Hera.isShocked = true;

    while (Hera.isShocked){
        cout << "Гера шокирована!" << endl;
    }

    return 0;
}
