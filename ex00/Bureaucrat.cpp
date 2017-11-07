#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("cat")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
{
    this->grade = obj.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    this->grade = obj.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(int grade, const std::string name) : name(name), grade(grade)
{
}

const std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrGrade()
{
    try
    {
        if (this->grade - 1 < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade--;
    }
    catch (std::exception &e)
    {
        std::cout<<this->getGrade()<<" "<<e.what()<<std::endl;
    }
}

void Bureaucrat::decrGrade()
{
    try
    {
        if (this->grade + 1 > 150)
            throw Bureaucrat::GradeTooLowException();
        this->grade++;
    }
    catch (std::exception &e)
    {
        std::cout<<this->getGrade()<<" "<<e.what()<<std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj)
{
    stream<<"<"<<obj.getName()<<">"<<", buraucrat grade <"<<obj.getGrade()<<">";
    return (stream);
}