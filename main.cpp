#include "parsers.h"


void Print(const vector<int>& v){
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    /*
    int variable_cnt, condition_cnt;
    string function;

    cout << "Enter number of variables" << endl;
    cin >> variable_cnt;

    cout << "Enter amount of conditions" << endl;
    cin >> condition_cnt;

    cout << "Enter function, for example: x1 - x2 + 4x3";
    getline(cin, function);

    vector<int> func_vector = parse_func(function);
*/
    Print(parse_func("-21x1 - x2 + x3 => max"));
    Print(parse_condition("-5x2 + x1 + 3x3 - x3 - x2 > 34", 3));
    return 0;
}
