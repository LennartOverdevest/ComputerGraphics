#ifndef EXERCISES_H
#define EXERCISES_H
#include <list>
#include <set>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ////////////////// Exercise 1 ////////////////////////////////////

using namespace std;


std::pair<float, float> Statistics(const std::list<float>& values)
{
	if (values.size() == 0) {
		return std::pair<float, float>(0.f, 0.f);
	}
	else {
		float total = 0;
		float mean = 0;
		float stddevtotal = 0;

		int n = values.size();

		for (list<float>::const_iterator it = values.begin(); it != values.end(); it++)
		{
			total = total + *it;
		}
		mean = total / (float)n;


		for (list<float>::const_iterator it2 = values.begin(); it2 != values.end(); it2++)
		{
			float delta = (*it2 - mean);
			float square = delta*delta;
			stddevtotal = stddevtotal + square;
		}
		float stddev = stddevtotal / (float)n;
		stddev = sqrt(stddev);
		return std::pair<float, float>(mean, stddev);
	}
}
//////////////////////////////////////////////////////////////////

////////////////// Exercise 2 ////////////////////////////////////
class TreeVisitor {
public:
	float visitTree(const Tree& tree, bool countOnlyEvenLevels) {
		float sum = tree.value;
		bool countAllLevels = false;

		if (countOnlyEvenLevels == true) {
			return visitEven(tree, 0);
		}
		else {
			for (list<Tree>::const_iterator iterator = tree.children.begin(); iterator != tree.children.end(); iterator++) {
				Tree c = *iterator;
				sum = sum + visitTree(c, countAllLevels);
			}
			return sum;
		}
	}

	float visitEven(const Tree& tree, int currentLevel) {
		float tot = 0;
		if (currentLevel % 2 == 0)
			tot = tree.value;
		for (list<Tree>::const_iterator iterator = tree.children.begin(); iterator != tree.children.end(); iterator++) {
			Tree child = *iterator;
			tot = tot + visitEven(child, currentLevel + 1);
		}
		return tot;
	}
};
//////////////////////////////////////////////////////////////////

////////////////// Exercise 3 ////////////////////////////////////
class Complex {
public:
	float real, im;
	Complex(float r, float i) {
		real = r;
		im = i;
	}

	Complex operator +(const Complex& c2) {
		return Complex(real + c2.real, im + c2.im);
	}

	Complex operator -(const Complex& c2) {
		return Complex(real - c2.real, im - c2.im);
	}

	Complex operator *(const Complex& c2) {
		return Complex(((real * c2.real) - (im * c2.im)), ((real * c2.im) + (im * c2.real)));
	}
};
//////////////////////////////////////////////////////////////////

////////////////// Exercise 4 ////////////////////////////////////
float WaterLevels(list<float> heights)
{
	list<float>::const_iterator iterator = heights.begin();
	iterator++;

	float sum = 0;


	while (iterator != prev(heights.end())) {
		list<float>::const_iterator leftside = prev(iterator);
		list<float>::const_iterator rightside = next(iterator);

		float leftmax = *heights.begin();
		float rightmax = *rightside;

		for (leftside; leftside != heights.begin(); leftside--) {
			if (leftmax < *leftside)
				leftmax = *leftside;
		}

		for (rightside; rightside != heights.end(); rightside++) {
			if (rightmax < *rightside)
				rightmax = *rightside;
		}

		float add = 0;
		if (leftmax < rightmax) {
			add = leftmax;
		}
		else {
			add = rightmax;
		}
		add = add - *iterator;

		if (add > 0)
			sum = sum + add;
		iterator++;
	}

	return sum;
}


////////////////// Exercise 5 ////////////////////////////////////
typedef std::pair<int, int> location;

int Labyrinth(std::set<std::pair<location, location> > labyrinth, int size)
{
	return 0;
}
//////////////////////////////////////////////////////////////////

#endif