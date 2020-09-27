//
// Created by dimchik on 22.09.2020.
//

#include "table.h"

#define FOR_BASIS_ROWS for (size_t ROW = 0; ROW < rows - 1; ROW++)
#define FUNCTION_ROW data[rows - 1]
#define LAST_IN_ROW columns - 1


Table::Table(CanonicalTask& task) : rows(task.conditions_number + 1) {
    // initialising rows: conditions
    for (size_t i = 0; i < LAST_IN_ROW; i++){
        data[i] = to_rational(parse_condition(task.conditions[i]));
    }

    // initialising rows: function
    FUNCTION_ROW = to_rational(parse_func(task.function));

    // finding the longest row
    size_t longest_row_size = 0;
    for (const auto& row : data){
        if (row.size() > longest_row_size){
            longest_row_size = row.size();
        }
    }

    // init 'columns' field
    // columns: for variables + for additional variables (1 for each condition) + 1 for simplex relations
    columns = longest_row_size + task.conditions_number + 1;

    // matching all rows' lengths
    for (auto& row : data){
        row.resize(columns);
    }
}

size_t Table::resolving_col_index() const {
    Rational max;
    size_t index;
    for (size_t i = 1; i < LAST_IN_ROW; i++){
        if (FUNCTION_ROW[i] > max){
            max = FUNCTION_ROW[i];
            index = i;
        }
    }
    return index;
}

void Table::evaluate_simplex_relations(){
    size_t rci = resolving_col_index();
    FOR_BASIS_ROWS {
        if (data[ROW][rci] > 0){
            data[ROW][LAST_IN_ROW] = data[ROW][0] / data[ROW][rci];
        }
    }
}

size_t Table::resolving_row_index() const {
    Rational min;
    size_t index;

    FOR_BASIS_ROWS {
        if (data[ROW][LAST_IN_ROW].Numerator() != 0){
            if (data[ROW][LAST_IN_ROW] < min){
                min = data[ROW][LAST_IN_ROW];
                index = ROW;
            }
        }
    }
    return index;
}

bool Table::is_not_optimal() const {
    for (Rational r : FUNCTION_ROW){
        if (r < 0) return true;
    }
    return false;
}

// not touching simplex relations
void Table::divide_row(size_t what, Rational coefficient) {
    for (size_t i = 0; i < LAST_IN_ROW; i++) {
        data[what][i] = data[what][i] / coefficient;
    }
}

// not touching simplex relations
void Table::add_rows(size_t to_what, size_t what, Rational coefficient) {
    for (size_t i = 0; i < LAST_IN_ROW; i++){
        data[to_what][i] = data[to_what][i] + coefficient * data[what][i];
    }
}

void Table::recount() {
    size_t res_col = resolving_col_index();
    evaluate_simplex_relations();
    size_t res_row = resolving_row_index();

    // getting value of resolving element
    Rational res_el = data[res_row][res_col];

    // dividing resolving row by it
    divide_row(res_row, res_el);

    for (size_t current_row = 0; current_row < rows && current_row != res_row; current_row++){
        add_rows(current_row, res_row, -data[current_row][res_col]);
    }
}

Rational Table::solve_simplex() {
    size_t step = 0;
    while (is_not_optimal()){
        cout << "STEP " << step << endl;
        recount();
        print_table(cout);
    }
    cout << "Function = " << FUNCTION_ROW[0] << endl;
    for (size_t i = 0; i < rows - 1; i++){
        cout << "x" << i + 1 << "= " << data[0][i] << "; ";
    }
    cout << endl;
}

void Table::print_table(ostream &os) {
    for (auto row : data){
        for (Rational number : row){
            os << setw(7) << number;
        }
        os << endl;
    }
    os << endl;
}
