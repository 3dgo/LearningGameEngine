
Vector3D& Vector3D::operator+=(const Vector3D& right)
{
	x += right.x;
	y += right.y;
	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D& right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

Vector3D operator+(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3D operator-(const Vector3D& left, const Vector3D& right)
{
	return Vector3D(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3D operator*(float scalar, const Vector3D& vector)
{
	return Vector3D(scalar * vector.x, scalar * vector.y, scalar * vector.z);
}

Vector3D operator*(const Vector3D& vector, float scalar)
{
	return scalar * vector;
}