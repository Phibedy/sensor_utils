#ifndef SENSOR_UTILS_TYPES_H
#define SENSOR_UTILS_TYPES_H

namespace sensor_utils
{
/**
 * @brief 3D Vector
 */
class Vector3
{
    protected:
        static constexpr size_t X = 0;
        static constexpr size_t Y = 1;
        static constexpr size_t Z = 2;
    public:
        Vector3() : Vector3(0.f, 0.f, 0.f) {}

        Vector3(float x, float y, float z)
        {
            data[X] = x;
            data[Y] = y;
            data[Z] = z;
        }

        float& operator()(size_t i) { return data[i]; }
        float& x() { return data[X]; }
        float& y() { return data[Y]; }
        float& z() { return data[Z]; }

        float operator()(size_t i) const { return data[i]; }
        float x() const { return data[X]; }
        float y() const { return data[Y]; }
        float z() const { return data[Z]; }

        Vector3& setZero()
        {
            memset(data, 0, sizeof(*data)*3);
            return *this;
        }

        Vector3 operator-(const Vector3& other) const
        {
            return Vector3( x() - other.x(), y() - other.y(), z() - other.z() );
        }

        Vector3& operator-=(const Vector3& other)
        {
            x() -= other.x();
            y() -= other.y();
            z() -= other.z();
            return *this;
        }

        Vector3 operator+(const Vector3& other) const
        {
            return Vector3( x() + other.x(), y() + other.y(), z() + other.z() );
        }

        Vector3& operator+=(const Vector3& other)
        {
            x() += other.x();
            y() += other.y();
            z() += other.z();
            return *this;
        }

        Vector3 operator-(float scalar) const
        {
            return Vector3( x() - scalar, y() - scalar, z() - scalar );
        }

        Vector3& operator-=(float scalar)
        {
            x() -= scalar;
            y() -= scalar;
            z() -= scalar;
            return *this;
        }

        Vector3 operator+(float scalar) const
        {
            return Vector3( x() + scalar, y() + scalar, z() + scalar );
        }

        Vector3& operator+=(float scalar)
        {
            x() += scalar;
            y() += scalar;
            z() += scalar;
            return *this;
        }

        Vector3 operator*(float scalar) const
        {
            return Vector3( x() * scalar, y() * scalar, z() * scalar );
        }

        Vector3& operator*=(float scalar)
        {
            x() *= scalar;
            y() *= scalar;
            z() *= scalar;
            return *this;
        }

        Vector3 operator/(float scalar) const
        {
            return Vector3( x() / scalar, y() / scalar, z() / scalar );
        }

        Vector3& operator/=(float scalar)
        {
            x() /= scalar;
            y() /= scalar;
            z() /= scalar;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const Vector3& vec)
        {
            out << "Vector[ x: " << vec.x() <<  " y: " << vec.y() << " z: " << vec.z() << " ]";
            return out;
        }

    protected:
        float data[3];
};

    /**
     * @brief 3x3 Matrix
    */
    class Matrix3
    {
    protected:
        static constexpr size_t X = 0;
        static constexpr size_t Y = 1;
        static constexpr size_t Z = 2;
    public:

        Matrix3() : Matrix3(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f) {}

        Matrix3(float xx, float xy, float xz,
                float yx, float yy, float yz,
                float zx, float zy, float zz)
        {
            data[X][X] = xx;
            data[X][Y] = xy;
            data[X][Z] = xz;
            data[Y][X] = yx;
            data[Y][Y] = yy;
            data[Y][Z] = yz;
            data[Z][X] = zx;
            data[Z][Y] = zy;
            data[Z][Z] = zz;
        }

        float& operator()(size_t r, size_t c) { return data[r][c]; }
        float& xx() { return data[X][X]; }
        float& xy() { return data[X][Y]; }
        float& xz() { return data[X][Z]; }
        float& yx() { return data[Y][X]; }
        float& yy() { return data[Y][Y]; }
        float& yz() { return data[Y][Z]; }
        float& zx() { return data[Z][X]; }
        float& zy() { return data[Z][Y]; }
        float& zz() { return data[Z][Z]; }

        float operator()(size_t r, size_t c) const { return data[r][c]; }
        float xx() const { return data[X][X]; }
        float xy() const { return data[X][Y]; }
        float xz() const { return data[X][Z]; }
        float yx() const { return data[Y][X]; }
        float yy() const { return data[Y][Y]; }
        float yz() const { return data[Y][Z]; }
        float zx() const { return data[Z][X]; }
        float zy() const { return data[Z][Y]; }
        float zz() const { return data[Z][Z]; }

        Matrix3& setZero()
        {
            memset(data, 0, sizeof(*data)*9);
            return *this;
        }
        Matrix3& setIdentity()
        {
            setZero();
            for(size_t i = 0; i < 3; i++)
            {
                data[i][i] = 1.f;
            }
            return *this;
        }

    protected:
        float data[3][3];
    };
}

#endif // SENSOR_UTILS_TYPES_H
