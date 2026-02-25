#include <iostream>
#include <vector>
#include <chrono>

bool find_in_stack(const std::vector<int>& stack, int target) {
    for (int i = 0; i < stack.size(); i++) {
        if (stack[i] == target) 
            return true;
    }
    return false;
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
    std::vector<int> sizes = { 10, 100, 10000, 100000, 1000000, 8000000, 10000000, 25000000, 50000000, 100000000, 1000000000 };

    for (int n : sizes) {
        std::vector<int> stack(n, 0);
        stack[n - 1] = 345; 

        auto [found, time] = measure_execution_time(find_in_stack, stack, 345);
        std::cout <<"Размер: " << n << " Время выполнения: " << time << std::endl;
    }

    return 0;
}

