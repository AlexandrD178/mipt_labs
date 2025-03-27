#include <iostream>
#include <random>
#include <chrono>

bool searched_func(int len, int sum, int arr[]) {              //function, which executive time I want to measure
    unsigned long l = 0;
    unsigned long r = len-1;
    while (l<=r) {
        if (arr[l]+arr[r] == sum) return true;
        if (arr[l]+arr[r] < sum) l = l+1;
        else r = r-1;
    }
    return false;
}

float counting_time(int len) {              
    int arr[len] = {};                  //creat ordered array {1, 2, ... len}
    for (int i = 0; i < len; ++i) 
        arr[i] = i;

    auto begin = std::chrono::steady_clock::now();         
    for (int i = 0; i < 100000; ++i) {
        searched_func(len, 1000000, arr);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return time_span.count();
}



int main() {
    for (int len = 100; len < 100000; len += 1000) {
        std::cout << len << ' ' << counting_time(len) << '\n';
    }
    std::cout << std::endl;
}