#ifndef VEC3_H
#define VEC3_H

class vec3
{
public:
	double m_xyz[3];

	vec3();
	vec3(double x, double y, double z);

	double x() const;
	double y() const;
	double z() const;

	vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	vec3& operator+=(const vec3& v);
	vec3& operator*=(double a);
	vec3& operator/=(double a);

	double length() const;
	double length_squared() const;
};

using point3 = vec3;

std::ostream& operator<<(std::ostream& out, const vec3& v);
vec3 operator+(const vec3& u, const vec3& v);
vec3 operator-(const vec3& u, const vec3& v);
vec3 operator*(const vec3& u, const vec3& v);
vec3 operator*(double a, const vec3& v);
vec3 operator*(const vec3& v, double a);
vec3 operator/(const vec3& v, double a);
double dot(const vec3& u, const vec3& v);
vec3 cross(const vec3& u, const vec3& v);
vec3 unit_vector(const vec3& v);

#endif