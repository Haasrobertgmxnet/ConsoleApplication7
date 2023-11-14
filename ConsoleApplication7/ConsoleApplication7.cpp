// ConsoleApplication7.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <numbers>
#include <functional>
#include <vector>

template<typename T, typename U>
std::vector<T> vectorialFuncIteration(const U& itb, const U& ite, const std::function<T(T)>& func) {
    if (itb == ite) {
        return std::vector<T>({});
    }
    std::vector<T> res;
    std::transform(itb, ite, std::back_inserter(res), [&func](const T& t) { return func(t); });
    return res;
}

template<typename T, typename U>
std::vector<T> vectorialFuncRecursion(const U& itb, const U& ite, const std::function<T(T)>& func) {
    if (itb == ite) {
        return std::vector<T>({});
    }
    std::vector<T> res = vectorialFuncRecursion(itb, ite - 1, func);
    res.push_back(func(*(ite - 1)));
    return res;
}

int main()
{
    std::vector<double> x = { 0.25, 0.5, 0.75, 1.0 };
    std::transform(x.begin(), x.end(), x.begin(), [](double t) { return t*std::numbers::pi; });
    std::for_each(x.cbegin(), x.cend(), [](double t) {std::cout << t << std::endl; });
    std::cout << std::endl;

    std::vector<double> y = vectorialFuncRecursion<double, std::vector<double>::const_iterator>(x.cbegin(), x.cend(), [](double t)->double {return std::sin(t); });
    std::for_each(y.cbegin(), y.cend(), [](double t) {std::cout << t << std::endl; });
    std::cout << std::endl;

    std::vector<double> z = vectorialFuncIteration<double, std::vector<double>::const_iterator>(x.cbegin(), x.cend(), [](double t)->double {return std::sin(t); });
    std::for_each(z.cbegin(), z.cend(), [](double t) {std::cout << t << std::endl; });
    std::cout << std::endl;

    std::cout << "End!\n";
}
