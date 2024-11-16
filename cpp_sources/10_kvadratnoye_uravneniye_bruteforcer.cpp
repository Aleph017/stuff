#include <iostream>

int main(){
    double x = 1;
    for(x; x < 1000000; x++){
        double equation = 6*x*x + x - 2;
        if(equation == 0){
            std::cout << x << " is a root of the equation and probably -" << x << " is." << std::endl;
        }
    }
}
