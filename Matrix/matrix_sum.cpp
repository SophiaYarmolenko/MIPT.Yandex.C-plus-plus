#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {

private:
    int numRows;
    int numCols;
    vector<vector<int>> matrix;

public:
    Matrix()
    {
        this->numRows = 0;
        this->numCols = 0;
    }

    Matrix(int num_rows, int num_columns)
    {
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns)
    {
        if (num_rows < 0)
        {
            throw out_of_range("out_of_range");
        }

        if (num_columns < 0)
        {
            throw out_of_range("out_of_range");
        }
        if (num_rows == 0 || num_columns == 0)
        {
            num_rows = num_columns = 0;
        }

        this->numCols = num_columns;
        this->numRows = num_rows;
        matrix.assign(num_rows, vector<int>(num_columns));
    }

    int At(int i, int j) const
    {
        return matrix.at(i).at(j);
    }

    int& At(int i, int j)
    {
        return matrix.at(i).at(j);
    }
    int GetNumRows() const
    {
        return this->numRows;
    }
    int GetNumColumns() const
    {
        return this->numCols;
    }
};

istream& operator>>(istream& in, Matrix& mat)
{
    int rows, cols;
    in >> rows >> cols;
    mat.Reset(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            in >> mat.At(i, j);
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& mat) {
    out << mat.GetNumRows() << " " << mat.GetNumColumns() << endl;
    for (int i = 0; i < mat.GetNumRows(); ++i) {
        for (int j = 0; j < mat.GetNumColumns(); ++j) {
            if (j > 0) {
                out << " ";
            }
            out << mat.At(i, j);
        }
        out << endl;
    }
    return out;
}

bool operator==(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1.GetNumRows() != mat2.GetNumRows()) {
        return false;
    }

    if (mat1.GetNumColumns() != mat2.GetNumColumns()) {
        return false;
    }

    for (int i = 0; i < mat1.GetNumRows(); ++i) {
        for (int j = 0; j < mat1.GetNumColumns(); ++j) {
            if (mat1.At(i, j) != mat2.At(i, j)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1.GetNumRows() != mat2.GetNumRows()) {
        throw invalid_argument("invalid_argument");
    }

    if (mat1.GetNumColumns() != mat2.GetNumColumns()) {
        throw invalid_argument("invalid_argument");
    }

    Matrix sumMat(mat1.GetNumRows(), mat1.GetNumColumns());

    for (int i = 0; i < mat1.GetNumRows(); ++i) {
        for (int j = 0; j < mat1.GetNumColumns(); ++j) {
            sumMat.At(i, j) = mat1.At(i, j) + mat2.At(i, j);
        }
    }
    return sumMat;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}