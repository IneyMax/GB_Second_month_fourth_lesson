#include "Array_Int.h"

#include <iostream>
#include <thread>

void ArrayInt::erase()
{
    delete[] m_data;
    // Здесь нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
    m_data = nullptr;
    m_length = 0;
}

void ArrayInt::reallocate(int newLength)
{
    // Удаляем все существующие элементы внутри массива
    erase();
 
    // Если наш массив должен быть пустым, то выполняем возврат здесь
    if (newLength <= 0)
        return;
 
    // Затем выделяем новые элементы
    m_data = new int[newLength];
    m_length = newLength;
}

void ArrayInt::resize(int newLength)
{
    // Если массив нужной длины, то выполняем return
    if (newLength == m_length)
        return;
 
    // Если нужно сделать массив пустым, то делаем это и затем выполняем return
    if (newLength <= 0)
    {
        erase();
        return;
    }
 
    // Теперь предположим, что newLength состоит, по крайней мере, из одного элемента. Выполняется следующий алгоритм действий:
    // 1. Выделяем новый массив.
    // 2. Копируем элементы из существующего массива в наш только что выделенный массив.
    // 3. Уничтожаем старый массив и даем команду m_data указывать на новый массив.
 
    // Выделяем новый массив
    int *data = new int[newLength];
 
    // Затем нам нужно разобраться с количеством копируемых элементов в новый массив.
    // Нам нужно скопировать столько элементов, сколько их есть в меньшем из массивов
    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;
 
        // Поочередно копируем элементы
        for (int index=0; index < elementsToCopy ; ++index)
            data[index] = m_data[index];
    }
 
    // Удаляем старый массив, так как он нам уже не нужен
    delete[] m_data;
 
    // И используем вместо старого массива новый! Обратите внимание, m_data указывает на тот же адрес, на который указывает наш новый динамически выделенный массив.
    // Поскольку данные были динамически выделены, то они не будут уничтожены, когда выйдут из области видимости
    m_data = data;
    m_length = newLength;
}

void ArrayInt::insert_before(int value, int index)
{
    // Проверка корректности передаваемого индекса
    assert(index >= 0 && index <= m_length);
 
    // Создаем новый массив на один элемент больше старого массива
    int *data = new int[m_length+1];
 
    // Копируем все элементы аж до index
    for (int before=0; before < index; ++before)
        data [before] = m_data[before];
 
    // Вставляем наш новый элемент в наш новый массив
    data [index] = value;
 
    // Копируем все значения после вставляемого элемента
    for (int after=index; after < m_length; ++after)
        data[after+1] = m_data[after];
 
    // Удаляем старый массив и используем вместо него новый массив
    delete[] m_data;
    m_data = data;
    ++m_length;
}

void ArrayInt::remove(int index)
{
    // Проверка на корректность передаваемого индекса
    assert(index >= 0 && index < m_length);
 
    // Если это последний элемент массива, то делаем массив пустым и выполняем return
    if (m_length == 1)
    {
        erase();
        return;
    }
 
    // Cоздаем новый массив на один элемент меньше нашего старого массива
    int *data = new int[m_length-1];
 
    // Копируем все элементы до index
    for (int before=0; before  < index; ++before)
        data[before] = m_data[before];
 
    // Копируем все значения после удаляемого элемента
    for (int after=index+1; after < m_length; ++after )
        data[after-1] = m_data[after];
 
    // Удаляем старый массив и используем вместо него новый массив
    delete[] m_data;
    m_data = data;
    --m_length;
}

void ArrayInt::insert_at_beginning(int value)
{
    insert_before(value, 0);
}

void ArrayInt::insert_at_end(int value)
{
    insert_before(value, m_length);
}

int ArrayInt::getLength() const
{
    return m_length;
}

void ArrayInt::pop_front_array()
{
    remove(0);
}

void ArrayInt::pop_back_array()
{
    remove(m_length - 1);
}

void ArrayInt::print_array() const
{
    // Выводим все элементы массива
    for (int j = 0; j < m_length; j++)
        std::cout << m_data[j] << " ";
    std::cout << std::endl;
}

void ArrayInt::sort_array()
{
    quick_sort_array(0, m_length);
}


void ArrayInt::quick_sort_array(int start, int end)
{
    int left_index {start};
    int right_index {end - 1};
    int pivot_value {m_data[((start + end)/2)]};
    
    /*
    std::cout <<"Start: " << left_index << " End: " << end << "\n";
    print_piace_array(my_array, left_index, right_index, pivot_value);
    */

    do
    {
        while (m_data[left_index] < pivot_value )
        {
            left_index ++;
        }

        while (m_data [right_index] > pivot_value)
        {
            right_index --;
        }
        
        if (left_index <= right_index) 
        {
            //std::cout <<"Left index value: " << my_array [left_index] << " Right index value: " << my_array [right_index] << "\n";
            std::swap (m_data[left_index++], m_data[right_index--]);
        }
    }
    while (left_index <= right_index);

    if (right_index > start)
    {
        // std::cout << "\n Left \n";
        quick_sort_array(start, right_index + 1);
    }
    
    if (left_index < end)
    {
        // std::cout << "\n Right \n";
        quick_sort_array(left_index, end);
    }
}

int& ArrayInt::operator[](int index)
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

