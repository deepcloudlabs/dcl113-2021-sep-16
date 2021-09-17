#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
#include "person.h"

int main() {
    vector <person_t> employees{
            {"jack",    "shephard",   person_t::male,   46},
            {"kate",    "austen",     person_t::female, 42},
            {"ben",     "linus",      person_t::male,   54},
            {"juliet",  "burke",      person_t::female, 41},
            {"john",    "locke",      person_t::male,   58},
            {"shannon", "rutherford", person_t::female, 36}
    };

    
    return 0;
}