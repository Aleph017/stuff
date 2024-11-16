#include <iostream>
#include <string>
using namespace std;

u32string VOWELS {U"aeiouäëyöü"};
u32string CONSONANTS={U"mpbfvntdsžrlšźkgxjẑ"};

int main(){
        for (int i = 0; i <= CONSONANTS.length(); i++){
            for (int j = 0; j <= VOWELS.length(); j++){
                cout << CONSONANTS[i] << VOWELS[j] << endl;
            }
        }
    return 0;
}