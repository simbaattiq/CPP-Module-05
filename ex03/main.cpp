

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    Bureaucrat ceo("CEO", 1);
    Bureaucrat supervisor("Supervisor", 100);
    try
    {
        // Intern someRandomIntern;
        AForm* rrf;
        // rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // rrf = someRandomIntern.makeForm("robotom y request", "Bender");

        // rrf = someRandomIntern.makeForm("shrubbery creation", "Walee");
        rrf = someRandomIntern.makeForm("presidential pardon", "Walee");
        // rrf = someRandomIntern.makeForm("****", "Walee");
        // rrf = someRandomIntern.makeForm("\n", "Walee");
        // rrf = someRandomIntern.makeForm("Presidential Pardon", "Walee");
        
        supervisor.signForm(*rrf);
        ceo.signForm(*rrf);
        supervisor.executeForm(*rrf);

        // std::cout << *rrf;
        delete rrf;

    }
    catch (AForm::UnknownFormTypeException & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Abnormal Termination\n";
    }
    return (0);
}



/* First Main */

// int main(void)
// {

//     try
//     {
//         /* creating Bureaucrat */
//         Bureaucrat intern("Intern", 150);
//         Bureaucrat manager("Manager", 40);
//         Bureaucrat ceo("Ceo", 1);

//         /* Forms */
//         ShrubberyCreationForm shForm("HOME");
//         RobotomyRequestForm rrForm("OFFICE");
//         PresidentialPardonForm ppForm("PRISONER");
        
//         manager.executeForm(shForm); // he cant, not signed
        
//         /* Signing */
//         intern.signForm(shForm); // he can't, low grade
//         manager.signForm(shForm);
//         manager.signForm(rrForm);
//         manager.signForm(ppForm); // he cant.. now lets call the ceo
//         ceo.signForm(ppForm);

//         /* Executing */
//         intern.executeForm(shForm); // he cant, low grade
//         manager.executeForm(shForm);
//         manager.executeForm(rrForm);
//         manager.executeForm(ppForm); // he cant, low grade
//         ceo.executeForm(ppForm);

//         /* Overloading */
//         std::cout << "Bureaucrat: " << intern;
//         std::cout << "Bureaucrat: " << manager;
//         std::cout << "Bureaucrat: " << ceo;
//         std::cout << "Form: " << shForm;
//         std::cout << "Form: " << rrForm;
//         std::cout << "Form: " << ppForm;

//         /* with Ptr & Ref*/
        
//         RobotomyRequestForm *formPtr = new RobotomyRequestForm(rrForm);
//         RobotomyRequestForm formObj(*formPtr);
//         RobotomyRequestForm &formRef = formObj;

//         std::cout << "Form Ptr before: " << *formPtr;
//         std::cout << "Form Obj before: " << formObj;
//         std::cout << "Form Ref before: " << formRef;

//         delete formPtr;
    
//         std::cout << "Form Obj after: " << formObj;
//         std::cout << "Form Ref after: " << formRef;

//     }
//     catch (std::exception & e)
//     {
//         /* handle exception */
//         std::cerr << "*** Exception in Main ***\n";
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
//     return (0);
// }