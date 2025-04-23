
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{

    try
    {
        /* creating Bureaucrat */
        Bureaucrat intern("Intern", 150);
        Bureaucrat manager("Manager", 40);
        Bureaucrat ceo("Ceo", 1);

        /* Forms */
        ShrubberyCreationForm shForm("HOME");
        RobotomyRequestForm rrForm("OFFICE");
        PresidentialPardonForm ppForm("PRISONER");
        
        manager.executeForm(shForm); // he cant, not signed
        
        /* Signing */
        intern.signForm(shForm); // he can't, low grade
        manager.signForm(shForm);
        manager.signForm(rrForm);
        manager.signForm(ppForm); // he cant.. now lets call the ceo
        ceo.signForm(ppForm);

        /* Executing */
        std::cout << "Execution\n";
        intern.executeForm(shForm); // he cant, low grade
        manager.executeForm(shForm);
        manager.executeForm(rrForm);
        manager.executeForm(ppForm); // he cant, low grade
        ceo.executeForm(ppForm);

        std::cout << "Overloading\n";
        std::cout << intern;
        std::cout << manager;
        std::cout << ceo;
        std::cout << shForm;
        std::cout << rrForm;
        std::cout << ppForm;

        // /* with Ptr & Ref*/
        // RobotomyRequestForm *formPtr = new RobotomyRequestForm(rrForm);
        // RobotomyRequestForm formObj(*formPtr);
        // RobotomyRequestForm &formRef = formObj;

        // std::cout << "Form Ptr before: " << *formPtr;
        // std::cout << "Form Obj before: " << formObj;
        // std::cout << "Form Ref before: " << formRef;

        // delete formPtr;
    
        // std::cout << "Form Obj after: " << formObj;
        // std::cout << "Form Ref after: " << formRef;

    }
    catch (std::exception & e)
    {
        /* handle exception */
        std::cerr << "*** Exception in Main ***\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}