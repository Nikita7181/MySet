#include <iostream>
#include <string>
#include "mySet.h"

int main ()
{
    mySet<int, myComparator<int>> msi1;
    msi1.insert(1);
    msi1.insert(5);
    msi1.insert(2);
    msi1.insert(7);
    msi1.insert(9);
    msi1.insert(3);
    msi1.print();
    std::cout << std::endl;

    mySet<int, myComparator<int>> msi2;
    msi1.insert(3);
    msi2.insert(10);
    msi2.insert(50);
    msi2.insert(20);
    msi2.insert(70);   

    msi2.print();
    std::cout << std::endl;
    //std::cout << msi1.empty();

    //mySet<int, myComparator<int>> msi2;
    //std::cout << msi2.empty();

    mySet<std::string, myComparator<std::string>> mss1;
    mss1.insert("first");
    mss1.insert("second");
    mss1.insert("first2");
    mss1.insert("second3");
    mss1.print();

    msi1.swap(msi2);
    std::cout << std::endl;
    std::cout << "--------------------msi1-------------------------" << std::endl;
    msi1.print();
    std::cout << std::endl;
    std::cout << "--------------------msi2-------------------------" << std::endl;
    msi2.print();
    std::cout << std::endl;
//    msi1.clear();
//    msi1.print();
//    std::cout <<std::endl;
//    std::cout << *(msi1.begin()+2) << std::endl;
//    msi1.erase(msi1.begin(), msi1.begin()+3);
//    msi1.print();
    msi1.merge(msi2);
    std::cout << "--------------------msi1-------------------------" << std::endl;
    msi1.print();
    std::cout << std::endl;
    std::cout << "--------------------msi2-------------------------" << std::endl;
    msi2.print();
    std::cout << std::endl;

    //msi1.swap(msi2);
}