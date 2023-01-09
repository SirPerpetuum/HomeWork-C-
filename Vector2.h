//
// Created by 1 on 28.11.2022.
//

#ifndef HELLO_WORLD_VECTOR2_H
#define HELLO_WORLD_VECTOR2_H


class Vector2 {
public:
    double x, y, p, phi;

    Vector2();
    Vector2(double x, double y);

    double getLen();

    double getPhi();
    Vector2 operator+(const Vector2& vector) const;
    Vector2 operator-(const Vector2& vector) const;
    void operator-=(const Vector2& vector);
    void operator+=(const Vector2& vector);
    void operator*=(const double N);
    void operator/=(const double N);
    Vector2 operator*(const double N) const;
    Vector2 operator/(const double N) const;
    bool operator==(const Vector2& vector) const;
    bool operator!=(const Vector2& vector) const;
    double skew_scalar_product(const Vector2& vector) const;
    double scalar_product(const Vector2& vector) const;
    void norm();
    void change_len(const double N);
    void change_phi(double phi);
    double cos_phi(Vector2& vector) const;

    double getPhiDeg();
};

#endif //HELLO_WORLD_VECTOR2_H