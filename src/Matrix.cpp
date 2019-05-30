#include <iostream>
#include <iomanip>
#include <random>
#include <NN/Matrix.h>

using namespace std;

Matrix::Matrix(int t_rowsCount, int t_colsCount, bool isRandom) 
    : m_rowsCount(t_rowsCount), m_colsCount(t_colsCount)
{
    for (int i = 0; i < this->m_rowsCount; i++) {
        vector<double> row;
        for (int j = 0; j < this->m_colsCount; j++) {
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

Matrix::Matrix(Matrix &&rhs)
    : m_rowsCount(rhs.m_rowsCount), m_colsCount(rhs.m_colsCount), m_values(move(rhs.m_values))
{}
    

Matrix Matrix::transpose() {
    Matrix transposed{this->m_colsCount, this->m_rowsCount};
    for (int i = 0; i < this->m_rowsCount; i++) {
        for (int j = 0; j < this->m_colsCount; j++) {
            transposed.setValue(j, i, this->m_values.at(i).at(j));
        }
    }
    return move(transposed);
}

void Matrix::setValue(int rowNum, int colNum, double value) {
    this->m_values.at(rowNum).at(colNum) = value;
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

double Matrix::getRandomValue() const {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}