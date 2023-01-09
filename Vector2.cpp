//
// Created by 1 on 28.11.2022.
//

#include <iostream>
#include <cmath>
#include "Vector2.h"
#define M_PI 3.1415926


Vector2::Vector2() : x(0.0), y(0.0), p(0.0), phi(0.0) {};
Vector2::Vector2(double x, double y) : x(x), y(y), p(sqrt(x* x + y * y)), phi(atan2(y, x)) {};

double Vector2::getLen() {
    return sqrt(x * x + y * y);
}

double Vector2::getPhi() {
    return std::atan2(y, x);
}

Vector2 Vector2::operator+(const Vector2& vector) const {
    return Vector2(x + vector.x, y + vector.y);
}

Vector2 Vector2::operator-(const Vector2& vector) const {
    return Vector2(x - vector.x, y - vector.y);
}

void Vector2::operator-=(const Vector2& vector) {
    x -= vector.x;
    y -= vector.y;
}

void Vector2::operator+=(const Vector2& vector) {
    x += vector.x;
    y += vector.y;
}

void Vector2::operator*=(const double N) {
    x *= N;
    y *= N;
}
void Vector2::operator/=(const double N) {
    if (N != 0) {
        x /= N;
        y /= N;
    }
}

Vector2 Vector2::operator/(const double N) const {
    if (N != 0) return Vector2(x / N, y / N);

}

Vector2 Vector2::operator*(const double N) const {
    return Vector2(x * N, y * N);
}

bool Vector2::operator==(const Vector2& vector) const {
    return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector) const {
    return x != vector.x or y != vector.y;
}

double Vector2::skew_scalar_product(const Vector2& vector) const {
    return x * vector.y - vector.x * y;
}

double Vector2::scalar_product(const Vector2& vector) const {
    return x * vector.x + y * vector.y;
}


void Vector2::norm() {
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
}


void Vector2::change_phi(double phi) {
    phi = phi / 180 * M_PI;
    double t1 = x * cos(phi) - y * sin(phi);
    double t2 = x * sin(phi) + y * cos(phi);
    x = t1;
    y = t2;
}

void Vector2::change_len(const double N) {
    double len = sqrt(x * x + y * y);
    x /= len;
    y /= len;
    x *= N;
    y *= N;
}

double Vector2::cos_phi(Vector2& vector) const {
    double len1 = sqrt(x * x + y * y);
    double len2 = vector.getLen();

    return (x * vector.x + y * vector.y) / (len1 * len2);
}


double Vector2::getPhiDeg() {
    return getPhi() * 180 / M_PI;
}