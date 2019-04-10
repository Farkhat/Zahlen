#include <iostream>
#include <math.h>

class mycomplex {
    double re, im;

public:
    //Konstruktoren
    mycomplex(double r, double i): re{r}, im{i}{}
    mycomplex(double r) :re{r}, im{0}{}
    mycomplex(): re{0}, im{0}{}

    //Getter und Setter
    double real() const {
        return re;
    }
    void real(double d) {
        re = d;
    }
    double imag() const {
        return im;
    }
    void imag(double d) {
        im = d;
    }

    //Funktionen für die mathematische Operationen
    mycomplex operator += (mycomplex z) {
        return {re+=z.re, im+=z.im};
    }
    mycomplex operator -= (mycomplex z) {
        return  {re-=z.re, im -= z.im};
    }
    mycomplex operator *= (mycomplex z) {
        return {re*z.re-im*z.im, re*z.im+im*z.re};
    }
    mycomplex operator /= (mycomplex z) {
        return {re, im};
    }
    double abs() {
        return sqrt((re * re) + (im * im));
    }
    mycomplex power(double x){
        double modulus = abs();
        double arg = atan2(im, re);
        double log_re = log(modulus);
        double log_im = arg;
        double x_log_re = x * log_re;
        double x_log_im = x * log_im;
        double modulus_ans = exp(x_log_re);
        return {modulus_ans * cos(x_log_im), modulus_ans * sin(x_log_im)};
    }
    mycomplex squared() {
        return power(2);
    }
};


mycomplex operator + (mycomplex a, mycomplex b) {
    return a+=b;
}
mycomplex operator - (mycomplex a, mycomplex b) {
    return a-=b;
}
// unäre Minus
mycomplex operator - (mycomplex a) {
    return {-a.real(), -a.imag()};
}
mycomplex operator * (mycomplex a, mycomplex b) {
    return a*=b;
}
mycomplex operator / (mycomplex a, mycomplex b) {
    return a/=b;
}
bool operator == (mycomplex a, mycomplex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}
bool operator != (mycomplex a, mycomplex b) {
    return !(a==b);
}
mycomplex sqrt(mycomplex);

int main() {
    mycomplex a{4.5, 7.3};
    mycomplex b{5.1, 2.3};
    mycomplex res = a + b;
    std::cout <<"a + b = "<<res.real()<<" - "<<res.imag()<<"i"<< std::endl;
    mycomplex res2 = a + b;
    std::cout <<"a - b = "<<res2.real()<<" - "<<res2.imag()<<"i"<< std::endl;
    mycomplex res3 = a / b;
    std::cout <<"a / b = "<<res3.real()<<" - "<<res3.imag()<<"i"<< std::endl;
    mycomplex res4 = a * b;
    std::cout <<"a * b = "<<res4.real()<<" - "<<res4.imag()<<"i"<< std::endl;
    mycomplex res5 = a.power(2);
    std::cout <<"a ^ 2 = "<<res5.real()<<" - "<<res5.imag()<<"i"<< std::endl;
    mycomplex res6 = a.squared();
    std::cout <<"a ^ 2 = "<<res6.real()<<" - "<<res6.imag()<< "i"<< std::endl;

    return 0;
}