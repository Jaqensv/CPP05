#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Form.hpp"

class Form;

class Bureaucrat {

public:

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	const std::string getName() const;
	void gradeChecker(int grade);
	void gradeModifier(int modifier);
	int	getGrade() const;
	void upGrade();
	void downGrade();
	void signForm(Form &form) const;

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(const char *error);
		virtual const char* what() const throw() {
			return this->_error;
		}
	private:
		const char *_error;
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(const char *error);
		virtual const char* what() const throw() {
			return this->_error;
		}
	private:
		const char *_error;
	};

private:

	const std::string	_name;
	int					_grade;

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif