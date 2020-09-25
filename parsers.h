//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_PARSERS_H
#define SIMPLEX_PARSERS_H

#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::istream;
using std::istringstream;
using std::runtime_error;
using std::set;
using std::string;
using std::vector;

vector<int> parse_func(const string& str);
vector<int> parse_condition(const string& str, size_t size);

struct CanonicalTask{
    string function;
    int conditions_number;
    vector<string> conditions;
};
/*
CanonicalTask read_task(istream& is){
    CanonicalTask task;

    is >> task.function;
}*/

#endif //SIMPLEX_PARSERS_H
