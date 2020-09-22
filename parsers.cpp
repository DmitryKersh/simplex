//
// Created by dimchik on 22.09.2020.
//

#include "parsers.h"


/// format:
/// 3x1 - 42x2 - x3 => max
vector<int> parse_func(const string& str){
    vector<int> coeffs;

    istringstream stream(str);

    bool minus = false;
    bool no_coeff = true; // flag to push coefficient "1" if no coefficient: x1 + 3x2 -> {1, 3}
    while (stream.peek() != '='){
        int coeff = 0;


        // if a number then it must be coefficient, because variable number is parsed with its variable
        if (isdigit(stream.peek())){
            //cout << "Peek: " << stream.peek();
            stream >> coeff;
            coeffs.push_back(minus ? -coeff : coeff);
            minus = false;
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
        } else {    // else => it's variable name
            if (no_coeff) {
                coeffs.push_back(minus ? -1 : 1);
            }
            stream.ignore(10,' ');
            no_coeff = true;
        }
    }
    while (stream.peek() != 'm'){ // starting of 'max' or 'min'
        stream.ignore();
    }
    string goal;
    stream >> goal;

    if (goal == "max"){
        //..do nothing
    } else if (goal == "min"){
        for (int& n : coeffs){
            n *= -1;
        }
        cout << "Inverted function" << endl;
    } else {
        throw runtime_error("Function should achieve max or min, but entered: " + stream.str());
    }

    return coeffs;
}

vector<int> parse_condition(const string& str, size_t size){
    vector<int> coeffs(size);

    istringstream stream(str);

    bool minus = false;
    bool no_coeff = true; // flag to push coefficient "1" if no coefficient: x1 + 3x2 -> {1, 3}
    int coeff = 0;
    int index = 0;
    while (stream.peek() != '<' && stream.peek() != '>'){
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
    bool sign = (stream.peek() == '>'); // checks if >= or <= sign

    while (!isdigit(stream.peek())){
        stream.ignore(); // ignoring all up to b_i
    }

    int b_i = 0;
    stream >> b_i;
    coeffs.push_back(b_i);

    if (sign){ // if >= then multiply all coeffs and b_i by -1 to get canonical form
        for (int& n : coeffs){
            n *= -1;
        }
        cout << "Inverted condition" << endl;
    }

    return coeffs;
}