// Example program
#include <iostream>
#include <string>
#include <cassert>

template <class T>
class Array_Base
{
protected:
    T m_data;
 
public:    
    Array_Base()
    {
    }

    Array_Base(T data)
    {        
        m_data = data;
    }
 
    virtual ~Array_Base()
    {
    }
    
    virtual void print()
    {
        std::cout << "value: " << m_data << "\n";
    }
};


template<class T>
class Array : public Array_Base<T>
{
};

template<class T>
class Array<T*> : public Array_Base<T*>
{
protected:
    int m_length;    
public:
    Array(int length)
        : m_length(length)
    {        
        if(length > 0)
            this->m_data = new T[length];
        else
            this->m_data = nullptr;
    }
    
    Array(T* data, int length)
        : m_length(length)
    {
        this->m_data = new T[length];
        
        for(int i = 0; i < length; i++)
            this->m_data[i] = data[i];
    }
    
    virtual ~Array()
    {
        delete[] this->m_data;
    }
    
    virtual void print()
    {
        for(int i = 0; i < m_length; i++)
            std::cout << this->m_data[i];
        std::cout << std::endl;
    }
    
    void erase()
    {
        delete[] this->m_data;
        // Присваиваем значение nullptr для m_data, чтобы на выходе не получить висячий указатель!
        this->m_data = nullptr;
        m_length = 0;
    }
    
    void delElement(int num)
    {
        T temp = this->m_data[num - 1];
        for(int i = num - 1; i < m_length - 1; i++)
            this->m_data[i] = this->m_data[i + 1];
        this->m_data[m_length - 1] = temp;
        
        m_length--;
    }
    
    T& operator[](int index)
    {
        if(index >= 0 && index < m_length)
            return this->m_data[index];
    }
    
    T* getArray() { return this->m_data; }
 
    int getLength() { return m_length; }
};


int main()
{
    int size = 5;
    std::cout << "Enter size of array: ";
    std::cin >> size;
    
    if(std::cin.fail())
    {
        std::cin.ignore(32767, '\n');
    }
    Array<char*> arrayChar(new char[size] {'H', 'e', 'l', 'l', 'o'}, size);    
    
    arrayChar.print();
}
