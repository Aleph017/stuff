void initializeField(char field[10][10], int playerX, int playerY) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerX && j == playerY) {
                field[i][j] = '@';
            } else {
                field[i][j] = '.';
            }
        }
    }
}

void displayField(char field[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void movePlayer(char& input, int& playerX, int& playerY) {
    if (input == 'w') playerX--;
    if (input == 's') playerX++;
    if (input == 'a') playerY--;
    if (input == 'd') playerY++;
}
