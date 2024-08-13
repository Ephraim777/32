#include <iostream>
struct Size
{
size_t rows;
size_t cols;
};
template<typename T>
class MyClass
{
    size_t cols;
    size_t rows;

    T** ptr_array;
    
    using pointer = T*;
public:

    MyClass(size_t cols, size_t rows) :cols(cols), rows(rows)
    {
        ptr_array = new T * [rows];
        for (size_t i = 0; i < rows; i++)
        {
            ptr_array[i] = new T[cols]{0};
        }
    }

    ~MyClass()
    {
        for (size_t i = 0; i < rows; i++)
        {
            delete [] ptr_array[i];
            ptr_array[i] = nullptr;
        }

        delete[] ptr_array;
    }
    pointer operator[](size_t row)
    {
     if(row>=rows)
     throw std::out_of_range("row error");
     return ptr_array[row];
    }
    
  const pointer operator[](size_t row) const
    {
     if(row>=rows)
     throw std::out_of_range("row error");
     return ptr_array[row];
    }
    
    Size Size() const
    {
    return {rows,cols};
    }
    
};

int main()
{
    MyClass <int>a(2, 2);

    a[1][1] =1;
    std::cout<< a[1][1]<< std::endl;
    
    auto temp = a.Size();
    std::cout<< temp.rows << " " << temp.cols << std::endl;
  
 }