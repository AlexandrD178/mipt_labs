#include <iostream>
#include <chrono>
#include <fstream>

int *add_el(int *arr, unsigned long long length, int el) {
    int *new_arr = new int[length+1];
    for (unsigned long long i = 0; i < length; ++i) new_arr[i] = arr[i];
    new_arr[length] = el;

    delete[] arr;
    return new_arr;
}

int main () {
std::ofstream out_file("Lab_2_plus1.txt");

    int *arr = new int[10];
    for (int i = 0; i < 10; ++i) arr[i] = 0;

    unsigned long long t = 0;

    for (unsigned long long l = 10; l < 5010; ++l) {
        auto begin = std::chrono::steady_clock::now();
        for (int i = 0; i < 1000; ++i) arr = add_el(arr, l, 1);
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        t = t + time_span.count();
        out_file << l << " " << t << std::endl;
    }
}

