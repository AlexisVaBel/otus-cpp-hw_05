#include "matrix/dischmatrix.h"

#include <iostream>
#include <cassert>


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

//    assert(matrix.size() == 0);
//    auto a = matrix[0][0];
//    assert(a == -1);
//    assert(matrix.size() == 0);
//    matrix[100][100] = 314;
//    assert(matrix[100][100] == 314);
//    assert(matrix.size() == 1);

//    matrix[100][100] = 314;
//    assert(matrix[100][100] == 314);
//    assert(matrix.size() == 1);

//    std::cout << matrix[3][3] << std::endl;
//    std::cout << matrix[1][5] << std::endl;
//    std::cout << "got something to process" << std::endl;
//    for(auto c: matrix)
//    {
//        int x;
//        int y;
//        int v;
//        std::tie(x, y, v) = c;
//        std::cout << x << " " << y << " " << v << std::endl;
//    }

    return 0;
}
