#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
std::vector<int> steps = { 2, 4, 6, 10, 20, 50, 100 };
double simpson_rule(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);
    for (int i = 2; i < n; i += 2)
        sum += 2 * f(a + i * h);

    return (h / 3) * sum;
}
double function1(double x) {
    return std::cos(x) - std::sin(x);
}
double function2(double x) {
    return (std::sin(0.5 * x) - 0.5) - std::sin(x);
}
int main() {
    setlocale(LC_ALL, "Russian");

    for (int n : steps) {

    double area1 = simpson_rule(function1, 4.0, 5.0, n);
    double area2 = simpson_rule(function2, 5.0, 6.0, n);

    double total_area = area1 + area2;

    std::cout << "Площадь при значении  " << n << std::endl;
    std::cout << "Общая площадь закрашенной фигуры:  " << total_area << std::endl;
}
    return 0;
}