#ifndef DISCHMATRIX_H
#define DISCHMATRIX_H

#include <iostream>
#include <numeric>

#include <tuple>
#include <map>
#include <vector>

#include <boost/algorithm/string.hpp>


// "U volshebnika Sulejmana vse po chestnomu, bez obmana"
// cheers, Sulejman (A.Beljev)

template <typename T, T DEFAULT, size_t DIMENSION = 2>
class DischMatrix {    
    using matrix_key        =  std::array<std::size_t, DIMENSION>;
    using matrix_value      =  T;
    using matrix_templ      = std::map<matrix_key,matrix_value>;

public:
    DischMatrix():m_matrix() {
    }
    ~DischMatrix(){
    }

    class Proxy {
        friend class DischMatrix;
    public:
        Proxy(DischMatrix &matr, int index):_matr(matr),_dimension(0){
            _matrKey[_dimension++]=index;
        }

        Proxy & operator[] (int index){                        
            _matrKey[_dimension++]=index;
            return *this;
        }



        template< class Perf>
        Proxy& operator=(Perf&& value) {
            auto fwdValue = std::forward<Perf>(value);

            if(DIMENSION != _dimension){
                throw std::length_error("Assign to non-available cell of matrix");
            }

            if(fwdValue != DEFAULT) {
                _matr.m_matrix[_matrKey] = fwdValue;
            } else {                
                auto it = _matr.m_matrix.find(_matrKey);
                if(it   != _matr.m_matrix.end()){
                    _matr.m_matrix.erase(it);
                }

            }
            return *this;
        }

        operator matrix_value(){            
            if(DIMENSION != _dimension){
                throw std::length_error("Access to non-available cell of matrix");
            }            
            auto it = _matr.m_matrix.find(_matrKey);
            if(it == _matr.m_matrix.end()){
                return DEFAULT;
            }
            return it->second;
        }

    private:
        DischMatrix&  _matr;        
        int           _dimension;
        matrix_key    _matrKey;
    };

    auto operator[](int index) {
        return Proxy(*this, index);
    }

    size_t size(){
        return m_matrix.size();
    }

// iterator placement
    template <typename R>
    class Matrix_iterator: public std::iterator< std::forward_iterator_tag, R>
    {

    public:
        Matrix_iterator(const R& pnt): m_pnt(pnt){}

        auto operator*(){
            auto tmp = a2t<std::size_t, DIMENSION>(m_pnt->first);
            return  std::tuple_cat(tmp,std::make_tuple(m_pnt->second));

        }
        const Matrix_iterator<R> & operator++(){
            m_pnt++;
            return *this;
        }

        bool operator!=(const Matrix_iterator<R> &other) const{
            return this->m_pnt != other.m_pnt;
        }
    private:
        R m_pnt;

        // Convert array into a tuple - https://en.cppreference.com/w/cpp/utility/integer_sequence
        template<typename Array, std::size_t... I>
        auto a2t_impl(Array& a, std::index_sequence<I...>)
        {
            return std::make_tuple((a.at(I))...);
        }

        template<typename U, std::size_t N, typename Indices = std::make_index_sequence<N>>
        auto a2t(const std::array<U,N>& a)
        {
            return a2t_impl(a, Indices{});
        }
        //~ Convert array into a tuple - https://en.cppreference.com/w/cpp/utility/integer_sequence
    };

//~ iterator placement


    auto begin(){
        return Matrix_iterator<typename std::map<matrix_key,matrix_value>::iterator> (m_matrix.begin());
    }
    auto end(){
        return Matrix_iterator<typename std::map<matrix_key,matrix_value>::iterator> (m_matrix.end());
    }

private:    



    matrix_templ m_matrix;
};



#endif // DISCHMATRIX_H
