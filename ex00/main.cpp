
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("Ahmed", 2);
        Bureaucrat b("Joe", 149);
        // // getters
        std::cout << "Testing Getters, Name: " << a.getName() << "Grade: " << a.getGrade() << std::endl;
        std::cout << "Testing Getters, Name: " << b.getName() << "Grade: " << b.getGrade() << std::endl;
        // // setter
        a.increment();
        b.decrement();
        std::cout << a.getName() << ", New Grade: " << a.getGrade() << std::endl;
        std::cout << b.getName() << ", New Grade: " << b.getGrade() << std::endl;
        // a.increment(); // this throws an exception
        // b.decrement(); // this also should do so 
        // std::cout << a.getName() << ", New Grade: " << a.getGrade() << std::endl;
        // std::cout << b.getName() << ", New Grade: " << b.getGrade() << std::endl;

        /* Overloding */
        std::cout << a;
        std::cout << b;

        /* Copy, Assign */
        // Bureaucrat a2("Ahmed", 42);
        // Bureaucrat b2(a2);
        // Bureaucrat b2;
        // b2 = a2; // this will assign only the grade

        // std::cout << "Default after: " << b2 ;

    }

    // catch(Bureaucrat::GradeTooHighException& e)
    // {
    //     //
    //     std::cerr << "Grade Too Hiiiigh!!!\n";
    // }
    // catch (Bureaucrat::GradeTooLowException& e)
    // {
    //     ///
    //     std::cerr << "Grade Too Lowwww!!!\n";

    // }

    catch (std::exception & e)
    {
        std::cerr << "*** Exception Detected ***\n";
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}