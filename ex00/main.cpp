#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat a;
    Bureaucrat b(0, "Fack");
    Bureaucrat c(a);
    Bureaucrat d(152, "Vanya");

    c = d;

    a.incrGrade();
    a.decrGrade();
    a.decrGrade();
    std::cout<<a<<std::endl;
    for(int i = 0; i < 10; i++)
    {
        c.incrGrade();
        std::cout<<c<<std::endl;
    }
    return (0);
}