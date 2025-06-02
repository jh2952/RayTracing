#ifndef INTERVAL_H
#define INTERVAL_H

class interval
{
public:
	double m_min;
	double m_max;

	interval();

	interval(double min, double max);

	double size() const;

	bool contains(double x) const;

	bool surrounds(double x) const;

	static const interval empty;
	static const interval universe;
};

#endif