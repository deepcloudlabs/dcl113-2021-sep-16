#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include "person.h"

using namespace std;

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

auto
is_older(const person_t &p,int age){
    return p.age() > age;
}

void
print_person(ostream &out, person_t &p, person_t::output_format format){
    if (format == person_t::name_only){
        out << p.name() << endl;
    } else {
        out << p.surname() << ", " << p.name() << endl;
    }
}

auto order_by_age_desc(person_t &first,person_t &second){
    return first.age() > second.age();
}

void print_full_person(person_t &p){
    cout << p.surname() << ", " << p.name() << ", " << p.age() << endl ;
}

int main(){
    vector<person_t> employees {
            {"jack", "shephard", person_t::male, 46},
            {"kate", "austen", person_t::female, 42},
            {"ben", "linus", person_t::male, 54},
            {"juliet", "burke", person_t::female, 41},
            {"john", "locke", person_t::male, 58},
            {"shannon", "rutherford", person_t::female, 36}
    };
    // employees whose age are greater than 50
    vector<person_t> experienced_employees;
    vector<person_t> inexperienced_employees;
    auto is_experienced = bind(is_older,placeholders::_1, 50);
    auto is_inexperienced = [&is_experienced](person_t &p){return !is_experienced(p);};
    copy_if(employees.begin(),employees.end(), back_inserter(experienced_employees), is_experienced);
    copy_if(employees.begin(),employees.end(), back_inserter(inexperienced_employees), is_inexperienced);
    auto print_person_with_fullname_to_console = bind(print_person,ref(cout),placeholders::_1 ,person_t::full_name);
    auto print_person_with_name_to_console = bind(print_person,ref(cout),placeholders::_1 ,person_t::name_only);
    for_each(experienced_employees.begin(),experienced_employees.end(), print_person_with_fullname_to_console);
    cout << "\n\n" ;
    for_each(inexperienced_employees.begin(),inexperienced_employees.end(), print_person_with_name_to_console);

    // functional programming
    // partial function: 1) std::bind 2) lambda expression -> pure function
    auto orderByAgeDesc = getOrder<person_t>(byAge, greater<int>());
    auto orderByAgeAsc = bind(orderByAgeDesc,placeholders::_2, placeholders::_1);

    cout << "orderByAgeDesc:" << endl;
    sort(employees.begin(), employees.end(), orderByAgeDesc);
    for_each(employees.begin(),employees.end(),print_full_person);
    cout << "orderByAgeAsc:" << endl;
    sort(employees.begin(),employees.end(), orderByAgeAsc);
    for_each(employees.begin(),employees.end(),print_full_person);
    /*
    sort(employees.begin(),employees.end(), getOrder<person_t>(byName,greater<string>()));
    for_each(employees.begin(),employees.end(),print_full_person);
    sort(employees.begin(),employees.end(), getOrder<person_t>(bySurname,less<string>()));
    for_each(employees.begin(),employees.end(),print_full_person);
    */
    return 0;
}