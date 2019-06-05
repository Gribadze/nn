#ifndef NN_MATRIX_H
#define NN_MATRIX_H

#include <vector>

typedef std::vector<std::vector<double>> vector2d;

class Matrix {
private:
    unsigned long m_rowsCount;
    unsigned long m_colsCount;
    vector2d m_values;
public:
    Matrix() : m_rowsCount(0), m_colsCount(0), m_values(vector2d()) {}

    explicit Matrix(unsigned long t_rowsCount, unsigned long t_colsCount, bool isRandom = false);

    Matrix(const Matrix &rhs);

    Matrix &operator=(const Matrix &rhs);

    Matrix transpose();

    void setValue(unsigned long rowNum, unsigned long colNum, double value);

    double getValue(unsigned long rowNum, unsigned long colNum) const { return this->m_values.at(rowNum).at(colNum); }

    unsigned long getRowsCount() const { return this->m_rowsCount; }

    unsigned long getColsCount() const { return this->m_colsCount; }

    std::vector<double> toVector() const;

    void print() const;

private:
    double getRandomValue();
};

Matrix operator*(const Matrix &m1, const Matrix &m2);

#endif
