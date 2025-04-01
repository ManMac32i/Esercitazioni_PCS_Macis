# pragma once
using namespace std;

template<typename T> requires std::floating_point<T>
class complex_number {
    T real, img;
public:
    complex_number() // default operator
        : real(0), img(0)
    {}
    
    explicit complex_number(T r) // if just an itenger is passed
        : real(r), img(0)
    {
        cout << "real number initialized as complex_number" << endl;
    }

    complex_number(T r, T i)
        : real(r), img(i)
    {}

    complex_number comp_conj()
    {
        if (img > 0) 
        {
            cout << "Your complex_number conjucate is" << real << "-" << img << "i" << endl;
        }
        else 
        {
            cout << "Your complex_number conjucate is" << real << "+" << img << "i" << endl;
        }
        
        return complex_number(real, -img);
    }

    T real_part() const
    {
        return real;
    }

    T imaginary() const
    {
        return img;
    }

    friend ostream& operator<<(ostream& os, const complex_number& other)
    {
        os << other.real_part();
        if (other.imaginary() >= 0) {
            os << " + " << other.imaginary() << "i";
        } else {
            os << " - " << -other.imaginary() << "i";
        }
        return os;;
    }

    complex_number& operator+=(const complex_number& other)
    {
        T a = real;
        T b = img;
        T c = other.real;
        T d = other.img;
        real = a + c;
        img = b + d;
        return *this;
    }

    complex_number operator+(const complex_number& other) const
    {
        complex_number comp = *this;
        comp += other;
        return comp;
    }

    complex_number& operator+=(const T& other)
    {
        real += other;
        return *this;
    }

    complex_number operator+(const T& other) const
    {
        complex_number comp = *this;
        comp += other;
        return comp;
    }

    complex_number operator*=(const complex_number& other)
    {
        T a = real;
        T b = img;
        T c = other.real;
        T d = other.img;
        real = a * c - b * d;
        img = a * d + b * c;
        return *this; 
    }

    complex_number operator*(const complex_number& other) const
    {
        complex_number comp = *this;
        comp *= other;
        return comp;
    }

    complex_number operator*=(const T& other) 
    {
        real *= other;
        img *= other;
        return *this;
    }

    complex_number operator*(const T& other) const
    {
        complex_number comp = *this;
        comp *= other;
        return comp;
    }


};

template <typename T>
complex_number<T>
operator+(const T& other, const complex_number<T>& comp)
{
    return comp + other; 
}

template <typename T>
complex_number<T>
operator*(const T& other, const complex_number<T>& comp)
{
    return comp * other; 
}