//
// Created by dimchik on 22.09.2020.
//

#include "table.h"

#define FOR_BASIS_ROWS for (size_t ROW = 0; ROW < rows - 1; ROW++)



Table::Table(CanonicalTask& task) : rows(task.conditions_number + 1) {
    // initialising rows: conditions
    for (size_t i = 0; i < rows - 1; i++){
        data[i] = to_rational(parse_condition(task.conditions[i]));
    }

    // initialising rows: function
    data[rows - 1] = to_rational(parse_func(task.function));

    // finding the longest row
    size_t longest_row_size = 0;
    for (const auto& row : data){
        if (row.size() > longest_row_size){
            longest_row_size = row.size();
        }
    }

    // init 'columns' field
    columns = longest_row_size + 1;

    // matching all rows' lengths
    for (auto& row : data){
        // + 1 for column of simplex relations
        row.resize(columns);
    }
}

size_t Table::resolving_col_index() {
    Rational max;
    size_t index;
    for (size_t i = 1; i < columns - 1; i++){
        if (data[rows - 1][i] > max){
            max = data[rows - 1][i];
            index = i;
        }
    }
    return index;
}

void Table::evaluate_simplex_relations(){
    size_t rci = resolving_col_index();
    FOR_BASIS_ROWS {
        if (data[ROW][rci] > 0){
            data[ROW][columns - 1] = data[ROW][0] / data[ROW][rci];
        }
    }
}

size_t Table::resolving_row_index() {
    Rational min;
    size_t index;

    FOR_BASIS_ROWS {
        if (data[ROW][columns - 1].Numerator() != 0){
            if (data[ROW][columns - 1] < min){
                min = data[ROW][columns - 1];
                index = ROW;
            }
        }
    }
    return index;
}