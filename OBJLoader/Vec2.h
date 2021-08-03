#pragma once
#include<ostream>

class Vec2
{
public:
	float x, y;

	Vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2(int x, int y)
	{
		this->x = (float)x;
		this->y = (float)y;
	}

	Vec2(float n)
	{
		this->x = n;
		this->y = n;
	}

	Vec2()
	{
		this->x = 0;
		this->y = 0;
	}

	static Vec2 normalize(Vec2 v)
	{
		return v / (v.x + v.y);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vec2& self)
	{
		os << "(" << self.x << ", " << self.y << ")";
		return os;
	}

	Vec2 operator/(float scalar)
	{
		return Vec2(this->x / scalar, this->y / scalar);
	}

	Vec2 operator/(int scalar)
	{
		return Vec2(this->x / scalar, this->y / scalar);
	}

	Vec2 operator+(const Vec2& vec)
	{
		return Vec2(this->x + vec.x, this->y + vec.y);
	}

	Vec2 operator-(const Vec2& vec)
	{
		return Vec2(this->x - vec.x, this->y - vec.y);
	}

	Vec2 operator*(const Vec2& vec)
	{
		return Vec2(this->x * vec.x, this->y * vec.y);
	}
};
