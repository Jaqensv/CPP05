#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

class Bureaucrat {

public:

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);
	const std::string getName() const;
	int	getGrade() const;
	void upGrade();
	void downGrade();
	void gradeChecker(int grade);
	/////////////////////////////////////////////////////
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Grade is too low!";
		}
	};

private:

	const std::string	_name;
	int					_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif