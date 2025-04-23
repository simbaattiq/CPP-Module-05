

#ifndef FORM_HPP
#define FORM_HPP

#include <stdbool.h>
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                sign;
    const int           gr_toSign;
    const int           gr_toExcut;
public:
    Form(void);
    ~Form(void);
    Form(std::string name, int toSign, int toExcut);
    Form(const Form& other);
    Form& operator=(const Form& other);

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what(void) const throw();
    }; 
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what(void) const throw();
    };

    // getters
    const std::string&  getName(void) const;
    bool                getSign(void) const;
    int                 getGradeToSign(void) const;
    int                 getGradeToExcut(void) const;

    // Additional Funcs
    void                beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, Form& a);

#endif