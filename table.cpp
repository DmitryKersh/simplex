//
// Created by dimchik on 22.09.2020.
//

#include "table.h"

Table::Table(size_t r, size_t c) : rows(r), columns(c), data(r){
    for (auto & item : data){
        item = vector<Rational>(c);
    }
}