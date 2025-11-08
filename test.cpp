///////////////////////////////////////////////
//                                           //
//  Пример работы с memory_pool библиотекой. //
//                                           //
///////////////////////////////////////////////

#include"memory_pool.hpp"
#include<iostream>

void calculator()
{
    char operator_char1, operator_char2; //будет доступно 3 оператора
    int const Memory = 3;
    double ansver;
    mp::Memory_pool_int memory(Memory); // Выделяем pool(область для создания) размером Memory

    std::cout << "Доступные операторы: +  -  *  /" << std::endl;

    std::cout << "Введите число: ";
    std::cin >> *memory.get_int();
    std::cout << "Введите оператор: ";
    std::cin >> operator_char1;
    std::cout << "Введите число: ";
    std::cin >> *memory.get_int();
    std::cout << "Введите оператор: ";
    std::cin >> operator_char2;
    std::cout << "Введите число: ";
    std::cin >> *memory.get_int();


    switch(operator_char1)
    {
        case '+':
            ansver = *memory.get_next_int_ptr() + *memory.get_next_int_ptr();
            break;
        case '-':
            ansver = *memory.get_next_int_ptr() - *memory.get_next_int_ptr();
            break;
        case '*':
            ansver = *memory.get_next_int_ptr() * *memory.get_next_int_ptr();
            break;
        case '/':
            ansver = *memory.get_next_int_ptr() / *memory.get_next_int_ptr();
            break;
    }
    switch(operator_char2)
    {
        case '+':
            ansver = ansver + *memory.get_next_int_ptr();
            break;
        case '-':
            ansver = ansver - *memory.get_next_int_ptr();
            break;
        case '*':
            ansver = ansver * *memory.get_next_int_ptr();
            break;
        case '/':
            ansver = ansver / *memory.get_next_int_ptr();
            break;
         default:
            std::cout << "чтото непонятное";
    }
    std::cout << "Ответ: " << ansver << std::endl;
    std::cout << memory.print_all_nums() << std::endl;
}


int main()
{

    void calculator();
    calculator();
    return 0;

}

