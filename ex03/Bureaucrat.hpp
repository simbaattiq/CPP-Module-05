

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

#include "AForm.hpp"


class AForm;

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;

public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade_init);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat(void);

    // Getters Setters
    const std::string&  getName(void) const;
    int                 getGrade(void) const;
    void                increment(void); 
    void                decrement(void);

    // exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    void signForm(AForm& f);
    void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);
#endif