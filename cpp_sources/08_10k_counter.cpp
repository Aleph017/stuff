#include <iostream>

int main(){
    int counter = 0;

    while(true){
        counter += 1;
        if (counter % 10000 == 0){
            std::cout << "10,000 passed" << std::endl;
        }
    }
} 
