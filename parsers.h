//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_PARSERS_H
#define SIMPLEX_PARSERS_H

#define WARNING "WARNING! Variable index matters, while name doesn't. Example: x1 = y1 = abcdef1, but x1 != x2 != y3"
#define FUNC_HINT "Enter function: Format: \"x1 - x2 + 4x3 => max\""
#define COND_NUMBER "Enter number of conditions"
#define COND_HINT "Start entering conditions: Format: \"3x1 - 4x2 - x3 => max\""


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
vector<int> parse_condition(const string& str);

struct CanonicalTask{
    string function;
    int conditions_number;
    vector<string> conditions;
};

CanonicalTask read_task(istream& is);
void Print(const vector<int>& v);

#endif //SIMPLEX_PARSERS_H
