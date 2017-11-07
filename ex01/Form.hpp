#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    bool _isSign;
    const std::string _name;
    const int _gradeSign;
    const int _gradeExecute;
public:
    class GradeTooHighException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("grade too high!!!");
        }
    };
    class GradeTooLowException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("grade too low!!!");
        }
    };
    Form();
    Form(const std::string name, const int sign, const int execute);
    Form(const Form &obj);
    Form &operator=(const Form &obj);
    const std::string getName() const;
    int getSign() const;
    int getExecute() const;
    bool getIsSign() const;
    void beSigned(const Bureaucrat &obj);
    ~Form();
};

std::ostream& operator<<(std::ostream& stream, const Form& obj);

#endif