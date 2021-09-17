#include "city.h"
#include "world-util.h"

#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace world;

map<int,shared_ptr<city>> cities;
map<string,shared_ptr<country>> countries;

int main(int argc, char* argv[]){
    create_world();
    auto my_reducer =
            [] // capturing
             (shared_ptr<country> &current_richest,pair<const string,shared_ptr<country>> &entry)
            {
                auto &country = entry.second;
                return current_richest->gnp < country->gnp ? country : current_richest;
            };
    auto &initial = countries.begin()->second;
    auto richest_country = accumulate(countries.begin(), countries.end(),
                                      initial, my_reducer );
    cout << richest_country->name << ", "
         << richest_country->continent << ", "
         << richest_country->population << ", "
         << richest_country->gnp << endl;

    return 0;
}