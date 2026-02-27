#include <iostream>
#include <vector>
#include <chrono>
#include <stack>   

bool find_in_stack(std::stack<int>& s, int target) {
    std::stack<int> help; 
    bool found = false; 

    while (s.size() > 0) {
        if (s.top() == target) {
            found = true;
            break; 
        }
        help.push(s.top());
        s.pop();
    }

    while (help.size()>0) {
        s.push(help.top());
        help.pop();
    }

    return found;
}

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = std::chrono::high_resolution_clock::now();
    auto result = func(std::forward<Args>(args)...);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    return std::make_pair(result, duration.count());
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<int> sizes = { 10, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000 };

    for (int n : sizes) {
        std::stack<int> my_stack;

        my_stack.push(345);
        for (int i = 0; i < n - 1; ++i) {
            my_stack.push(0);
        }

        auto [found, time] = measure_execution_time(find_in_stack, my_stack, 345);

        std::cout << "Размер: " << n << "  Время выполнения: " << time << " мс" << std::endl;
    }

    return 0;
}