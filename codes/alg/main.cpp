#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "sort.hpp"

using namespace std;

int main()
{

    const int length = 10;
    std::vector<int> iv;
    for(int i = 0; i < length; ++i) {
        iv.push_back(rand());
    }
    std::for_each(iv.begin(), iv.end(), [](int i){std::cout << i << " ";});
    std::cout << "\n";
    //QuickSort(&iv[0], length);
//    InsertSort(&iv[0], length);
    HeapSort(&iv[0], length);
    std::for_each(iv.begin(), iv.end(), [](int i){std::cout << i << " ";});
    std::cout << "\n";


    return 0;
}
