#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Unit")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) : name(name)
{
    try
    {
        if (grade < 1)
        {    
            this->grade = 1;
            throw Bureaucrat::GradeTooHighException();
        }
        else if (grade > 150)
        {    
            this->grade = 150;
            throw Bureaucrat::GradeTooLowException();
        }
        else
            this->grade = grade;        
    }
    catch (std::exception &e)
    {
        std::cout<<this->getName()<<" "<<e.what()<<", so he will have "<<this->grade<<std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): name(obj.name)
{
    this->grade = obj.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    const_cast<std::string&>((this)->name) = obj.name;
    this->grade = obj.grade;
    return (*this);
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
        std::cout<<this->getGrade()<<" - 1 "<<e.what()<<std::endl;
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
        std::cout<<this->getGrade()<<" + 1 "<<e.what()<<std::endl;
    }
}

void Bureaucrat::signForm(const Form &obj)
{
    if (obj.getIsSign() == true)
        std::cout<<this->getName()<<" sign "<<obj.getName()<<std::endl;
    else
        std::cout<<this->getName()<<" cannot sign "<<obj.getName()<<" because grade sign form is "<<obj.getSign()<<" and grade bureaucrat is "<<this->getGrade()<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj)
{
    stream<<"<"<<obj.getName()<<">"<<", buraucrat grade <"<<obj.getGrade()<<">";
    return (stream);
}