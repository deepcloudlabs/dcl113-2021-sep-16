#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

// std::bind
auto buyukmu = greater<double>(); // binary
auto _6_42den_buyukmu = bind(buyukmu,6,42);
auto _42den_buyukmu = bind(buyukmu,placeholders::_1,42); // unary function
auto kucukmu = bind(buyukmu,placeholders::_2,placeholders::_1) ;// binary

// std::bind ==> lambda
auto kucukmu_lambda = [](int x,int y){ return buyukmu(y,x);};
auto is_even = [](int x) -> bool {return x%2==0;};
auto is_odd = [](int x){return !is_even(x);}; // wrapper function

int main() {
    std::cout << buyukmu(6,42) << std::endl;
    std::cout << kucukmu(6,42) << std::endl;
    std::cout << kucukmu_lambda(6,42) << std::endl;
    std::cout << buyukmu(42,6) << std::endl;
    std::cout << _6_42den_buyukmu() << std::endl;
    std::cout << _42den_buyukmu(8) << std::endl;
    std::cout << is_even(42) << std::endl;
    std::cout << is_odd(42) << std::endl;

    return 0;
}
