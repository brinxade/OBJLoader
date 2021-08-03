#pragma once
#include<ostream>

class Vec3
{
public:
	float x, y, z;

	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3(int x, int y, int z)
	{
		this->x = (float)x;
		this->y = (float)y;
		this->z = (float)z;
	}

	Vec3(float n)
	{
		this->x = n;
		this->y = n;
		this->z = n;
	}

	Vec3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	static Vec3 normalize(Vec3 v)
	{
		return v / (v.x + v.y + v.z);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vec3& self)
	{
		os << "(" << self.x << ", " << self.y << ", " << self.z << ")";
		return os;
	}

	Vec3 operator/(float scalar)
	{
		return Vec3(this->x / scalar, this->y / scalar, this->z / scalar);
	}

	Vec3 operator/(int scalar)
	{
		return Vec3(this->x / scalar, this->y / scalar, this->z / scalar);
	}

	Vec3 operator+(const Vec3& vec)
	{
		return Vec3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
	}

	Vec3 operator-(const Vec3& vec)
	{
		return Vec3(this->x - vec.x, this->y - vec.y, this->z - vec.z);
	}

	Vec3 operator*(const Vec3& vec)
	{
		return Vec3(this->x * vec.x, this->y * vec.y, this->z * vec.z);
	}

	Vec3 operator^(const Vec3& vec)
	{
		Vec3 result;
		float xyz[] = {
			this->y * vec.z - this->z * vec.y,
			this->z * vec.x - this->x * vec.z,
			this->x * vec.y - this->y * vec.x
		};

		result.x = xyz[0];
		result.y = xyz[1];
		result.z = xyz[2];
		return result;
	}
};