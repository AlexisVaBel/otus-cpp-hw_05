#include "matrsrc/dischmatrix.h"

#include <iostream>



int main(int, char *[])
{

    DischMatrix<int, 0> matrix;

    int value = 1;

    for(auto i = 1; i< 10; ++i){
        for(auto j = 1; j < 10; ++j){
            if( i == j) (matrix[i][j] = value++);
        }
    }
    value = 9;
    for(auto i = 0; i< 10; ++i){
        for(auto j = 9; j > 0; --j){
            if( i + j == 9) (matrix[i][j] = value--);
        }
    }

    for(auto i = 1; i< 9; ++i){
        for(auto j = 1; j < 9; ++j){
            std::cout << matrix[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    std::cout << matrix.size() << std::endl;
    return 0;
}
