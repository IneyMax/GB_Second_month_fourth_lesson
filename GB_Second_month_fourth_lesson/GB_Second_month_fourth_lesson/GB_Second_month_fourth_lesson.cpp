#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

#include "Array_Int.h"

// Для рандомной инициализации массива:
int get_random_number()
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(0,10); // distribute results between 1 and 6 inclusive.
    return dist(gen);
}

int main()
{
    {   // task 1
        
        ArrayInt my_array(10);
        
        for (int i=0; i<10; i++)
            my_array[i] = i+1;
        
        my_array.resize(7);
        my_array.insert_before(15, 3);
        my_array.insert_at_end(35);
        my_array.insert_at_beginning(50);

        my_array.print_array();

        my_array.sort_array();
        my_array.print_array();
    
        my_array.pop_front_array();
        my_array.pop_back_array();
    
        my_array.print_array();
    }

    {   // task 2
        std::vector<int> my_vector;
        my_vector.resize(10);
        int i {0};
        while ( i < my_vector.size() )
        {
            my_vector[i] = get_random_number();
            i ++;
        }

        for (int t = 0; t < my_vector.size(); ++t)
        {
            std::cout << my_vector[t] << " ";
        }
        std::cout << std::endl;

        std::unordered_set<int> various_numbers;
        
        for (int t = 0; t < my_vector.size() - 1; ++t)
        {
            various_numbers.emplace(my_vector[t]);
        }

        std::cout << "Various numbers: " << various_numbers.size();
    }
    
    return 0;
}
