#include "Complex.h"
#include "Complex.h"

bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex operator+(const Complex& l, const Complex& r)
{
    return { l.GetRealData() + r.GetRealData(), l.GetImagData() + r.GetImagData() };
}

Complex operator+(const Complex& l, double r)
{
    return { l.GetRealData() + (int) r, l.GetImagData() + (r - floor(r))};
}

Complex operator+(double l, const Complex& r)
{
    return { (int) l + r.GetRealData(), (l-floor(l)) + r.GetImagData()};
}

Complex operator-(const Complex& l, const Complex& r)
{
    return { l.GetRealData() - r.GetRealData(), l.GetImagData() - r.GetImagData() };
}

Complex operator-(const Complex& obj)
{
    return { -obj.GetRealData(), obj.GetImagData() };
}

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const
{
    return real_data;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

double Complex::GetRealData() const
{
    return this->real_data;
}

double Complex::GetImagData() const
{
    return this->imag_data;
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}
