#include "city.h"
#include "country.h"
#include "world-util.h"

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <parallel/algorithm>
#include <numeric>

using namespace std;
using namespace world;

map<int, shared_ptr<world::city>> cities;
map<std::string, shared_ptr<world::country>> countries;

int main(int argc, char *argv[]) {
    create_world();

    // reduce (distinct)
    auto my_reducer =
            [] // capturing
                    (map<string,int> &country_nums,pair<const string,shared_ptr<country>> &entry)
            {
                auto country = entry.second;
                auto continent = country->continent;
                if (country_nums.find(continent)!=country_nums.end()){
                    country_nums[continent]++;
                } else {
                    country_nums[continent]=1;
                }
                return country_nums;
            };
    auto country_numbers_by_continent = accumulate(countries.begin(), countries.end(), map<string,int>() ,my_reducer );
    for_each(country_numbers_by_continent.cbegin(),country_numbers_by_continent.cend(), [](const auto &entry){
        cout << entry.first << ": " << entry.second << endl;
    });
    return 0;
}