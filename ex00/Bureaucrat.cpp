
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Bur"), _grade(75)
{
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	std::cout << "Set Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(string const name, int grade) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
	try
	{
		if (grade < MAXGRADE) throw Bureaucrat::GradeTooHighException();
		else if (grade > MINGRADE) throw Bureaucrat::GradeTooLowException();
		else this->_grade = grade;
	}
	catch (GradeTooHighException &high)
	{
		std::cerr << high.what() << endl;
	}
	catch (Bureaucrat::GradeTooLowException &low)
	{
		std::cerr << low.what() << endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->_grade = obj._grade;
	return (*this);
}

string Bureaucrat::getName() const { return (this->_name); }


void Bureaucrat::addGrade()
{
	try
	{
		if (this->_grade - 1 < MAXGRADE) throw Bureaucrat::GradeTooHighException();
		else this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &high)
	{
		std::cerr << high.what() << endl;
	}
}

void Bureaucrat::removeGrade()
{
	try
	{
		if (this->_grade + 1 > MINGRADE) throw Bureaucrat::GradeTooLowException();
		else this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &low)
	{
		std::cerr << low.what() << endl;
	}
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream & operator<<(std::ostream & out, Bureaucrat src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low exception");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high exception");
}
