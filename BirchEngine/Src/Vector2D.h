#pragma once
#include <iostream>


//x and y position
//create vectors, default 0,0 and add float we want. add sub mult div, functions for that, and override operatoars, where we can do ex. v1.add() v1 += v2
//plot gps of tractor
class Vector2D 
{
public:
	float x;
	float y;

	Vector2D(); //default const
	Vector2D(float x, float y); //overridden const
	
	Vector2D& Add(const Vector2D& vec); 
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& vec); 
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);


	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec); 

};






