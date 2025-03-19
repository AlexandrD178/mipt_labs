#include <iostream>
#include <random>
#include <chrono>

int rand_key(int len) {                     //function returning one random value from (0, len)
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, len - 1);

    return dstr(rng);

}

bool searched_func(int len, int key, int arr[]) {              //function, which executive time I want to measure
    int l = 0;
    int r = len - 1;
    unsigned long long mid;

    while (l <= r) {
        mid = l + (r-l)/2;

        if (arr[mid] == key) return true;
        if (arr[mid] > key) r = mid - 1; else l = mid + 1;
    }

    return false;
}

float counting_time(int len) {              
    int arr[len] = {};                  //creat ordered array {1, 2, ... len}
    for (int i = 0; i < len; ++i) 
        arr[i] = i;
        
    int key_arr[1000000];
    for (int i = 0; i < 1000000; ++i) {
        key_arr[i] = rand_key(len);     //array of random keys
    }

    auto begin = std::chrono::steady_clock::now();         
    for (int i = 0; i < 1000000; ++i) {
        searched_func(len, key_arr[i], arr);
    }
    auto end = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    return time_span.count();
}



int main() {
    for (int len = 100; len < 1000000; len += 10000) {
        std::cout << len << ' ' << counting_time(len) << '\n';
    }
    std::cout << std::endl;
}