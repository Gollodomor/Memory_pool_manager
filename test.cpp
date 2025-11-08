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
    int* tmp;
    double ansver;
    mp::Memory_pool_int memory(Memory); // Выделяем pool(область для создания) размером Memory

    // Тут такая запись через tmp только для крастоты при вводе чисел
    // чтобы логи модуля не засоряли экран
    // если нужно, их можно закомментить через реплейс std на // в .cpp файле модуля

    std::cout << "Доступные операторы: +  -  *  /" << std::endl;
    tmp = memory.get_int();
    std::cout << "Введите число: ";
    std::cin >> *tmp;
    std::cout << "Введите оператор: ";
    std::cin >> operator_char1;
    tmp = memory.get_int();
    std::cout << "Введите число: ";
    std::cin >> *tmp;
    std::cout << "Введите оператор: ";
    std::cin >> operator_char2;
    tmp = memory.get_int();
    std::cout << "Введите число: ";
    std::cin >> *tmp;


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
}


int main()
{

    void calculator();
    calculator();
    return 0;

}

