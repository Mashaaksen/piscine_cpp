#include "Form.hpp"

Form::Form():_isSign(false), _name("FORM"), _gradeSign(150), _gradeExecute(150)
{
}

Form::Form(const std::string name, const int sign, const int execute) :_isSign(false), _name(name), _gradeSign(sign), _gradeExecute(execute)
{
    try
    {
        if (sign < 1 || execute < 1)
        {
            if (sign < 1)
                const_cast<int&>((this)->_gradeSign) = 1;
            else if (execute < 1)
                const_cast<int&>((this)->_gradeExecute) = 1;
            throw Form::GradeTooHighException();
        }
        else if (sign > 150 || execute > 150)
        {
            if (sign > 15)
                const_cast<int&>((this)->_gradeSign) = 150;
            else if (execute > 15)
                const_cast<int&>((this)->_gradeExecute) = 150;
            throw Form::GradeTooLowException();
        }
        else
        {
            const_cast<int&>((this)->_gradeSign) = sign;
            const_cast<int&>((this)->_gradeExecute) = execute;
        }
    }
    catch (std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}

Form::Form(const Form &obj):_isSign(obj._isSign), _name(obj._name), _gradeSign(obj._gradeSign), _gradeExecute(obj._gradeExecute)
{
}

Form &Form::operator=(const Form &obj)
{
    _isSign = obj._isSign;
    const_cast<std::string&>((this)->_name) = obj._name;
    const_cast<int&>((this)->_gradeSign) = obj._gradeSign;
    const_cast<int&>((this)->_gradeExecute) = obj._gradeExecute;
    return (*this);
}

const std::string Form::getName() const
{
    return (this->_name);
}

int Form::getSign() const
{
    return (this->_gradeSign);
}

int Form::getExecute() const
{
    return (this->_gradeExecute);
}

bool Form::getIsSign() const
{
    return (this->_isSign);
}

void Form::beSigned(const Bureaucrat &obj)
{
    if (obj.getGrade() <= this->getSign())
        this->_isSign = true;
}

Form::~Form()
{
}

std::ostream& operator<<(std::ostream& stream, const Form& obj)
{
    stream<<"<"<<obj.getName()<<">"<<", form grade sign <"<<obj.getSign()<<">"<<", form grade execute <"<<obj.getExecute()<<">"<<", sign <"<<obj.getIsSign()<<">";
    return (stream);
}