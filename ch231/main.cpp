#include <iostream>
#include "SimpleVector.h"

int main() {
    // 1. 기본 생성자 테스트
    SimpleVector<int> vec1;
    std::cout << "Initial capacity: " << vec1.capacity() << std::endl;
    std::cout << "Initial size: " << vec1.size() << std::endl;

    // 2. push_back 테스트
    for (int i = 0; i < 15; ++i) {
        vec1.push_back(i);
        std::cout << "Pushed: " << i << ", Size: " << vec1.size() << ", Capacity: " << vec1.capacity() << std::endl;
    }

    // 3. pop_back 테스트
    vec1.pop_back();
    std::cout << "After pop_back, Size: " << vec1.size() << ", Last Element: " << vec1[vec1.size() - 1] << std::endl;

    // 4. reserve 테스트
    vec1.reserve(50);
    std::cout << "After reserve(50), Capacity: " << vec1.capacity() << std::endl;

    // 5. resize 테스트
    vec1.resize(20);
    std::cout << "After resize(20), Capacity: " << vec1.capacity() << ", Size: " << vec1.size() << std::endl;

    // 6. 복사 생성자 테스트
    SimpleVector<int> vec2 = vec1;
    std::cout << "Copied vector, Size: " << vec2.size() << ", Capacity: " << vec2.capacity() << std::endl;

    // 7. sortData 테스트
    vec1.push_back(99);
    vec1.push_back(22);
    vec1.push_back(11);
    std::cout << "Before sort: ";
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    vec1.sortData();
    std::cout << "After sort: ";
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    // 8. clear 테스트
    vec1.clear();
    std::cout << "After clear, Size: " << vec1.size() << ", Capacity: " << vec1.capacity() << std::endl;


    return 0;
}