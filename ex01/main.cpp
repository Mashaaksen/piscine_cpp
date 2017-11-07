#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form a("UNIT", 10, 10);
    Bureaucrat b;

    std::cout<<a<<std::endl;
    a.beSigned(b);
    b.signForm(a);
    return (0);
}