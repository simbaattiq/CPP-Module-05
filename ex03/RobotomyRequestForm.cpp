

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45, "Default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    CheckExcutionRequirment(executor);

    std::srand(std::time(0));
    int random = std::rand();

    std::cout << "Makes drilling noises...\n";
    
    if (random % 2 == 0)
    {
        std::cout << this->getTarget();
        std::cout << " has been robotomized [successfully]\n";
    }
    else
        std::cout << "the robotomy [failed]\n";
  
}