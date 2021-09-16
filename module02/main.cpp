#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

// imperative
// auto result = statement1;
// statement2(result);
// statement3(result);

// high-order functions: filter, map, reduce/folding
// declarative
// method chaining -> fun(gun(...,run(...)))
// transform: vector<double> -> vector<double>
// deg2rad : double --> double
int counter = 0;

double
deg2rad(double degree){ // pure function -> A -> immutable class
    return ( 3.14 * degree ) / 180;
}

void
print_radiant(double rad){
    cout << rad << " " ;
}

auto order_by_age_desc(person_t &first,person_t &second){
    return first.age() > second.age();
}

void print_person(person_t &p){
    cout << p.surname() << ", " << p.name() << ", " << p.age() << endl ;
}

template <class T,class OrderBy,class CompareBy>
decltype(auto)
getOrder(OrderBy orderBy,CompareBy compareBy){
    return [orderBy, compareBy](const T& first,const T& second){
        return compareBy(orderBy(first),orderBy(second));
    };
}

auto
byAge(const person_t& p){
    return p.age();
}

auto
bySurname(const person_t& p){
    return p.surname();
}

auto
byName(const person_t& p){
    return p.name();
}

int main() {
    vector<double> degrees{0., 30., 45., 53., 112., 180.};
    vector<double> radians(degrees.size());
    // hof: 4th parameter -> function -> global function
    transform(degrees.cbegin(),degrees.cend(),radians.begin(),deg2rad);
    // print_rad: double -> void
    for_each(radians.begin(),radians.end(),print_radiant);

    vector<person_t> people {
            {"jack", "shephard", person_t::male, 46},
            {"kate", "austen", person_t::female, 42},
            {"ben", "linus", person_t::male, 54},
            {"juliet", "burke", person_t::female, 41},
            {"john", "locke", person_t::male, 58},
            {"shannon", "rutherford", person_t::female, 36}
    };

    sort(people.begin(),people.end(), getOrder<person_t>(byAge,greater<int>()));
    for_each(people.begin(),people.end(),print_person);
    sort(people.begin(),people.end(), getOrder<person_t>(byAge,less<int>()));
    for_each(people.begin(),people.end(),print_person);
    sort(people.begin(),people.end(), getOrder<person_t>(byName,greater<string>()));
    for_each(people.begin(),people.end(),print_person);
    sort(people.begin(),people.end(), getOrder<person_t>(bySurname,less<string>()));
    for_each(people.begin(),people.end(),print_person);
    return 0;
}
