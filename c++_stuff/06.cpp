#include <iostream>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    float vars[3];
    const char* var_names[3] = {"I", "U", "R"};

    cout << "I - сила тока; U - напряжение; R - сопротивление" << endl;
    cout << "Введите известные значения. Если значение неизвестно, введите 0." << endl;

    for (int i = 0; i < 3; i++){
        cout << var_names[i] << " = ";
        cin >> vars[i];
    }

    if ((vars[1] == 0 || vars[2] == 0) && vars[0] == 0) {
        cout << "GO FUCK YOURSELF!!!" << endl;
    }

    else if (vars[0] == 0){
        cout << "I = U/R = " << vars[1] / vars[2] << " А" << endl;
    }

    else if (vars[1] == 0){
        cout << "U = I*R = " << vars[0] * vars[2] << " В" << endl;
    }

    else if (vars[2] == 0){
        cout << "R = U/I = " << vars[1] / vars[0] << " Ом" << endl;
    }

    else {
        cout << "GO FUCK YOURSELF!!!" << endl;
    }

    return 0;
}