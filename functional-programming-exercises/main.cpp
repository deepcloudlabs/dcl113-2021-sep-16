#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <ranges>
#include <deque>

using namespace std;
auto
is_even(int x){
    cerr << "is_even(" << x << ") is called!" << endl;
    return x%2 == 0;
}
auto
squared(int x){
    cerr << "squared(" << x << ") is called!" << endl;
    return x*x;
}

int main() {
   std::list<int> numbers {4,8,15,8,16,8,23,42};

   // 1-PASS
   for (auto number : numbers | std::ranges::views::filter(is_even)
                              | std::ranges::views::transform(squared))
   {
       cerr << number << endl;
   }

    return 0;
}