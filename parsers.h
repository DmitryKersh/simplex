//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_PARSERS_H
#define SIMPLEX_PARSERS_H




#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include "Rational.h"

using std::endl;
using std::cout;
using std::cin;
using std::istream;
using std::istringstream;
using std::runtime_error;
using std::set;
using std::string;
using std::vector;

void parse_expression(vector<int>& coeffs, istringstream& stream, set<char> stop_chars);
void invert_if(vector<int>& v, bool condition);

vector<int> parse_func(const string& str);
vector<int> parse_condition(const string& str);

struct CanonicalTask{
    string function;
    int var_number;
    int conditions_number;
    vector<string> conditions;
};

CanonicalTask read_task(istream& is);

void Print(const vector<int>& v);

vector<Rational> to_rational(const vector<int>& v);



#endif //SIMPLEX_PARSERS_H
