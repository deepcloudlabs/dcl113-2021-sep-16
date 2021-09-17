#include "city.h"
#include "country.h"
#include "world-util.h"

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <numeric>

using namespace std;
using namespace world;

// TODO: Find the capital with highest population in the world

map<int,shared_ptr<city>> cities;
map<string,shared_ptr<country>> countries;

int main(int argc, char* argv[]){
    create_world();

    auto highPopulatedCapitalReducer=  [](shared_ptr<city>& highPopulatedCapital, const pair<const string,shared_ptr<country>>& entry)  {
        auto capital= entry.second->capital;
        if(capital==nullptr) return highPopulatedCapital;
        auto population= capital->population;
        if (highPopulatedCapital==nullptr){
            return capital;
        } else  if (highPopulatedCapital->population<population) {
            return capital;
        }
        return highPopulatedCapital;
    };

    auto highPopulatedCapital = accumulate(countries.cbegin(),countries.cend(),shared_ptr<city>(nullptr),highPopulatedCapitalReducer);

    cout << *highPopulatedCapital << endl;

    return 0;
}