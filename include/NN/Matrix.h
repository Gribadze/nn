#ifndef NN_MATRIX_H
#define NN_MATRIX_H

#include <vector>

typedef std::vector<std::vector<double>> vector2d;

class Matrix {
private:
    int m_rowsCount;
    int m_colsCount;
    vector2d m_values;
public:
    Matrix(): m_rowsCount(0), m_colsCount(0), m_values(vector2d()) {}
    explicit Matrix(int t_rowsCount, int t_colsCount, bool isRandom = false);
    Matrix(const Matrix &rhs);
    Matrix(Matrix &&rhs);
    Matrix & operator=(const Matrix &rhs);
    Matrix transpose();
    void setValue(int rowNum, int colNum, double value); 
    double getValue(int rowNum, int colNum) const { return this->m_values.at(rowNum).at(colNum); }
    int getRowsCount() const { return this->m_rowsCount; }
    int getColsCount() const { return this->m_colsCount; }
    std::vector<double> toVector() const;
    void print() const;
private:
    double getRandomValue() const;
};

Matrix operator*(const Matrix &m1, const Matrix &m2);

#endif
