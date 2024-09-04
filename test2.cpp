#include <iostream>


int main()
{
    int prikol {true};

    std::cout << prikol << std::endl;

    prikol = false;

    std::cout << prikol << std::endl;

    //static_cast<Тип>(Данные) - явное преобразование типа

    prikol += 5;

    std::cout << prikol << std::endl;

    

    return 0;
}