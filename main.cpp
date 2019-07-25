

#include <iostream>
#include <numeric>

#include <map>






template <class T, T DEFAULT_VALUE>
class Matrix_two{
public:
    Matrix_two(){
    }

    class Proxy {
    public:
        Proxy(std::map<T, T> map) : m_curMap(map) { }
        T operator[](int idx) {
             return m_curMap[idx];
//            if(idx == -1) return DEFAULT_VALUE;
//            auto it = m_curMap.find(idx);
//            if(it != m_curMap.end()) return m_curMap[idx];
//            return DEFAULT_VALUE;
        }

    private:
        std::map<T, T> m_curMap;
    };


    Proxy operator[](int idx) {
        return m_map[idx];
//        auto it = m_map.find(idx);
//        if(it != m_map.end()) return m_map[idx];
//        return Proxy(m_hlpMap[-1]);
    }


    // wtf ?
    auto size(){
        auto allAcc = std::accumulate(std::begin(m_map),std::end(m_map), 0 ,
                        [] (auto prevSize, const typename std::map<T, std::map<T,T>>::value_type &p) {return prevSize + p.second.size(); });

        std::cout << __PRETTY_FUNCTION__ <<" "<<allAcc << " "<<m_map.size()<<std::endl;
        return allAcc+m_map.size();
    }

private:

    std::map<T, std::map<T,T>>  m_map;
    std::map<T, std::map<T,T>>  m_hlpMap;
};


template <typename T>
class DefaultContainer : public std::map<int, T>
{
};




template <class ... Args1>
class Matrix_5{
    typedef Matrix_5 <T, dimensions-1, Container> itemType;
};

template <class T,T DEFAULT_VALUE>
class Matrix_5<T>{

};

//template <typename T,
//          int dimensions,
//          template <typename> class Container = DefaultContainer
//          >
//class Matrix_4{
//    typedef Matrix_4<T, dimensions-1, Container> itemType;

//    Container<itemType> m_data;

//public:
//    /**
//     * This returns an item of the array m_data which is probably a matrix
//     * of less dimensions that can be further accessed be the same operator
//     * for resolving another dimension.
//     */
//    itemType& operator[](int idx)
//    {
//        return m_data[idx];
//    }

//    const itemType& operator[](int idx) const
//    {
//        return m_data[idx];
//    }

//};

//template <typename T,
//          template <typename> class Container
//          >
//class Matrix_4<T,1,Container>
//{
//    /**
//     * Here we are defining an array of itemType which is defined to be T.
//     * so we are actually defining an array of T.
//     */
//    typedef T itemType;

//    Container<itemType> m_data;

//public:
//    itemType& operator[](int idx)
//    {
//        return m_data[idx];
//    }

//    const itemType& operator[](int idx) const
//    {
//        return m_data[idx];
//    }
//};


//std::tie(i, b) = images.emplace(w, img);



int main(int, char *[])
{
//    Matrix_4<int,2> matr;
//    std::cout<< matr[0][0] << std::endl;
//    matr[0][0] = 10;
//    std::cout<< matr[0][0] << std::endl;
//    Matrix_two<int, -4> matrix;
//    std::cout << matrix[0][0] << std::endl;
//    std::cout << matrix[1][0] << std::endl;
//    std::cout << matrix[0][2] << std::endl;
//    std::cout << matrix[0][10] << std::endl;
//    std::cout << matrix.size() << std::endl;

//    matrix[0][0] = 10;
//    std::cout << matrix[0][0] << std::endl;

}
