#pragma once

#include <string>

namespace Minecraft
{
	template<typename T> class Vector;

	template <typename T> Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs);
	template <typename T> Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs);

	template<typename T>
	class Vector
	{
	private:
		T X;
		T Y;
		T Z;
	public:
		Vector(T x, T y, T z);
		Vector(T x, T y);
		Vector();

		void Scale(T factor);
		void Floor();

		T Magnitude();

		T Distance(Vector<T> destination);

		T GetX();
		T GetY();
		T GetZ();

		void SetX(T x);
		void SetY(T y);
		void SetZ(T z);

		std::string ToString();

		friend Vector operator+<T>(const Vector& vec1, const Vector& vec2);
		friend Vector operator-<T>(const Vector& vec1, const Vector& vec2);
	};

	template<typename T>
	inline Vector<T>::Vector(T x, T y, T z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	template<typename T>
	inline Vector<T>::Vector(T x, T y)
	{
		X = x;
		Y = y;
		Z = 0;
	}

	template<typename T>
	inline Vector<T>::Vector()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

	template<typename T>
	inline void Vector<T>::Scale(T factor)
	{
		X *= factor;
		Y *= factor;
		Z *= factor;
	}

	template<typename T>
	inline void Vector<T>::Floor()
	{
		if (!std::is_same<T, double>() && !std::is_same<T, float>())
		{
			std::cerr << "Failed to floor vector: not float or double type" << std::endl;
			return;
		}
		X = std::floor(X);
		Y = std::floor(Y);
		Z = std::floor(Z);
	}

	template<typename T>
	inline T Vector<T>::Magnitude()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}


	template<typename T>
	inline T Vector<T>::Distance(Vector<T> destination)
	{
		T dx = X - destination.X;
		T dy = Y - destination.Y;
		T dz = Z - destination.Z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	template<typename T>
	inline T Vector<T>::GetX()
	{
		return X;
	}

	template<typename T>
	inline T Vector<T>::GetY()
	{
		return Y;
	}

	template<typename T>
	inline T Vector<T>::GetZ()
	{
		return Z;
	}

	template<typename T>
	inline void Vector<T>::SetX(T x)
	{
		X = x;
	}

	template<typename T>
	inline void Vector<T>::SetY(T y)
	{
		Y = y;
	}

	template<typename T>
	inline void Vector<T>::SetZ(T z)
	{
		Z = z;
	}

	template <typename T>
	inline Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		Vector<T> result;
		result.X = lhs.X + rhs.X;
		result.Y = lhs.Y + rhs.Y;
		result.Z = lhs.Z + rhs.Z;
		return result;
	}

	template<typename T>
	inline Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		Vector<T> result;
		result.X = lhs.X - rhs.X;
		result.Y = lhs.Y - rhs.Y;
		result.Z = lhs.Z - rhs.Z;
		return result;
	}

	template<typename T>
	inline std::string Vector<T>::ToString()
	{
		return "(" + std::to_string(X) + "," + std::to_string(Y) + "," + std::to_string(Z) + ")";
	}
}

