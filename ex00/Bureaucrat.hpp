
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define MAXGRADE 1
#define MINGRADE 150
#include <iostream>
#include <exception>
using std::string;
using std::cout;
using std::endl;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(string const name, int grade);
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat();
	Bureaucrat	&operator=(const Bureaucrat &obj);
	string			getName() const;
	int				getGrade() const;
	void			addGrade();
	void			removeGrade();
class GradeTooHighException : public std::exception
	{
		public: virtual const char * what() const throw();
	};
class GradeTooLowException : public std::exception
	{
	public: virtual const char * what() const throw();
	};
private:
	const string	_name;
	int				_grade;
};

std::iostream&	operator<<(std::iostream &out, Bureaucrat &src);

#endif
