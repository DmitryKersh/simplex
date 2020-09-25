//
// Created by dimchik on 25.09.2020.
//

#include "Rational.h"

int gcd(int a, int b){
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

Rational::Rational() {  // дробь по умолчанию — 0/1
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int new_numerator, int new_denominator) {
    const int divisor = gcd(new_numerator, new_denominator);
    // сократим дробь, разделив числитель и знаменатель на их НОД
    numerator = new_numerator / divisor;
    denominator = new_denominator / divisor;
    // знаменатель должен быть положительным
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
    return os << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}