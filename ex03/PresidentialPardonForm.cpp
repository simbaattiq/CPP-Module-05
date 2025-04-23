

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5, "Default_target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("presidential pardon", 25, 5, target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    CheckExcutionRequirment(executor);

    std::cout << this->getTarget();
    std::cout << " has been pardoned by Zaphod Beeblebrox.\n";
}