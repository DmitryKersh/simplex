// Copyright 2020 Dmitry Karpukhin <d.karpukhin@mail.ru>

#include "Rational.h"

int gcd(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int new_numerator, int new_denominator) {
    const int divisor = gcd(new_numerator, new_denominator);

    numerator = new_numerator / divisor;
    denominator = new_denominator / divisor;

    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
}

int Rational::Denominator() const { return denominator; }

int Rational::Numerator() const { return numerator; }

bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
    int n, d;
    char c;

    if (is) {
        is >> n >> c >> d;
        if (is && c == '/') {
            r = Rational(n, d);
        }
    }

    return is;
}

ostream& operator << (ostream& os, const Rational& r) {
    if (r.Denominator() == 1){
        return os << r.Numerator();
    }
    std::ostringstream osstr;
    osstr << r.Numerator() << '/' << r.Denominator();
    return os << osstr.str();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

bool operator > (const Rational& lhs, const Rational& rhs) {
    return rhs < lhs;
}

bool operator < (const Rational& lhs, const int& rhs){
    return lhs < Rational(rhs, 1);
}

bool operator > (const Rational& lhs, const int& rhs){
    return Rational(rhs, 1) < lhs;
}

Rational operator- (const Rational& operand){
    return Rational(-operand.Numerator(), operand.Denominator());
}

Rational abs (const Rational& operand){
    return operand.Numerator() < 0 ? -operand : operand;
}

bool operator <=(const Rational& lhs, const Rational& rhs){
    return lhs < rhs || lhs == rhs;
}

bool operator >=(const Rational& lhs, const Rational& rhs){
    return lhs > rhs || lhs == rhs;
}