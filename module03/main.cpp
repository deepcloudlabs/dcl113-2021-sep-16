#include <iostream>
#include <vector>

using namespace std;

struct Deg2Rad{
    auto operator()(double deg){
        return (3.14 * deg) / 180;
    }
};

struct PrintRad{ // state
    auto operator()(double rad){
        cout << rad << " ";
    }
};

int main() {
    vector<double> degrees{0., 30., 45., 53., 112., 180.};
    vector<double> radians(degrees.size());
    // hof: 4th parameter -> function -> global function
    /*
    transform(degrees.cbegin(),degrees.cend(),radians.begin(),[](auto deg){
        return (3.14 * deg) / 180;
    });
    for_each(radians.begin(),radians.end(),[](auto rad){cout << rad << " ";});
     */
    transform(degrees.cbegin(),degrees.cend(),radians.begin(),Deg2Rad());
    for_each(radians.begin(),radians.end(),PrintRad());
    return 0;
}
