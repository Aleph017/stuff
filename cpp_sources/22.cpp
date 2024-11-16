#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

using namespace std;

int countNeighbors(const vector<vector<char>> &field, int x, int y, int rows, int cols) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Пропускаем текущую клетку
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (field[nx][ny] == '#') {
                    count++;
                }
            }
        }
    }
    return count;
}

void updateField(vector<vector<char>> &field, vector<vector<char>> &newField, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(field, i, j, rows, cols);
            if (field[i][j] == '#') {
                newField[i][j] = (neighbors == 2 || neighbors == 3) ? '#' : ' ';
            } else {
                newField[i][j] = (neighbors == 3) ? '#' : ' ';
            }
        }
    }
    field = newField;
}

int main() {
    const int cellSize = 8; // Размер одной клетки в пикселях
    const int rows = 200;     // Количество строк
    const int cols = 200;     // Количество столбцов

    // Инициализация поля
    vector<vector<char>> field(rows, vector<char>(cols, ' '));
    vector<vector<char>> newField(rows, vector<char>(cols, ' '));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    // Заполнение поля случайными данными
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            field[i][j] = (dis(gen) == 1) ? '#' : ' ';
        }
    }

    // Создание окна SFML
    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize), "Game of Life");
    window.setFramerateLimit(10); // Ограничение FPS для плавности

    while (window.isOpen()) {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обновление поля
        updateField(field, newField, rows, cols);

        // Отрисовка поля
        window.clear();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (field[i][j] == '#') {
                    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                    cell.setFillColor(sf::Color::White);
                    cell.setPosition(j * cellSize, i * cellSize);
                    window.draw(cell);
                }
            }
        }

        window.display();
    }

    return 0;
}
