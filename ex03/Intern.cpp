
#include "Intern.hpp"


AForm* Intern::ShrubberyCreationFunc(std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::RobotomyRequestFunc(std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::PresidentialPardonFunc(std::string& target)
{
    return (new PresidentialPardonForm(target));
}


const Intern::formCreator Intern::array [] = 
{
    {"shrubbery creation", &Intern::ShrubberyCreationFunc},
    {"robotomy request", &Intern::RobotomyRequestFunc},
    {"presidential pardon", &Intern::PresidentialPardonFunc}
};

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern& other) 
{
     (void)other;
}

Intern& Intern::operator=(const Intern& other) 
{ 
    (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    name = changeToLower(name);
    for (int i = 0; i < maxForms; i++)
    {
        if (name == array[i].formName)
        {
            AForm* ptr = array[i].FormCptr(target);
            std::cout << "Intern Created Form: " << name << '\n';
            return (ptr);
        }
    }
    throw AForm::UnknownFormTypeException();
}

std::string& Intern::changeToLower(std::string & name )
{
    for (size_t i = 0; i < name.length(); i++)
        name[i] = static_cast<char>(std::tolower(name[i]));
    return (name);
}