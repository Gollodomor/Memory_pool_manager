#include<string>
namespace mp{

class Memory_pool_int{
    private:

        int size_of_pool_;
        int* ptr_pool_;
        int** ptr_pool_list_;

    public:

        int iter_;
        Memory_pool_int(int size_of_pool);
        int* const get_int();
        int* const get_next_int_ptr();
        void delete_int(int* const ptr);
        void delete_last_int();
        std::string print_all_nums();
        ~Memory_pool_int();

};

} //namespace mp


