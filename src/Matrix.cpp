#include <iostream>
#include <iomanip>
#include <random>
#include <cassert>
#include <NN/Matrix.h>

using namespace std;

Matrix::Matrix(unsigned long t_rowsCount, unsigned long t_colsCount, bool isRandom)
    : m_rowsCount(t_rowsCount), m_colsCount(t_colsCount)
{
    for (unsigned long i = 0; i < this->m_rowsCount; i++) {
        vector<double> row;
        for (unsigned long j = 0; j < this->m_colsCount; j++) {
            double value = isRandom ? this->getRandomValue() : 0.0;
            row.emplace_back(value);
        }
        m_values.emplace_back(row);
    }
}

Matrix::Matrix(const Matrix &rhs) 
    : m_rowsCount(rhs.m_rowsCount), m_colsCount(rhs.m_colsCount)
{
    for (auto &rhs_row : rhs.m_values) {
        vector<double> row;
        for(auto &value : rhs_row) {
            row.push_back(value);
        }
        m_values.emplace_back(row);
    }
}

Matrix & Matrix::operator=(const Matrix &rhs) {
    if (this != &rhs) {
        this->m_values.clear();
        this->m_rowsCount = rhs.m_rowsCount;
        this->m_colsCount = rhs.m_colsCount;
        for (auto &rhs_row : rhs.m_values) {
            vector<double> row;
            for (auto &value : rhs_row) {
                row.push_back(value);
            }
            m_values.emplace_back(row);
        }
    }
    return (*this);
}

Matrix Matrix::transpose() {
    Matrix transposed{this->m_colsCount, this->m_rowsCount};
    for (unsigned long i = 0; i < this->m_rowsCount; i++) {
        for (unsigned long j = 0; j < this->m_colsCount; j++) {
            transposed.setValue(j, i, this->m_values.at(i).at(j));
        }
    }
    return move(transposed);
}

void Matrix::setValue(unsigned long rowNum, unsigned long colNum, double value) {
    this->m_values.at(rowNum).at(colNum) = value;
}

vector<double> Matrix::toVector() const {
    vector<double> result;
    for (unsigned long i = 0; i < this->m_rowsCount; i++) {
        for (unsigned long j = 0; j < this->m_colsCount; j++) {
            result.push_back(this->m_values.at(i).at(j));
        }
    }
    return result;
}

void Matrix::print() const {
    for (auto &row: m_values) {
        for (auto &val: row) {
            cout.precision(4);
            cout << setw(10) << fixed << val;
        }
        cout << endl;
    }
}

double Matrix::getRandomValue() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

Matrix operator*(const Matrix &m1, const Matrix &m2) {
    Matrix multiplied{m1.getRowsCount(), m2.getColsCount()};
    assert(m1.getColsCount() == m2.getRowsCount());
    for (unsigned long i = 0; i < multiplied.getRowsCount(); i++) {
        for (unsigned long j = 0; j < multiplied.getColsCount(); j++) {
            double value = 0.0;
            for (unsigned long r = 0; r < m1.getColsCount(); r++) {
                value += m1.getValue(i, r) * m2.getValue(r, j);
            }
            multiplied.setValue(i, j, value);
        }
    }
    return move(multiplied);
}
