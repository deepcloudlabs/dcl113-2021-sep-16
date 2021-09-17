#include "city.h"
#include "country.h" 
#include "world-util.h" 

#include <set>
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
	create_world(); // populates cities and countries

    // reduce (distinct)
    auto continent_reducer =
            [] // capturing
            (set<string> &conts,pair<const string,shared_ptr<country>> &entry)
            {
                auto country = entry.second;
                auto continent = country->continent;
                conts.insert(continent);
                return conts;
            };
    auto continents = accumulate(countries.begin(), countries.end(), set<string>() ,continent_reducer );
    auto print_continent = [](const string& continent){
        cout << continent << " " ;
    };
    for_each(continents.cbegin(),continents.cend(),print_continent);
	return 0;
}