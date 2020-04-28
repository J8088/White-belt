#include<iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <sstream>
#include<string>
#include<algorithm>

using namespace std;

void Pozitive(int& a)
{
    if (a < 0)
        a = -a;
}

int NOD(int a, int b) {

    while (a != b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}

int NOK(const int& a, const int& b)
{
    return a * b / NOD(a, b);
}

void Cut(int& a, int& b)
{
    //положительное (0) или отрицательное (1)
    bool sign = (((a < 0) && (b > 0)) || ((a > 0) && (b < 0)));
    //делаю 2 положительных числа
    Pozitive(a);
    Pozitive(b);
    int d = NOD(a, b);
    a /= d;
    b /= d;
    //возвращаю знак
    if (sign) a *= -1;
}



class Rational {
public:
    Rational()
    {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
            throw  invalid_argument("");
        //если 0
        if (numerator == 0)
        {
            denom = 1;
            num = 0;
            return;
        }
        Cut(numerator, denominator);
        num = numerator;
        denom = denominator;
    }
    int Numerator() const
    {
        return num;
    }
    int Denominator() const
    {
        return denom;
    }
private:
    int num;
    int denom;
};


Rational operator+(const Rational& l, const Rational& r) {
    int denom_new = NOK(l.Denominator(), r.Denominator());
    int num_new = (denom_new / l.Denominator()) * l.Numerator() + (denom_new / r.Denominator()) * r.Numerator();
    return  Rational(num_new, denom_new);
}

Rational operator-(const Rational& l, const Rational& r) {
    int denom_new = NOK(l.Denominator(), r.Denominator());
    int num_new = (denom_new / l.Denominator()) * l.Numerator() - (denom_new / r.Denominator()) * r.Numerator();
    return  Rational(num_new, denom_new);
}

bool operator==(const Rational& l, const Rational& r) {
    return ((l.Numerator() == r.Numerator()) && (l.Denominator() == r.Denominator()));
}

Rational operator*(const Rational& l, const Rational& r) {
    return  Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/(const Rational& l, const Rational& r) {
    if (r.Numerator() == 0)
        throw domain_error("");
    Rational temp(r.Denominator(), r.Numerator());
    return  l * temp;
}

ostream& operator<<(ostream& stream, const Rational& rational){
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
    if(stream.good()) {
        int a, b;
        stream >> a;
        stream.ignore(1);
        stream >> b;
        rational = Rational(a, b);
    }
    else stream.setstate(ios::failbit);
    return stream;
}


bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}



int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}