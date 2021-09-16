#include <iostream>
#include <vector>
#include <fstream>
#include <execution>
#include <parallel/algorithm>

// recursive -> tail-recursion ->
// stack -> ulimit -a
/*
. . .
stack size              (kbytes, -s) 8192
. . .
*/
// ranges (c++20)
#include <ranges>

using namespace std;
namespace rng = std::ranges;

template <rng::range R>
constexpr auto to_vector(R &&r){
    using elem_t = std::decay_t<rng::range_value_t<R>>;
    return std::vector<elem_t>{r.begin(), r.end()};
}

ifstream
open_file(const string &file){
    return ifstream (file);
}

int
count_lines_in_file(ifstream in_file){
    return count(istreambuf_iterator<char>(in_file),istreambuf_iterator<char>(), '\n');
}

vector<int>
count_lines_declarative_ranges(const vector<string> &files) {
   return to_vector(files | std::ranges::views::transform(open_file) | std::ranges::views::transform(count_lines_in_file));
}

int
count_lines(const string &file){
    ifstream in_file(file);
    // function programming : internal loop (no recursion!)
    return count(istreambuf_iterator<char>(in_file),istreambuf_iterator<char>(), '\n'); // (1)
}

// declarative programming - functional programming + oop
vector<int>
count_lines_declarative(const vector<string> &files) {
    vector<int> line_counts(files.size());
    // solution -> internal loop -> [ STL (Container, Algorithm, Iterator) + Template ] -> Generic Programming
    transform(execution::par,files.begin(),files.end(),line_counts.begin(),count_lines);
    return line_counts;
}

// imperative programming - procedural programming + oop
vector<int>
count_lines_imperative(const vector<string> &files){
    vector<int> line_counts;
    // solution -> external loops -> STL Container: vector, set, array, map, ...
    for (const auto &file : files)
    { // (1)
        ifstream in_file(file);
        char c;
        auto line_count = 0;
        while (in_file.get(c)){
            if (c=='\n')
                line_count++;
        } // EOF
        line_counts.push_back(line_count);
    }
    return line_counts;
}

int main() {
    vector<string> my_files;
    my_files.push_back(string("c:\\tmp\\jvm-flags.txt"));
    my_files.push_back(string("c:\\tmp\\oracle_tuning.txt"));
    my_files.push_back(string("c:\\tmp\\notes-hives.txt"));
    for (auto &line_count : count_lines_imperative(my_files)){
        cout << line_count << endl;
    }
    for (auto &line_count : count_lines_declarative(my_files)){
        cout << line_count << endl;
    }
    for (auto &line_count : count_lines_declarative_ranges(my_files)){
        cout << line_count << endl;
    }
    return 0;
}
