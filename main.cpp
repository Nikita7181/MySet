#include <iostream>
#include <string>
#include "mySet.h"

int main ()
{
    mySet<int, myComparator<int>> msi0;
    for (int i = 0; i < 100; i++)
    {
        msi0.insert(i);
    }

    mySet<int, myComparator<int>> msi1;
    msi1.insert(1);
    msi1.insert(5);
    msi1.insert(2);
    msi1.insert(7);
    msi1.insert(6);
    msi1.insert(9);
    msi1.insert(3);
    msi1.insert(2);

    std::cout << std::endl << "int set 1 " << "Size " << msi1.size() << std::endl;
    msi1.print();

    mySet<int, myComparator<int>> msi2;
    msi2.insert(10);
    msi2.insert(50);
    msi2.insert(1);
    msi2.insert(20);
    msi2.insert(70);   
    msi2.insert(3);

    std::cout << std::endl << "int set 2 " << "Size " << msi2.size() << std::endl;
    msi2.print();
    //std::cout << msi1.empty();

    //mySet<int, myComparator<int>> msi2;
    //std::cout << msi2.empty();

    mySet<std::string, myComparator<std::string>> mss1;
    mss1.insert("first");
    mss1.insert("second");
    mss1.insert("first2");
    mss1.insert("second3");
    std::cout << std::endl << "string" << std::endl;
    mss1.print();

    //msi1.swap(msi2);
    //std::cout << std::endl;
    //msi1.print();
    //msi2.print();
    //msi1.clear();
    //msi1.print();

    std::cout << std::endl << "int set 1; count(10) " << msi2.count(10)<< std::endl;
    std::cout << std::endl << "int set 1; find(10) " << *msi2.find(10);

    std::cout <<std::endl << "Merge ";
    msi1.merge(msi2);
    std::cout << std::endl << "int set 1" << std::endl;
    msi1.print();
    std::cout << std::endl << "int set 2" << std::endl;
    msi2.print();
    std::cout <<std::endl << "Extract by val = " << msi1.extract(2) <<std::endl;
    msi1.print();
    std::cout <<std::endl << "Extract by iter (begin): val = " << msi1.extract(msi1.begin()) <<std::endl;
    msi1.print();
    std::cout <<std::endl << "Erase begin()++" <<std::endl;
    mySetIterator<int> it = msi1.begin();
    it++;

    msi1.erase(it);
    msi1.print();
    std::cout <<std::endl << "Erase by from begin to end" <<std::endl;
    auto it2 = msi1.end();
    auto it1 = msi1.begin();
    msi1.erase(it1,it2);
    msi1.print();
    std::cout << "Size " <<msi1.size() << std::endl;
 
    std::cout << std::endl << "Reverse iterator print" << std::endl;
    msi2.r_print();
    std::cout << std::endl << "--------------------" << std::endl;
    msi0.r_print();

}
