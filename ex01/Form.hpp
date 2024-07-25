#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

	Form();
	~Form();
	Form(std::string name, int gts, int gte);
	Form(Form const &src);
	Form &operator=(Form const &src);
	std::string getName() const;
	bool getSigned() const;
	int getGts() const;
	int getGte() const;
	std::string getReason() const;
	void formGradeChecker(int gts, int gte);
	void beSigned(Bureaucrat bureaucrat);
	//////////////////////////////////////////////
	class GradeTooHighException : std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too high!";
		}
	};
	class GradeTooLowException : std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too low!";
		}
	};

private:

	std::string _name;
	bool		_signed;
	int			_gts; // grade to sign
	int			_gte; // grade to execute
	std::string	_reason;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
