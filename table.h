//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_TABLE_H
#define SIMPLEX_TABLE_H

#include <cstddef>
#include <iomanip>
#include "Rational.h"
#include "parsers.h"

using std::setw;
// columns =

// rows = conditions + 1 (for F)

class Table {
public:
    Table(CanonicalTask& task);

    size_t resolving_col_index() const;
    size_t resolving_row_index() const;
    bool is_not_optimal() const;

    void recount();
    void evaluate_simplex_relations();
    void add_rows(size_t to_what, size_t what, Rational coefficient);
    void divide_row(size_t what, Rational coefficient);

    void print_table(ostream& os);

    // solving func
    Rational solve_simplex();
private:
    size_t rows;
    size_t columns;

    vector<vector<Rational>> data;
};


#endif //SIMPLEX_TABLE_H
