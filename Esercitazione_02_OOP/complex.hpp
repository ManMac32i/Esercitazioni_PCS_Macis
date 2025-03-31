# pragma once
using namespace std;

template<typename I> requires std::integral<I>
class complex_number {
    I real, img;
public:
    complex_number() // default operator
        : real(0), img(0)
    {}
    
    explicit complex_number(I r) // if
        : real(r), img(0)
    {
        cout << "real number initialized as complex_number" << endl;
    }

    complex_number(I r, I i)
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
        
        return complex_number(real, -img)
    }

    I real()
    {
        return real;
    }

    I imaginary()
    {
        return img;
    }

    complex_number operator<<(const complex_number& other)
    {
        return cout << other.real << other.img << "i" << endl;
    }

    complex_number& operator+=(const complex_number& other)
    {
        I a = real;
        I b = img;
        I c = other.real;
        I d = other.img;
        real = a + c;
        img = b + d;
        return *this
    }

    complex_number operator+(const complex_number& other) const
    {
        complex_number comp = *this;
        comp += other;
        return comp
    }

    complex_number& operator+=(const I& other)
    {
        real += other;
        return *this
    }

    complex_number operator+(const I& other) const
    {
        complex_number comp = *this;
        comp += other;
        return comp
    }

    complex_number operator*=(const complex_number& other)
    {
        I a = real;
        I b = img;
        I c = other.real;
        I d = other.img;
        real = a * c - b * d;
        img = a * d + b * c;
        return *this 
    }

    complex_number operator*(const complex_number& other) const
    {
        complex_number comp = *this;
        comp *= other;
        return comp
    }


};