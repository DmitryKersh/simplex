// Copyright 2020 Dmitry Karpukhin <d.karpukhin@mail.ru>

#ifndef SIMPLEX_RATIONAL_H
#define SIMPLEX_RATIONAL_H

#include <iostream>
#include <sstream>

using std::istream;
using std::ostream;

int gcd(int a, int b);

class Rational {
public:
    Rational();
    Rational(int new_numerator, int new_denominator);

    [[nodiscard]] int Numerator() const;
    [[nodiscard]] int Denominator() const;

private:
    int numerator;
    int denominator;
};


bool operator == (const Rational& lhs, const Rational& rhs);

Rational operator + (const Rational& lhs, const Rational& rhs);

Rational operator - (const Rational& lhs, const Rational& rhs);

Rational operator * (const Rational& lhs, const Rational& rhs);

Rational operator / (const Rational& lhs, const Rational& rhs);

istream& operator >> (istream& is, Rational& r);

ostream& operator << (ostream& os, const Rational& r);

bool operator < (const Rational& lhs, const Rational& rhs);

bool operator > (const Rational& lhs, const Rational& rhs);

bool operator < (const Rational& lhs, const int& rhs);

bool operator > (const Rational& lhs, const int& rhs);

Rational operator - (const Rational& operand);

Rational abs (const Rational& operand);

bool operator <= (const Rational& lhs, const Rational& rhs);

bool operator >=(const Rational& lhs, const Rational& rhs);

#endif //SIMPLEX_RATIONAL_H
