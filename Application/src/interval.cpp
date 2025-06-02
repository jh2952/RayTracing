#include "util.h"
#include "interval.h"

const interval interval::empty    = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

interval::interval()
	: m_min{ +infinity }
	, m_max{ -infinity }
{
}

interval::interval(double min, double max)
	: m_min{ min }
	, m_max{ max }
{
}

double interval::size() const
{
	return m_max - m_min;
}

bool interval::contains(double x) const
{
	return m_min <= x && x <= m_max;
}

bool interval::surrounds(double x) const
{
	return m_min < x && x < m_max;
}
