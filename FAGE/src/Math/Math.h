#pragma once

namespace fage
{

	template<typename T>
	struct Vector2
	{
		Vector2() : x(0), y(0) {

		}

		Vector2(T x, T y) : x(x), y(y)
		{

		}

		Vector2(const Vector2& other)
		{
			x = other.x;
			y = other.y;
		}

		Vector2 operator=(const Vector2& other)
		{
			return Vector2(other);
		}

		Vector2 operator+(const Vector2& other)
		{
			return Vector2(x + other.x, y + other.y);
		}
		
		Vector2 operator+=(const Vector2& other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(const Vector2& other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		T x, y;

	
	};

	template<typename T>
	struct Vector3
	{
		Vector3(T x, T y, T z) : x(x), y(y), z(z)
		{

		}


		T x, y, z;
	};

	typedef Vector2<float> Vec2f;
	typedef Vector2<int> Vec2i;
	typedef Vector2<unsigned int> Vec2u;
	typedef Vector3<float> Vec3f;
	typedef Vector3<int> Vec3i;
	typedef Vector3<unsigned int> Vec3u;
}

