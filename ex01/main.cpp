
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        // Bureaucrat a("Ahmed", 2);
        // Bureaucrat a; // default dummy
        // Bureaucrat b("Joe", 149);
       
        // a.increment();
        // b.decrement();
        // std::cout << a.getName() << ", New Grade: " << a.getGrade() << std::endl;
        // std::cout << b.getName() << ", New Grade: " << b.getGrade() << std::endl;
        // a.increment(); // this throws an exception
        // b.decrement(); // this also should do so 
        // std::cout << a.getName() << ", New Grade: " << a.getGrade() << std::endl;
        // std::cout << b.getName() << ", New Grade: " << b.getGrade() << std::endl;

        // std::cout << "Overloding << :" << a;
        // std::cout << "Overloding << :" << b;

        /*ex01 code*/
        Bureaucrat q("Adam", 76);
        Form       l("[Redacted]", 75, 75);
        Form       d(l);
        // Form       d = l;

        q.signForm(l);

        std::cout << "OVERLOADING**\n";
        std::cout << q;
        std::cout << l;
        std::cout << d; // signed will be false;

    }
    // catch(Bureaucrat::GradeTooHighException& e)
    // {
    //     std::cerr << "Grade Too Hiiiigh!!!\n";
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     std::cerr << "Grade Too Lowwww!!!\n";
    // }
    // catch(Form::GradeTooHighException& a)
    // {
    //     std::cerr << "We Catched a Form Exception Type: \n";
    //     std::cerr << a.what() << std::endl;
    // }
    // catch(Form::GradeTooLowException& a)
    // {
    //     std::cerr << "We Catched a Form Exception Type: ";
    //     std::cerr << a.what() << std::endl;
    // }
    catch (std::exception & e)
    {
        std::cerr << "*** Exception Detected ***\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}