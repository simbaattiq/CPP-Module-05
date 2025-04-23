
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("DEFAULT"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade_init) : name(name)
{
    if (grade_init > 150)
        throw GradeTooLowException();
    else if (grade_init < 1)
        throw GradeTooHighException();
    else
        grade = grade_init;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName(void) const { return (name); }

int Bureaucrat::getGrade(void) const { return (grade); }

void Bureaucrat::increment(void)
{
    if (grade <= 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        grade--;
}

void Bureaucrat::decrement(void)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade >= 150)
        throw GradeTooLowException();
    else
        grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat Grade Is Too High");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat Grade Is Too Low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj)
{
    std::cout << "Bureaucrat " << obj.getName() << ", grade " << obj.getGrade() << std::endl;
    return (os);
}

void Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << "Bureaucrat: " << this->getName() ;
        std::cout << ", Signed Form: " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bureaucrat: " << this->getName();
        std::cerr << ", Couldn't Sign Form: " << f.getName();
        std::cerr << ", Because: " << e.what() << '\n';
    }
}