#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	a;
	Bureaucrat	c("Daddy", 150);

	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
	cout << c.getName() << " burec have grade " << c.getGrade() << endl;
	for (int i = 0; i < 74; i++)
		a.addGrade();
	cout << a.getName() << " burec have grade " << a.getGrade() << endl;
}
