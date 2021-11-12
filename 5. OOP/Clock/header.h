#ifndef STUDENT_RPN_CALCULATOR_H
#define STUDENT_RPN_CALCULATOR_H

#include <memory>
#include <queue>
#include <stack>
#include <iostream>
#include <string>

struct Element {
	virtual void evaluate(std::stack<double>&) const = 0;
	virtual ~Element();
};
/*
struct Literal : Element {
	double const value{ 0.0 };

	void evaluate(std::stack<double>&) const override;

	Literal(double const);
	};

struct Print : Element {
	void evaluate(std::stack<double>&) const override;
};

struct Addition : Element {
	void evaluate(std::stack<double>&) const override;
};
*/
struct Calculator {
	std::vector<std::string> stack1;
	std::stack<double> stack;
	std::queue<std::unique_ptr<Element>> ops;

	// Schedule operation for evaluation.

/*
	void push(std::unique_ptr<Element>);

	// Convert string to element and push it on the queue of operations to perform.

	void push(std::string);

	// Evaluate scheduled operations.

	void evaluate();
*/
	Calculator() = default;
	Calculator(std::stack<double>);
	Calculator(std::vector<std::string>);

};

#endif
