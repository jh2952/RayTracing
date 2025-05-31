#include "vec3.h"

vec3::vec3()
	: xyz{0.0, 0.0, 0.0}
{
}

vec3::vec3(double x, double y, double z)
	: xyz{x, y, z}
{
}

inline double vec3::x() const 
{ 
	return xyz[0];
}

inline double vec3::y() const 
{
	return xyz[1];
}

inline double vec3::z() const 
{ 
	return xyz[2];
}

inline vec3 vec3::operator-() const 
{ 
	return vec3(-xyz[0], -xyz[1], -xyz[2]);
}

inline double vec3::operator[](int i) const 
{ 
	return xyz[i];
}

double& vec3::operator[](int i)
{ 
	return xyz[i];
}

vec3& vec3::operator+=(const vec3& v)
{
	xyz[0] += v.xyz[0];
	xyz[1] += v.xyz[1];
	xyz[2] += v.xyz[2];
	return *this;
}

vec3& vec3::operator*=(double a)
{
	xyz[0] *= a;
	xyz[1] *= a;
	xyz[2] *= a;
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
	return xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2];
}

inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
	return out << v.xyz[0] << ' ' << v.xyz[1] << ' ' << v.xyz[2];
}

inline vec3 operator+(const vec3& u, const vec3& v)
{
	return vec3(u.xyz[0] + v.xyz[0], u.xyz[1] + v.xyz[1], u.xyz[2] + v.xyz[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v)
{
	return vec3(u.xyz[0] - v.xyz[0], u.xyz[1] - v.xyz[1], u.xyz[2] - v.xyz[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) 
{
	return vec3(u.xyz[0] * v.xyz[0], u.xyz[1] * v.xyz[1], u.xyz[2] * v.xyz[2]);
}

inline vec3 operator*(double a, const vec3& v) 
{
	return vec3(a * v.xyz[0], a * v.xyz[1], a * v.xyz[2]);
}

inline vec3 operator*(const vec3& v, double a) 
{
	return a * v;
}

inline vec3 operator/(const vec3& v, double a) 
{
	return (1 / a) * v;
}

inline double dot(const vec3& u, const vec3& v) 
{
	return u.xyz[0] * v.xyz[0]
		+ u.xyz[1] * v.xyz[1]
		+ u.xyz[2] * v.xyz[2];
}

inline vec3 cross(const vec3& u, const vec3& v) 
{
	return vec3(u.xyz[1] * v.xyz[2] - u.xyz[2] * v.xyz[1],
		u.xyz[2] * v.xyz[0] - u.xyz[0] * v.xyz[2],
		u.xyz[0] * v.xyz[1] - u.xyz[1] * v.xyz[0]);
}

inline vec3 unit_vector(const vec3& v) 
{
	return v / v.length();
}
