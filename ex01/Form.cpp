
#include "Form.hpp"

Form::Form(void) : name("Default"), sign(false), gr_toSign(150), gr_toExcut(150) {}

Form::Form(std::string name, int toSign, int toExcut)
:   name(name),
    sign(false),
    gr_toSign(toSign),
    gr_toExcut(toExcut)
{
    if (gr_toSign > 150 || gr_toExcut > 150)
        throw GradeTooLowException();
    else if (gr_toSign < 1 || gr_toExcut < 1)
        throw GradeTooHighException();
}

Form::Form(const Form& other) 
:   name(other.name),
    sign(other.sign),
    gr_toSign(other.gr_toSign),
    gr_toExcut(other.gr_toExcut)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->sign = other.sign;
    return (*this);
}

Form::~Form(void) {}

const char* Form::GradeTooHighException::what(void) const throw() 
{
    return ("Form Grade Is Too High");
}

const char* Form::GradeTooLowException::what(void) const throw() 
{
    return ("Form Grade Is Too Low");
}

/* Getters*/
const std::string&  Form::getName(void) const { return (name); }

bool                Form::getSign(void) const { return (sign); }

int           Form::getGradeToSign(void) const { return (gr_toSign); }

int           Form::getGradeToExcut(void) const { return (gr_toExcut); }

/*Setters*/

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->gr_toSign)
        throw GradeTooLowException();
    this->sign = true;
}

std::ostream& operator<<(std::ostream& os, Form& a)
{
    std::cout << "Form: " << a.getName() << ", signed: " << std::boolalpha << a.getSign();
    std::cout << ", grade required to sign it: " << a.getGradeToSign();
    std::cout << ", grade required to excute it: " << a.getGradeToExcut() << std::endl;
    return (os);
}