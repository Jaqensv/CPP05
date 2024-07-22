#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	std::string getName() const;
	int	getGrade() const;
	void upGrade();
	void downGrade();
	// Bureaucrat &operator=(Bureaucrat const &rhs);

private:
	std::string	_name;
	int			_grade;
};

#endif