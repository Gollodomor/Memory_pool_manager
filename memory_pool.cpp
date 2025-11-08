#include"memory_pool.hpp"
#include<iostream>

using namespace mp;

Memory_pool_int::Memory_pool_int(int size_of_pool = 1)
    : size_of_pool_{size_of_pool}
    , ptr_pool_{new int[size_of_pool]}
    , ptr_pool_list_{new int*[size_of_pool]}
    , iter_{0}
{
    //std::cout << "Memory pool из " << size_of_pool_ << " элементов создан" << std::endl;
    for(int i = 0; i < size_of_pool_; i++)
    {
        ptr_pool_list_[i] = nullptr;
    }
}

int* const Memory_pool_int::get_int()
{
    for(int i = 0; i < size_of_pool_; i++)
    {
        if(iter_ == size_of_pool_)
        {
            iter_ = 0;
        }
        if(ptr_pool_list_[iter_] == nullptr)
        {
            ptr_pool_list_[iter_] = &ptr_pool_[iter_];
            //std::cout << "Выделена память под адресом " << ptr_pool_list_[iter_] << std::endl;
            iter_++;
            return ptr_pool_list_[iter_-1];
        }
        iter_++;
    }
    //std::cout << "Нет места для нового значения, освободите старое" << std::endl;
    return nullptr;
}

int* const Memory_pool_int::get_next_int_ptr()
{
    if(iter_ == size_of_pool_)
    {
        iter_ = 0;
    }

    if(ptr_pool_list_[iter_] != nullptr)
    {
        iter_++;
        return ptr_pool_list_[iter_ -1];
    }
    return nullptr;
}

void Memory_pool_int::delete_int(int* const ptr)
{
    int* ptr_tmp = ptr;

    //std::cout << "int под интексом " << ptr << " удален" << std::endl;

    for(int i = 0; i < size_of_pool_; i++)
    {
        if(ptr_pool_list_[i] == ptr_tmp)
        {
            ptr_pool_list_[i] = nullptr;
        }
        *ptr_tmp = 0;
    }

}

void Memory_pool_int::delete_last_int() // Если итератор на позиции 0, то происходит аборт программы
{
    int tmp = iter_;
    for(int i = 1; i < size_of_pool_ - iter_; ++i)
    {
        if(iter_ > 0 && ptr_pool_list_[iter_-i] != nullptr)
        {
            //std::cout << "int под интексом " << ptr_pool_list_[iter_-i] << " успешно удален" << std::endl;
            ptr_pool_[iter_-i] = 0;
            ptr_pool_list_[iter_-i] = nullptr;
            break;
        }
        if(iter_-i < 0)
        {
            iter_ = size_of_pool_;
            if(ptr_pool_list_[iter_-i] != nullptr)
            {
                //std::cout << "int под интексом " << ptr_pool_list_[iter_-i] << " успешно удален" << std::endl;
                iter_ = size_of_pool_;
                ptr_pool_[iter_-i] = 0;
                ptr_pool_list_[iter_-i] = nullptr;
                break;
            }
        }
        iter_ = tmp;
        iter_ -= i; //вот это можно расскоментить, и я хз че будет, вроде работает так же
    }

}

std::string Memory_pool_int::print_all_nums()
{
    std::cout << "Последний полученный адрес = " << iter_ << std::endl;
    for(int i = 0; i < size_of_pool_; i++)
    {
        std::cout<< "Адрес " << ptr_pool_list_[i] << " = ";
        std::cout << ptr_pool_[i] << std::endl;
    }
    return "";// ДОПИСАТЬ
}

Memory_pool_int::~Memory_pool_int()
{
    delete[] ptr_pool_;
    delete[] ptr_pool_list_;
    //std::cout << "Memory pool удалена" << std::endl;
}


