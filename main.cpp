

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




template <typename T, T ... Args>
class Matrix_5{

    typedef Matrix_5 <T, Args ...> itemType;

    std::map<T,itemType> m_matrix;

public:
    Matrix_5(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~Matrix_5(){

    }

    itemType& operator[](int idx)
    {
        return m_matrix[idx];
    }

    const itemType& operator[](int idx) const
    {
        return m_matrix[idx];
    }

};

template <typename T,T DEF>
class Matrix_5<T,DEF>{
    typedef T itemType;
    typedef std::map<itemType,itemType> holdType;

    std::map<itemType,holdType> m_matrix;
public:
    Matrix_5(){
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    holdType& operator[](int idx)
    {
        return m_matrix[idx];
    }

    const holdType& operator[](int idx) const
    {
        return m_matrix[idx];
    }
};



//std::tie(i, b) = images.emplace(w, img);



int main(int, char *[])
{
    Matrix_5<int,2> matr5;
    std::cout << matr5[0][0] << std::endl;
    matr5[0][0]= 10;
    std::cout << matr5[0][0] << std::endl;
    std::cout << matr5[0][1] << std::endl;
    matr5[0][1]= 12;
    std::cout << matr5[0][1] << std::endl;

    return 0;
}
