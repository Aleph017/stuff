#include <cstdlib>
#include <thread>
#include <iostream>
#include <chrono>
#include <random>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std;
using namespace chrono;
using namespace this_thread;

int countNeighbors(vector<vector<char>> &field , int x, int y, int rows, int cols) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Пропустить текущую клетку
            int nx = x + dx;
            int ny = y + dy;
            // Проверка, чтобы не выйти за границы поля
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (field[nx][ny] == '#') {
                    count++;
                }
            }
        }
    }
    return count;
}

void drawField(int row, int col){
    vector<vector<char>> field(row, vector<char>(col));
    vector<vector<char>> newField(row, vector<char>(col));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,1);
    uniform_int_distribution<> dis0(1,10);

//  cout << w.ws_col << " " << w.ws_row;
//  1sleep_for(seconds(10));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (dis(gen) == 1 && dis0(gen) <= 3){
                field[i][j] = '#';
            }
            else{
                field[i][j] = ' ';
            }
        }
    }

        while (true){
            cout << "\033[2J\033[H";
            sleep_for(milliseconds(100));

        for (int i = 0; i < row; i++){
            for (int j = 0; j <col; j++){
                cout << field[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int neighbors = countNeighbors(field, i, j, row, col);
                if (field[i][j] == '#') {
                    // "Живая" клетка
                    newField[i][j] = (neighbors == 2 || neighbors == 3) ? '#' : ' ';
                } else {
                    // "Мёртвая" клетка
                    newField[i][j] = (neighbors == 3) ? '#' : ' ';
                }
            }
        }

        // Копируем новое поле в текущее
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                field[i][j] = newField[i][j];
            }
        }
        field = newField;
    }
}

int main(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    drawField(w.ws_row, w.ws_col);
    return 0;
}
