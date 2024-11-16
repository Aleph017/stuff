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

// Счётчик живых соседей
int countNeighbors(char field[][], int x, int y, int rows, int cols) {
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

void drawField() {
    char field[30][30];
    char newField[30][30]; // Поле для хранения следующего состояния
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    // Инициализация поля
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            field[i][j] = (dis(gen) == 1) ? '#' : ' ';
        }
    }

    while (true) {
        cout << "\033[2J"; // Очистить экран
        cout << "\033[H";  // Переместить курсор в начало
        sleep_for(milliseconds(200));

        // Рисуем текущее состояние поля
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                cout << field[i][j];
            }
            cout << endl;
        }

        // Обновляем поле
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                int neighbors = countNeighbors(field, i, j, 30, 30);

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
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                field[i][j] = newField[i][j];
            }
        }
    }
}

int main() {
    drawField();
    return 0;
}
