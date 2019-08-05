#define BOOST_TEST_MODULE matrix_fill_test_module


#include <boost/test/unit_test.hpp>
#include "../matrsrc/dischmatrix.h"

static const int I_DEFAULT_MATRIX = -2;
static const int I_SOMEV_MATRIX = 234;


BOOST_AUTO_TEST_SUITE(matrix_fill_test_suite)



BOOST_AUTO_TEST_CASE(matrix_create_empty){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    BOOST_CHECK(matrix.size() == 0);
}


BOOST_AUTO_TEST_CASE(matrix_create_default){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    auto a = matrix[0][0];
    BOOST_CHECK(a == I_DEFAULT_MATRIX);

}

BOOST_AUTO_TEST_CASE(matrix_fill_default){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    matrix[0][0] = I_DEFAULT_MATRIX;
    auto a = matrix[0][0];
    BOOST_CHECK(a == I_DEFAULT_MATRIX);
    BOOST_CHECK(matrix.size() == 0);
}


BOOST_AUTO_TEST_CASE(matrix_fill_some_check_some){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    matrix[0][0] = I_SOMEV_MATRIX;
    auto a = matrix[0][0];
    BOOST_CHECK(a == I_SOMEV_MATRIX);
    BOOST_CHECK(matrix.size() == 1);
}


BOOST_AUTO_TEST_CASE(matrix_fill_some_fill_default){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    matrix[0][0] = I_SOMEV_MATRIX;
    auto& a = matrix[0][0];
    BOOST_CHECK(a == I_SOMEV_MATRIX);
    BOOST_CHECK(matrix.size() == 1);
    matrix[0][0] = I_DEFAULT_MATRIX;
    BOOST_CHECK(a == I_DEFAULT_MATRIX);
    BOOST_CHECK(matrix.size() == 0);
}

BOOST_AUTO_TEST_CASE(matrix_with_idxs){
    DischMatrix<int, I_DEFAULT_MATRIX> matrix;
    matrix[10][20] = I_SOMEV_MATRIX;
    auto a = matrix[10][20];
    BOOST_CHECK(a == I_SOMEV_MATRIX);
    for(auto c: matrix){
        int x;
        int y;
        int v;
        std::tie(x, y, v) = c;
        BOOST_CHECK(x == 10);
        BOOST_CHECK(y == 20);
        BOOST_CHECK(v == I_SOMEV_MATRIX);
    }
}

BOOST_AUTO_TEST_CASE(matrix_with__three){
    DischMatrix<int, I_DEFAULT_MATRIX,3> matrix;
    matrix[10][20][25]= I_SOMEV_MATRIX;
    auto a = matrix[10][20][25];
    BOOST_CHECK(a == I_SOMEV_MATRIX);
    for(auto c: matrix){
        int x;
        int y;
        int v;
        int q;
        std::tie(x, y, v, q) = c;
        BOOST_CHECK(x == 10);
        BOOST_CHECK(y == 20);
        BOOST_CHECK(v == 25);
        BOOST_CHECK(q == I_SOMEV_MATRIX);
    }
}

BOOST_AUTO_TEST_CASE(matrix_with_six){
    DischMatrix<int, I_DEFAULT_MATRIX,6> matrix;
    matrix[10][20][25][0][2][1000] = I_SOMEV_MATRIX;
    auto a = matrix[10][20][25][0][2][1000];
    BOOST_CHECK(a == I_SOMEV_MATRIX);
    for(auto c: matrix){
        int a;
        int b;
        int d;
        int e;
        int f;
        int g;
        int h;
        std::tie(a, b, d, e, f, g, h) = c;
        BOOST_CHECK(a == 10);
        BOOST_CHECK(b == 20);
        BOOST_CHECK(d == 25);
        BOOST_CHECK(e == 0 );
        BOOST_CHECK(f == 2 );
        BOOST_CHECK(g == 1000);
        BOOST_CHECK(h == I_SOMEV_MATRIX);
    }
}

BOOST_AUTO_TEST_SUITE_END()
