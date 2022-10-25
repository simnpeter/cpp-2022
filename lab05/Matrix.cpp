//
// Created by SP on 2022. 10. 17..
//

#include <random>
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double * [mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double [mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = new double * [mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double [mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
            cout << mElements[i][j] << " ";
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = what.mElements;

    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete [] mElements[i];
    }
    delete [] mElements;
    mRows = 0;
    mCols = 0;
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << ' ';
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if( x.mRows == y.mRows && x.mCols == y.mCols ){
        Matrix temp(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                temp.mElements[i][j] = x.mElements[i][j]+y.mElements[i][j];
            }
        }
        return temp;
    }
    throw out_of_range("out of range");
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mCols == y.mRows){
        Matrix temp(x.mRows, y.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < y.mCols; ++j) {
                for (int k = 0; k < x.mCols; ++k) {
                    temp[i][j] += x.mElements[i][k]*y.mElements[k][j];
                }
            }
        }
        return temp;
    }
    throw out_of_range("baj van bari haljak meg");
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (mRows == mat.mRows && mCols == mat.mCols){
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
    throw out_of_range("out of range!");
}

Matrix &Matrix::operator=(Matrix &&mat) {
    for (int i = 0; i < this->mRows; ++i) {
        delete []mElements[i];
    }
    delete []mElements;

    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = mat.mElements;

    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}

double *Matrix::operator[](int index) {
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }

    return is;
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(a, b);
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = dist(mt);
        }
    }
}

bool Matrix::isSquare() const {
    return getCols() == getRows();
}
