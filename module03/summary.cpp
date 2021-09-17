#include <vector>
#include <iostream>
#include <parallel/algorithm>
#include <parallel/numeric>

/*
 1-pass
 sayilar = [4,8,15,16,23,42]
 1-pass
 sayilar.filter( (x) => { return x%2 == 0;} )
        .map( (u) => {return u*u;})
        .reduce((a,b)=>{return a+b;}, 0)
  ranges -> 1-pass
  python, js, java, c#, ... -> generator function -> lazy evaluation
 */
using namespace std;

auto
is_even(int x) { // 1
    return x % 2 == 0;
}

auto
make_squared(int x) { // 1
    return x * x;
}

auto
add(int x, int y) { // 1
    return x + y;
}

struct Even {
    auto operator()(int x) { return x % 2 == 0; }
};

struct Squared {
    auto operator()(int x) { return x * x; }
};

struct Add {
    typename <class T>
    auto operator()(T x, T y) { return x + x; }
};

int main() {
    vector<int> numbers{4, 8, 15, 16, 23, 42};
    // filter(even) -> map(squared) -> folding/reduce(summation)
    vector<int> even_numbers;
    // (1) global function
    //copy_if(numbers.begin(),numbers.end(), back_inserter(even_numbers), is_even); // filter(even)
    //transform(even_numbers.begin(),even_numbers.end(), squared_numbers.begin(), make_squared); // map(squared)
    //auto result = reduce(squared_numbers.begin(),squared_numbers.end(), 0,add); // folding/reduce(summation)
    // (2) lambda expression -> syntactic sugar -> (3) function object
    //copy_if(numbers.begin(), numbers.end(), back_inserter(even_numbers),
    //        [](auto x) { return x % 2 == 0; }); // filter(even)
    //vector<int> squared_numbers(even_numbers.size());
    //transform(even_numbers.begin(), even_numbers.end(), squared_numbers.begin(),
    //          [](auto x) { return x * x; }); // map(squared)
    //auto result = reduce(squared_numbers.begin(), squared_numbers.end(), 0,
    //                     [](auto x, auto y) { return x + y; }); // folding/reduce(summation)
    // (3) function object (functor)
    copy_if(numbers.begin(), numbers.end(), back_inserter(even_numbers),
            Even() ); // filter(even)
    vector<int> squared_numbers(even_numbers.size());
    transform(even_numbers.begin(), even_numbers.end(), squared_numbers.begin(),
              Squared()); // map(squared)
    auto result = reduce(squared_numbers.begin(), squared_numbers.end(), 0,
    //                     Add()); // folding/reduce(summation)
                         //plus<int>()); // folding/reduce(summation)
                         plus<>()); // folding/reduce(summation), since c++14
                         cout << "Result is " << result << endl;
    // (4) Partial Function -> fun(x,y) -> y=2 g(x)
    //   sun(x,y,z) -> run(x,y,z) -> sun(z,y,x)
    //     Currying
    return 0;
}
