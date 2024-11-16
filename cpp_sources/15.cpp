#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

void atbash(string lang) {
    string keyboard_en = "qwertyuiopasdfghjklzxcvbnm";
    string keyboard_ru = "йцукенгшщзхъфывапролджэячсмитьбю";

    string text;
    cout << "Введите сообщение для шифровки: ";
    cin.ignore();  // Очищаем буфер ввода после предыдущего cin
    getline(cin, text);  // Используем getline для ввода строки с пробелами
    cout << endl;

    transform(text.begin(), text.end(), text.begin(), ::tolower);  // Преобразуем текст в нижний регистр

    string keyboard;

    if (lang == "ru") {
        keyboard = keyboard_ru;
    } else if (lang == "en") {
        keyboard = keyboard_en;
    } else {
        cout << "Неправильный язык!" << endl;
        return;
    }

    int length = keyboard.size();
    string result;

    for (char& ch : text) {
        size_t pos = keyboard.find(ch);
        if (pos != string::npos) {
            result += keyboard[length - pos - 1];  // Находим симметричный символ
        } else {
            result += ch;  // Если символ не найден (например, пробел или знак), просто добавляем его
        }
    }

    cout << "Зашифрованное сообщение: " << result << endl;
}

int main() {
    string lang;

    cout << "Текст с каким алфавитом вы хотите зашифровать? (RU/EN): ";
    cin >> lang;
    cout << endl;

    transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

    atbash(lang);

    return 0;
}

