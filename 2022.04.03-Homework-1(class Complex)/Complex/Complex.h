#pragma once
#include <iostream>

class Complex
{
private:

    double re;
    double im;

public:

    Complex(double re = 0, double im = 0);
    Complex(const Complex& complex);
    ~Complex();

    double getRe();
    void setRe(double re);
    double getIm();
    void setIm(double im);

    void set(double re, double im);

    void operator=(const Complex& complex);

    double abs();

    double arg();

    Complex reverse();

    void sqrt(int n, std::ostream& stream);

    friend Complex operator*(Complex complex1, Complex complex2);
    friend Complex operator*(double d, Complex complex);
    friend Complex operator*(Complex complex, double d);

    friend Complex operator+(Complex complex1, Complex complex2);

    friend Complex operator/(Complex complex1, Complex complex2);

    friend Complex operator-(Complex complex1, Complex complex2);

    friend std::ostream& operator<<(std::ostream& stream, const Complex& complex);
};