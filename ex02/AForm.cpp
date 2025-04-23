

#include "AForm.hpp"

AForm::AForm(void) 
:   name("Default"),
    sign(false),
    gr_toSign(150),
    gr_toExcut(150),
    target("Default_target") {}

AForm::AForm(std::string name, int toSign, int toExcut, std::string target) 
:   name(name),
    sign(false),
    gr_toSign(toSign),
    gr_toExcut(toExcut),
    target(target)
{
    if (gr_toSign > 150 || gr_toExcut > 150)
        throw GradeTooLowException();
    else if (gr_toSign < 1 || gr_toExcut < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm& other) 
:   name(other.name),
    sign(other.sign),
    gr_toSign(other.gr_toSign),
    gr_toExcut(other.gr_toExcut),
    target(other.target)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->sign = other.sign;
    return (*this);
}

AForm::~AForm(void) {}

const char* AForm::GradeTooHighException::what(void) const throw() 
{
    return ("AForm Grade Is Too High");
}

const char* AForm::GradeTooLowException::what(void) const throw() 
{
    return ("AForm Grade Is Too Low");
}

const char* AForm::FormNotSignedException::what(void) const throw() 
{
    return ("AForm Is Not Signed");
}


/* Getters */

const std::string&  AForm::getName(void) const { return (name); }

const std::string&  AForm::getTarget(void) const {return target; };

bool                AForm::getSign(void) const { return (sign); }

int           AForm::getGradeToSign(void) const { return (this->gr_toSign); }

int           AForm::getGradeToExcut(void) const { return (this->gr_toExcut); }


/* Setters */

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->gr_toSign)
        throw GradeTooLowException(); //
    this->sign = true;
}


std::ostream& operator<<(std::ostream& os, AForm& a)
{
    std::cout << "Form: " << a.getName() << ", Target: " << a.getTarget();
    std::cout << ", signed: " << std::boolalpha << a.getSign();
    std::cout << ", grade required to sign it: " << a.getGradeToSign();
    std::cout << ", grade required to excute it: " << a.getGradeToExcut() << std::endl;
    return (os);
}

void AForm::CheckExcutionRequirment(Bureaucrat const & target) const
{
    if (this->sign == 0)
        throw FormNotSignedException();
    if (target.getGrade() > this->gr_toExcut)
        throw GradeTooLowException();
}