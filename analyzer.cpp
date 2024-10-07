#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"
#include <chrono>

int linear_search(const std::vector<std::string>& container, const std::string& element) {
    int index = -1;
    for (size_t i = 0; i < container.size(); ++i) {
        if (container[i] == element) {
            index = i;
        }
    }
    return index;
}

int binary_search(const std::vector<std::string>& container, const std::string& element) {
    int mid = 0;
    int high = container.size() - 1;
    int low = 0;
    int index = -1;
    while (low <= high) {
        if (container[high] == element) {
            index = high;
            break;
        } else if (container[low] == element) {
            index = low;
            break;
        } else {
            mid = (high + low) / 2;

            if (container[mid] < element) {
                low = mid + 1;
            } else if (container[mid] > element) {
                high = mid - 1;
            } else {
                index = mid;
                break;
            }
        }
    }
    return index;
}

// Mock function to simulate stringdata.get_data()
std::vector<std::string> get_data() {
    return {"example", "data", "for", "testing", "search", "functions"};
}

int main() {
    std::cout << "Finding 'not_here'\n";
    std::cout << "Method Currently Tested: Linear Test\n";
    auto start_time = std::chrono::system_clock::now();
    int result = linear_search(get_data(), "not_here");
    std::cout << "Index Found: " << result << "\n";
    auto end_time = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;
    std::cout << "Time Taken for Linear Test: " << elapsed.count() << "\n\n";

    std::cout << "Method Currently Tested: Binary Test\n";
    start_time = std::chrono::system_clock::now();
    result = binary_search(get_data(), "not_here");
    std::cout << "Index Found: " << result << "\n";
    end_time = std::chrono::system_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Time Taken for Binary Test: " << elapsed.count() << "\n";
    std::cout << "------------------------------------------------------\n";

    std::cout << "Finding 'mwwww'\n";
    std::cout << "Method Currently Tested: Linear Test\n";
    start_time = std::chrono::system_clock::now();
    result = linear_search(get_data(), "mwwww");
    std::cout << "Index Found: " << result << "\n";
    end_time = std::chrono::system_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Time Taken for Linear Test: " << elapsed.count() << "\n\n";

    std::cout << "Method Currently Tested: Binary Test\n";
    start_time = std::chrono::system_clock::now();
    result = binary_search(get_data(), "mwwww");
    std::cout << "Index Found: " << result << "\n";
    end_time = std::chrono::system_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Time Taken for Binary Test: " << elapsed.count() << "\n";
    std::cout << "------------------------------------------------------\n";

    std::cout << "Finding 'aaaaa'\n";
    std::cout << "Method Currently Tested: Linear Test\n";
    start_time = std::chrono::system_clock::now();
    result = linear_search(get_data(), "aaaaa");
    std::cout << "Index Found: " << result << "\n";
    end_time = std::chrono::system_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Time Taken for Linear Test: " << elapsed.count() << "\n\n";

    std::cout << "Method Currently Tested:::::: Binary Test\n";
    start_time = std::chrono::system_clock::now();
    result = binary_search(get_data(), "aaaaa");
    std::cout << "Index Found::::: " << result << "\n";
    end_time = std::chrono::system_clock::now();
    elapsed = end_time - start_time;
    std::cout << "Time Taken for Binary Test:::: " << elapsed.count() << "\n";

    return 0;
}