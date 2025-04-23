

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

    struct formCreator
    {
        std::string formName;
        AForm* (*FormCptr)(std::string&);
    };
    
    static AForm* ShrubberyCreationFunc(std::string& target);
    static AForm* RobotomyRequestFunc(std::string& target);
    static AForm* PresidentialPardonFunc(std::string& target);

    const static formCreator array[];
    const static int  maxForms = 3;
    
public:
    Intern(void);
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern(void);

    ////
    AForm* makeForm(std::string name, std::string target);
    std::string& changeToLower(std::string & name );
};


#endif