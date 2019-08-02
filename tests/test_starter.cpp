#define BOOST_TEST_MODULE matrix_fill_test_module


#include <boost/test/unit_test.hpp>
#include "../matrix/dischmatrix.h"

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


BOOST_AUTO_TEST_SUITE_END()
