//
// Created by dimchik on 22.09.2020.
//

#ifndef SIMPLEX_TABLE_H
#define SIMPLEX_TABLE_H

#include <cstddef>
#include "Rational.h"
#include "parsers.h"


class Table {
public:
    Table(size_t r, size_t c);

private:
    size_t rows;
    size_t columns;

    vector<vector<Rational>> data;
};


#endif //SIMPLEX_TABLE_H
