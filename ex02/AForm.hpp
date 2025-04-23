

#ifndef AFORM_HPP
#define AFORM_HPP

#include <stdbool.h>
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>


class Bureaucrat;

class AForm
{
private:
    const std::string   name;
    bool                sign;
    const int           gr_toSign;
    const int           gr_toExcut;
    const std::string   target;
public:
    AForm(void);
    virtual ~AForm(void);
    AForm(std::string name, int toSign, int toExcut, std::string target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what(void) const throw();
    }; 
    
    class GradeTooLowException : public std::exception
    {
    public:
        const char* what(void) const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char* what(void) const throw();
    };

    // getters
    const std::string&  getName(void) const;
    const std::string&  getTarget(void) const;
    bool                getSign(void) const;
    int                 getGradeToSign(void) const;
    int                 getGradeToExcut(void) const;

    // Additional Funcs
    void                beSigned(const Bureaucrat& b);
    virtual void        execute(Bureaucrat const & executor) const = 0;
    void CheckExcutionRequirment(Bureaucrat const & target) const;
};

std::ostream& operator<<(std::ostream& os, AForm& a);

#endif