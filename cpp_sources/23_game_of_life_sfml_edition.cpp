#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <vector>
#include <random>

using namespace std;
using namespace sf;

int countNeighbours(vector<vector<char>> &field, int x, int y, int rows, int cols){
    int count = 0;
    for(int ax = -1; ax <= 1; ax++){
        for (int ay = -1; ay <= 1; ay++){
            if(ax == 0 && ay == 0){
                continue; //weird guy, could make some problems
            }
            int nx = x + ax;
            int ny = y + ay;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols){
                if(field[nx][ny] == '#'){
                    count++;
                }
            }
        }
    }
    return count;
}

void updateField(vector<vector<char>> &field, vector<vector<char>> &newField, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int neighbours = countNeighbours(field, i, j, rows, cols);
            if (field[i][j] == '#') {
                newField[i][j] = (neighbours == 2 || neighbours == 3) ? '#' : ' ';
            }
            else{
                newField[i][j] = (neighbours == 3) ? '#' : ' ';
            }
        }
    }
    field = newField;
    }


int main(){
    unsigned int width = (VideoMode::getDesktopMode().width)/2;
    unsigned int height = (VideoMode::getDesktopMode().height)/2;
    const int cellSize = 4;
    const int rows = height/cellSize;
    const int cols = width/cellSize;

    vector<vector<char>> field(rows, vector<char>(cols, ' '));
    vector<vector<char>> newField(rows, vector<char>(cols, ' '));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            field[i][j] = (dis(gen) < 1) ? '#' : ' ';
        }
    }

    RenderWindow window(VideoMode(cols * cellSize, rows * cellSize), "Game of Life");
    window.setFramerateLimit(15);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }


    updateField(field, newField, rows, cols);

    window.clear();

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(field[i][j] == '#'){
                RectangleShape cell(Vector2f(cellSize - 1, cellSize -1));
                cell.setFillColor(Color::Cyan);
                cell.setPosition(j * cellSize, i * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
    }
    return 0;
}
