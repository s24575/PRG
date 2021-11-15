#ifndef STUDENT_RPN_CALCULATOR_H
#define STUDENT_RPN_CALCULATOR_H

#include <memory>
#include <queue>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <string>

struct Element {
	virtual void evaluate(std::stack<double>&) const = 0;
	virtual ~Element() {}
};

struct Literal : Element {
	double const value{ 0.0 };

	void evaluate(std::stack<double>& stack) const override
	{
		stack.push(value);
	}
	Literal(double const x) : value(x) {}
};

struct Print : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.empty()) {
			throw std::logic_error{ "empty stack" };
		}
		auto element = std::move(stack.top());
		std::cout << element << '\n';
	}
};

struct Addition : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for + operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(a + b);
	}
};

struct Subtraction : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for - operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(a - b);
	}
};

struct Multiplication : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for * operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(a * b);
	}
};

struct Division : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for / operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(a / b);
	}
};

struct Division_int : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for // operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(int(a / b));
	}
};

struct Modulo : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for % operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(int(a) % int(b));
	}
};

struct Exponentiation : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 2) {
			throw std::logic_error{ "invadid amount of numbers for ** operation" };
		}
		double b = stack.top();
		stack.pop();
		double a = stack.top();
		stack.pop();
		stack.push(pow(a, b));
	}
};

struct Square_root : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 1) {
			throw std::logic_error{ "invadid amount of numbers for sqrt operation" };
		}
		double a = stack.top();
		stack.pop();
		stack.push(sqrt(a));
	}
};

struct Factorial : Element {
	void evaluate(std::stack<double>& stack) const override
	{
		if (stack.size() != 1) {
			throw std::logic_error{ "invadid amount of numbers for ! operation" };
		}
		double a = stack.top();
		stack.pop();
		int fact = 1;
		for (int i = 1; i <= a; i++)
			fact = fact * i;
		stack.push(fact);
	}
};

struct Calculator {
	std::stack<double> stack;
	std::queue<std::unique_ptr<Element>> ops;

	// Convert string to element and push it on the queue of operations to perform.
	void push(std::string x)
	{
		if (x == "p")
		{
			std::unique_ptr<Element> print = std::make_unique<Print>();
			ops.push(std::move(print));
		}
		else if (x == "+")
		{
			std::unique_ptr<Element> plus = std::make_unique<Addition>();
			ops.push(std::move(plus));
		}
		else if (x == "-")
		{
			std::unique_ptr<Element> minus = std::make_unique<Subtraction>();
			ops.push(std::move(minus));
		}
		else if (x == "*")
		{
			std::unique_ptr<Element> times = std::make_unique<Multiplication>();
			ops.push(std::move(times));
		}
		else if (x == "/")
		{
			std::unique_ptr<Element> divided = std::make_unique<Division>();
			ops.push(std::move(divided));
		}
		else if (x == "//")
		{
			std::unique_ptr<Element> divided_int = std::make_unique<Division_int>();
			ops.push(std::move(divided_int));
		}
		else if (x == "%")
		{
			std::unique_ptr<Element> modulo = std::make_unique<Modulo>();
			ops.push(std::move(modulo));
		}
		else if (x == "**")
		{
			std::unique_ptr<Element> power = std::make_unique<Exponentiation>();
			ops.push(std::move(power));
		}
		else if (x == "sqrt")
		{
			std::unique_ptr<Element> sqrt = std::make_unique<Square_root>();
			ops.push(std::move(sqrt));
		}
		else if (x == "!")
		{
			std::unique_ptr<Element> factorial = std::make_unique<Factorial>();
			ops.push(std::move(factorial));
		}
		else
		{
			std::unique_ptr<Element> num = std::make_unique<Literal>(std::stod(x));
			ops.push(std::move(num));
		}
	}

	// Evaluate scheduled operations.
	void evaluate()
	{
		while (!ops.empty())
		{
			std::unique_ptr<Element>& x = ops.front();
			x->evaluate(stack);
			ops.pop();
		}
	}

	Calculator() = default;
	//Calculator(std::stack<double>) {}
};

#endif