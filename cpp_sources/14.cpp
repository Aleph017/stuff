#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <string.h>

// m - n + 1 

using namespace std;

void atbash(string goida){
  string keyboard_en = "qwertyuiopasdfghjklzxcvbnm";
  string keyboard_ru = "йцукенгшщзхъфывапролджэячсмитьбю";

  string text;
  cout << "Введите сообщения для шифровки: ";
  cin >> text;
  cout << endl;

  transform(text.begin(), text.end(), text.begin(), ::tolower);

  string keyboard;

  if(goida == "ru"){
    keyboard = keyboard_ru;
  }
  else if(goida == "en"){
    keyboard = keyboard_en;
  }
  else{
  cout << "иди нахуй" << endl;
  }

  int length = keyboard.size();
  string result;

  for(int i = 0; i <= length; i++){
    size_t pos = text.find(keyboard[i]);
    if (pos != string::npos){
    result += keyboard[length - pos + 1];
    }
  }
  cout << result << endl;
}



int main(){
  //string keyboard_en = "qwertyuiopasdfghjklzxcvbnm";
  //string keyboard_ru = "йцукенгшщзхъфывапролджэячсмитьбю";

  string lang;

  cout << "Текст с каким алфавитом вы хотите зашифровать? (RU/EN) ";
  cin >> lang;
  cout << endl;

  transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

/*  if(lang == "ru"){
    cout << "Русский" << endl;
  }
  else if(lang == "en"){
    cout << "English" << endl;
  } */

  atbash(lang);

  return 0;
}
