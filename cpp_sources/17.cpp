#include <iostream>
#include <ncurses.h>

using namespace std;

//структура для игрока и возможно врагов
struct cunt{
    int i;
    int j;
};

//функция вывода карты в терминал
void map_output(char map[25][25], cunt& player){
    clear();
    map[player.i][player.j] = '@';

     for (int i = 0; i < 25; i++){
        for (int j = 0; j < 25; j++){
            mvaddch(i, j, map[i][j]);
        }
    }
    refresh();
}

void move_player(char map[25][25], cunt& player, int key){
    map[player.i][player.j] = '.';

    switch (key){
        case /*'w'*/KEY_UP:
            if (player.i > 0) player.i--;
            break;
        case /*'s'*/KEY_DOWN:
            if (player.i < 24) player.i++;
            break;
        case /*'a'*/ KEY_LEFT:
            if (player.j > 0) player.j--;
            break;
        case /*'d'*/KEY_RIGHT:
            if (player.j < 24) player.j++;
            break; 
    }
}

//главная функция, которая всё запускает
int main(){
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    char map[25][25];
    cunt player{10, 10};

    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 25; j++){
            map[i][j] = '.';
        }
    }

    int key;
    while ((key = getch()) !='q'){
        move_player(map, player, key);
        map_output(map, player);
    }

    endwin();
    return 0;
}