#include "util.h"
#include "vec3.h"

vec3::vec3()
	: m_xyz{0.0, 0.0, 0.0}
{
}

vec3::vec3(double x, double y, double z)
	: m_xyz{x, y, z}
{
}

double vec3::x() const 
{ 
	return m_xyz[0];
}

double vec3::y() const 
{
	return m_xyz[1];
}

double vec3::z() const 
{ 
	return m_xyz[2];
}

vec3 vec3::operator-() const 
{ 
	return vec3(-m_xyz[0], -m_xyz[1], -m_xyz[2]);
}

double vec3::operator[](int i) const 
{ 
	return m_xyz[i];
}

double& vec3::operator[](int i)
{ 
	return m_xyz[i];
}

vec3& vec3::operator+=(const vec3& v)
{
	m_xyz[0] += v.m_xyz[0];
	m_xyz[1] += v.m_xyz[1];
	m_xyz[2] += v.m_xyz[2];
	return *this;
}

vec3& vec3::operator*=(double a)
{
	m_xyz[0] *= a;
	m_xyz[1] *= a;
	m_xyz[2] *= a;
	return *this;
}

vec3& vec3::operator/=(double a)
{
	return *this *= 1 / a;
}

double vec3::length() const
{
	return std::sqrt(length_squared());
}

double vec3::length_squared() const
{
	return m_xyz[0] * m_xyz[0] + m_xyz[1] * m_xyz[1] + m_xyz[2] * m_xyz[2];
}

std::ostream& operator<<(std::ostream& out, const vec3& v)
{
	return out << v.m_xyz[0] << ' ' << v.m_xyz[1] << ' ' << v.m_xyz[2];
}

vec3 operator+(const vec3& u, const vec3& v)
{
	return vec3(u.m_xyz[0] + v.m_xyz[0], u.m_xyz[1] + v.m_xyz[1], u.m_xyz[2] + v.m_xyz[2]);
}

vec3 operator-(const vec3& u, const vec3& v)
{
	return vec3(u.m_xyz[0] - v.m_xyz[0], u.m_xyz[1] - v.m_xyz[1], u.m_xyz[2] - v.m_xyz[2]);
}

vec3 operator*(const vec3& u, const vec3& v) 
{
	return vec3(u.m_xyz[0] * v.m_xyz[0], u.m_xyz[1] * v.m_xyz[1], u.m_xyz[2] * v.m_xyz[2]);
}

vec3 operator*(double a, const vec3& v) 
{
	return vec3(a * v.m_xyz[0], a * v.m_xyz[1], a * v.m_xyz[2]);
}

vec3 operator*(const vec3& v, double a) 
{
	return a * v;
}

vec3 operator/(const vec3& v, double a) 
{
	return (1 / a) * v;
}

double dot(const vec3& u, const vec3& v) 
{
	return u.m_xyz[0] * v.m_xyz[0]
		+ u.m_xyz[1] * v.m_xyz[1]
		+ u.m_xyz[2] * v.m_xyz[2];
}

vec3 cross(const vec3& u, const vec3& v) 
{
	return vec3(u.m_xyz[1] * v.m_xyz[2] - u.m_xyz[2] * v.m_xyz[1],
		u.m_xyz[2] * v.m_xyz[0] - u.m_xyz[0] * v.m_xyz[2],
		u.m_xyz[0] * v.m_xyz[1] - u.m_xyz[1] * v.m_xyz[0]);
}

vec3 unit_vector(const vec3& v) 
{
	return v / v.length();
}
