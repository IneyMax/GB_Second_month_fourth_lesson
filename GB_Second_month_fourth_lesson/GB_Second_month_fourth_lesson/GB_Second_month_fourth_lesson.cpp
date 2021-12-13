#include "Array_Int.h"

int main()
{
    // Объявляем массив с 10 элементами
    ArrayInt my_array(10);
 
    // Заполняем массив числами от 1 до 10
    for (int i=0; i<10; i++)
        my_array[i] = i+1;
 
    // Изменяем размер массива до 7 элементов
    my_array.resize(7);
    
    my_array.insert_before(15, 3);
    my_array.insert_at_end(35);
    my_array.insert_at_beginning(50);


    
    { // task 1
        my_array.print_array();

        my_array.sort_array();
        my_array.print_array();
    
        my_array.pop_front_array();
        my_array.pop_back_array();
    
        my_array.print_array();
    }
 
    return 0;
}
