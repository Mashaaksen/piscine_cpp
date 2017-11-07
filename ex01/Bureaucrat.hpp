#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    class GradeTooHighException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade_Too_High_Exception!!!");
        }
    };
    class GradeTooLowException: public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return ("Grade_Too_Low_Exception!!!");
        }
    };
    Bureaucrat();
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat(int grade, const std::string name);
    Bureaucrat &operator=(const Bureaucrat &obj);
    const std::string getName() const;
    int getGrade() const;
    void incrGrade();
    void decrGrade();
    void signForm(const Form &obj);
    ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj);

#endif