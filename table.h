//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_TABLE_H
#define SIMPLEX_TABLE_H

#include <cstddef>
#include "Rational.h"
#include "parsers.h"

// columns =

// rows = conditions + 1 (for F)

class Table {
public:
    Table(CanonicalTask& task);

    size_t resolving_col_index();
    size_t resolving_row_index();
    void evaluate_simplex_relations();
private:
    size_t rows;
    size_t columns;

    vector<vector<Rational>> data;
};


#endif //SIMPLEX_TABLE_H
