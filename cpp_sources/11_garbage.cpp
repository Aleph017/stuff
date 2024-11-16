#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Для system("clear")

using namespace std;

struct Player {
    int X;
    int Y;
    int health;
};

struct Enemy {
    int X;
    int Y;
    int health;
};

char field[10][10]; // Игровое поле
vector<Enemy> enemies; // Вектор для хранения врагов

void initialize(Player& player) {
    // Установка начальной позиции игрока и его здоровья
    player.X = 0;
    player.Y = 0;
    player.health = 10;

    // Заполнение поля
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[i][j] = '.';
        }
    }

    // Добавляем врагов
    enemies.push_back({5, 5, 5}); // Враг 1
    enemies.push_back({8, 2, 5}); // Враг 2

    // Устанавливаем игрока на поле
    field[player.X][player.Y] = '@';

    // Устанавливаем врагов на поле
    for (auto& enemy : enemies) {
        field[enemy.X][enemy.Y] = 'E'; // 'E' обозначает врага
    }
}

void displayField(const Player& player) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Player Health: " << player.health << endl; // Выводим здоровье игрока
}

void movePlayer(string input, Player& player) {
    // Стираем старое положение игрока
    field[player.X][player.Y] = '.';

    // Обрабатываем только первые 2-3 символа, кроме "f"
    for (int i = 0; i < min(3, (int)input.length()); i++) {
        if (input[i] == 'w' && player.X > 0) player.X--; // Вверх
        if (input[i] == 's' && player.X < 9) player.X++; // Вниз
        if (input[i] == 'a' && player.Y > 0) player.Y--; // Влево
        if (input[i] == 'd' && player.Y < 9) player.Y++; // Вправо
    }

    // Устанавливаем новое положение игрока
    field[player.X][player.Y] = '@';
}

void attack(Player& player) {
    cout << "Attacking enemies within range!" << endl;

    // Проходим по всем врагам
    for (auto& enemy : enemies) {
        // Проверяем, находится ли враг в радиусе 1 клетки от игрока (3x3 квадрат)
        if (enemy.X >= player.X - 1 && enemy.X <= player.X + 1 &&
            enemy.Y >= player.Y - 1 && enemy.Y <= player.Y + 1) {
            // Наносим урон 3 единицы
            enemy.health -= 3;
        cout << "Enemy at (" << enemy.X << ", " << enemy.Y << ") took 3 damage!" << endl;

        // Если здоровье врага падает до 0 или ниже, удаляем его
        if (enemy.health <= 0) {
            cout << "Enemy at (" << enemy.X << ", " << enemy.Y << ") has died!" << endl;
            field[enemy.X][enemy.Y] = '.'; // Стираем врага с поля
            enemy.X = -1; // Устанавливаем недопустимые координаты для удаления врага
            enemy.Y = -1;
        }
            }
    }

    // Удаляем врагов с недопустимыми координатами
    enemies.erase(remove_if(enemies.begin(), enemies.end(),
                            [](Enemy& enemy) { return enemy.X == -1 && enemy.Y == -1; }),
                  enemies.end());
}

void moveEnemies(Player& player) {
    for (auto& enemy : enemies) {
        // Стираем старое положение врага
        field[enemy.X][enemy.Y] = '.';

        // Простое приближение к игроку: враг двигается на одну клетку ближе к игроку
        int oldX = enemy.X;
        int oldY = enemy.Y;

        if (enemy.X < player.X) enemy.X++;
        else if (enemy.X > player.X) enemy.X--;

        if (enemy.Y < player.Y) enemy.Y++;
        else if (enemy.Y > player.Y) enemy.Y--;

        // Проверка на вход в клетку другого врага
        bool collision = false;
        for (auto& other_enemy : enemies) {
            if (&enemy != &other_enemy && enemy.X == other_enemy.X && enemy.Y == other_enemy.Y) {
                collision = true;
                break;
            }
        }

        if (collision) {
            enemy.X = oldX;
            enemy.Y = oldY;
        }

        // Если враг попал на клетку игрока, уменьшаем здоровье игрока
        if (enemy.X == player.X && enemy.Y == player.Y) {
            player.health -= 1;
            if (player.health <= 0) {
                player.health = 0;
                system("clear"); // Очищаем экран
                displayField(player); // Отображаем игровое поле
                cout << "Game Over! You have died." << endl;
                exit(0); // Завершаем программу
            }
        }

        // Устанавливаем новое положение врага
        field[enemy.X][enemy.Y] = 'E';
    }
}

int main() {
    Player player;
    initialize(player);

    while (true) {
        system("clear"); // Очищаем экран
        displayField(player);  // Отображаем игровое поле
        string input;
        cin >> input;    // Вводим направление перемещения
        if (input == "f") {
            attack(player);  // Если введено "f", выполняем атаку
        } else {
            movePlayer(input, player); // Обрабатываем перемещение игрока
            moveEnemies(player);       // Перемещаем врагов и проверяем столкновения
        }
    }

    return 0;
}
