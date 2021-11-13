// Example program
#include <iostream>
#include <string>
#include <cassert>

template <class T>
class Array
{
private:
    int m_length;
    T *m_data;
 
public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }
 
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length];
        m_length = length;
    }
 
    ~Array()
    {
        delete[] m_data;
    }
 
    void Erase()
    {
        delete[] m_data;
        // Присваиваем значение nullptr для m_data, чтобы на выходе не получить висячий указатель!
        m_data = nullptr;
        m_length = 0;
    }
 
    T & operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    
    
    void delElement(int num)
    {
        T temp = m_data[num - 1];
        for(int i = num - 1; i < m_length - 1; i++)
            m_data[i] = m_data[i + 1];
        m_data[m_length - 1] = temp;
        
        m_length--;
    }
 
    int getLength() { return m_length; }
};

int main()
{
    Array<double> arrayDouble(10);
    
    for(int i = 0; i < arrayDouble.getLength(); ++i)
        arrayDouble[i] = i;
    
    for(int i = 0; i < arrayDouble.getLength(); i++)
        std::cout << arrayDouble[i] << " ";
    std::cout << std::endl;
    
    arrayDouble.delElement(2);
    
    for(int i = 0; i < arrayDouble.getLength(); i++)
        std::cout << arrayDouble[i] << " ";
    std::cout << std::endl;
}
