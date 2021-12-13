#pragma once

#include <cassert> // для assert()
 
class ArrayInt
{
    int m_length;
    int *m_data;
 
public:
    ArrayInt():
        m_length(0), m_data(nullptr)
    {
    }
 
    ArrayInt(int length):
        m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
 
    void erase();
    // Функция reallocate() изменяет размер массива. Все существующие элементы внутри массива будут уничтожены. Процесс быстрый
    void reallocate(int newLength);
    // Функция resize() изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength);
    void insert_before(int value, int index);
    void remove(int index);
    void insert_at_beginning(int value);
    void insert_at_end(int value);
    int getLength() const;

    // ДЗ 1:
    void pop_front_array();
    void pop_back_array();
    void print_array() const;
    void sort_array();
    void quick_sort_array (int start, int end);

    int& operator[](int index);
    
    ~ArrayInt()
    {
        delete[] m_data;
    }
};
