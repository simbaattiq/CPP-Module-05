

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137, "Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("shrubbery creation", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    CheckExcutionRequirment(executor);

    std::string nName = this->getTarget() + "_shrubbery";
    std::ofstream outFile(nName.c_str());
    if (!outFile.is_open())
        throw std::runtime_error("Couldn't Open The File");

    outFile << "    /\\       /\\        /\\       /\\         /\\          " << std::endl ;
    outFile << "   /**\\     /**\\      /**\\     /**\\       /**\\         " << std::endl ;
    outFile << "  /****\\   /****\\    /****\\   /****\\     /****\\        " << std::endl ;
    outFile << " /******\\ /******\\  /******\\ /******\\   /******\\       " << std::endl ;
    outFile << "/********\\********\\/********\\********\\ /********\\      " << std::endl ;
    outFile << "    ||        ||        ||       ||        ||           " << std::endl ;
    outFile << "                                                       " << std::endl ;
    outFile << "   /\\        /\\       /\\        /\\       /\\       /\\   " << std::endl ;
    outFile << "  /**\\      /**\\     /**\\      /**\\     /**\\     /**\\  " << std::endl ;
    outFile << " /****\\    /****\\   /****\\    /****\\   /****\\   /****\\ " << std::endl ;
    outFile << "/******\\  /******\\ /******\\  /******\\ /******\\ /******\\" << std::endl ;
    outFile << "   ||        ||       ||        ||       ||       ||   " << std::endl ;

    outFile.close();
  
}