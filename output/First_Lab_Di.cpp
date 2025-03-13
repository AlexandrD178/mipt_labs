#include <iostream>
#include <random>
#include <chrono>

int rand_key(int len) {
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned> dstr(0, len - 1);

    return dstr(rng);

}

bool searching_func(int len, int key, int arr[]) {
    for (int counter = 0; counter < len; ++counter) {
        if (arr[counter] == key) return 1;
    }

    return 0;
}

float counting_time(int len) {
    int arr[len] = {};
    for (int i = 0; i < len; ++i) 
        arr[i] = i;

    int key = rand_key(len);
        

    auto begin = std::chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt !=0; --cnt) {
        searching_func(len, key, arr);
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