#include <iostream>
#include <chrono>
#include <fstream>

int *add_el(int *arr, unsigned long long length, int el, unsigned long long max_size) {
    if (length == max_size) {
        unsigned long long new_max_size = max_size * 2;
        int *new_arr = new int[new_max_size];

        for (unsigned long long i = 0; i < length; ++i) new_arr[i] = arr[i];

        new_arr[length] = el;

        max_size = new_max_size;
        delete[] arr;

        return new_arr;
    } else {
        arr[length] = el;
        return arr;
    }
}

int main () {
std::ofstream out_file("Lab_2_X2.txt");

    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) arr[i] = 0;

    unsigned long long t = 0;

    for (unsigned long long l = 10; l < 10010; ++l) {
        auto begin = std::chrono::steady_clock::now();
        for (unsigned long long i = 0; i < 100000; ++i) arr = add_el(arr, l, 1, 10);
        auto end = std::chrono::steady_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        t = t + time_span.count();

        out_file << l << " " << t << std::endl;
    }
}