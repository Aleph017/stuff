#include <iostream>
#include <random>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

int main(){

	random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0,1);

	char field[25][25];
	while (true){
		cout << "\033[2J"; // ANSI-последовательность для очистки экрана
		cout << "\033[H"; // ANSI-последовательность для перемещения курсора в начало

		this_thread::sleep_for(milliseconds(100));

	for (int x = 0; x < 25; x++){
		for (int y = 0; y < 25; y++){
			if (dis(gen) == 1){
				field[x][y] = '#';
			}
			else{
				field[x][y] = ' ';
			}
		}
	}

	for (int x = 0; x < 25; x++){
		for (int y = 0; y < 25; y++){
			cout << field[x][y];
		}
		cout << endl;
	}}

        return 0;
}
