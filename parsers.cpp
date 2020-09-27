//
// Created by dimchik on 22.09.2020.
//

#include "parsers.h"

void invert_if(vector<int>& v, bool condition){
    if (condition){
        for (int& n : v){
            n = -n;
        }
    }
}

void parse_expression(vector<int>& coeffs, istringstream& stream, set<char> stop_chars){
    bool minus = false;
    bool no_coeff = true; // flag to push coefficient "1" if no coefficient: x1 + 3x2 -> {1, 3}
    int coeff = 0;
    int index = 0;
    while (!stop_chars.count(stream.peek())){
        // if a number then it must be coefficient, because variable number is parsed with its variable
        if (isdigit(stream.peek())){
            stream >> coeff;
            no_coeff = false;
        } else if (stream.peek() == '-'){ // if '-' then adjust flag
            minus = true;
            stream.ignore();
            if (!isdigit(stream.peek())){ // avoid ignoring first numbers<0
                stream.ignore(10, ' ');
            }
            no_coeff = true;
        } else if (stream.peek() == '+'){ // if '+' then adjust flag
            minus = false;
            stream.ignore(10, ' ');
            no_coeff = true;
        } else if (stream.peek() == ' '){
            stream.ignore();
        } else{    // else => it's variable name
            while (!isdigit(stream.peek())){ //ignoring name, but not number of variable
                stream.ignore();
            }
            stream >> index;
            if (coeffs.size() < index){
                coeffs.resize(index);
            }
            try {
                if (no_coeff) {
                    coeffs.at(index - 1) += (minus ? -1 : 1);
                } else {
                    coeffs.at(index - 1) += (minus ? -coeff : coeff);
                }
            }
            catch (std::exception& e) {
                cout << e.what() << endl;
            }

            no_coeff = true;
        }
    }
}

/// format:
/// 3x1 - 42x2 - x3 => max
vector<int> parse_func(const string& str){
    vector<int> coeffs;

    istringstream stream(str);

    parse_expression(coeffs, stream, {'='});

    while (stream.peek() != 'm'){ // starting of 'max' or 'min'
        stream.ignore();
    }
    string goal;
    stream >> goal;

    // YT VIDEO SAID WE INVERT IF -> MAX
    invert_if(coeffs, goal == "max");

    if (goal != "max" && goal != "min") {
        throw runtime_error("Function should achieve max or min, but entered: " + stream.str());
    }
    coeffs.insert(coeffs.begin(), 0);
    return coeffs;
}

vector<int> parse_condition(const string& str){
    vector<int> coeffs;

    istringstream stream(str);

    parse_expression(coeffs, stream, {'>', '<'});

    bool sign = (stream.peek() == '>'); // checks if >= or <= sign

    while (!isdigit(stream.peek())){
        stream.ignore(); // ignoring all up to b_i
    }

    int b_i = 0;
    stream >> b_i;
    coeffs.insert(coeffs.begin(), b_i);

    invert_if(coeffs, sign);

    return coeffs;
}

CanonicalTask read_task(istream& is){
    CanonicalTask task;

    cout << FUNC_HINT << endl;
    cout << WARNING << endl;
    getline(is, task.function);

    cout << COND_NUMBER << endl;
    is >> task.conditions_number; is.ignore();

    task.conditions = vector<string>(task.conditions_number);
    cout << COND_HINT << endl;

    for (size_t i = 0; i < task.conditions_number; i++){
        cout << "Enter condition #" << i + 1 << endl;
        getline(is, task.conditions[i]);
    }

    return task;
}

void Print(const vector<int>& v){
    cout << "[ ";
    size_t size = v.size();
    for (size_t i = 0; i < size; i++) {
        cout << v[i] << ((i == size - 1) ? " " : ", ");
    }
    cout << "]" << endl;
}

vector<Rational> to_rational(const vector<int>& v){
    vector<Rational> res(v.size());

    for (size_t i = 0; i < v.size(); i++){
        res[i] = Rational(v[i], 1);
    }

    return res;
}
