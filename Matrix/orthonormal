#include <iostream>
#include <stdexcept>//бібліотека для винятків
#include <vector>//бібліотека для вектора

using namespace std;

class Matrix
{

private:
    int numRows;//поле для кількості рядків матриці
    int numCols;//поле для кількості стовпчиків матриці

public:
    vector<vector<int>> matrix;//сама матриця
    Matrix()//конструктор, який по дефолту задає розміри 0*0 коли створюється об'єкт-матриця
    {
        this->numRows = 0;
        this->numCols = 0;
    }

    Matrix(int num_rows, int num_columns)//конструктор, який створює матрицю вже з заданими параметрами
    {
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns)//функція, яка змінює кількість рядків і стовпчиків матриці
    {
        if (num_rows < 0)//якщо параметр буде введено неправильно, то кинеться виняток, а не аварійно все піде
        {
            throw out_of_range("out_of_range");
        }

        if (num_columns < 0)//якщо параметр буде введено неправильно, то кинеться виняток, а не аварійно все піде
        {
            throw out_of_range("out_of_range");
        }
        if (num_rows == 0 || num_columns == 0)
        {
            num_rows = num_columns = 0;
        }

        this->numCols = num_columns;//присвоюємо полю кількості стовпчиків передану кількість
        this->numRows = num_rows;//присвоюємо полю кількості рядків передану кількість
        matrix.assign(num_rows, vector<int>(num_columns));//змінюємо матрицю
    }

    int At(int i, int j) const//повертає елемент з рядка і, стовпчика j
    {
        return matrix.at(i).at(j);
    }

    int& At(int i, int j)//повертає посилання на елемент з рядка і, стовпчика j
    {
        return matrix.at(i).at(j);
    }
    int GetNumRows() const//повертає приватне поле кількості рядків
    {
        return this->numRows;
    }
    int GetNumColumns() const//повертає приватне поле кількості стовпчиків
    {
        return this->numCols;
    }

};

istream& operator>>(istream& in, Matrix& mat)//оператор вводу матриці
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

ostream& operator<<(ostream& out, const Matrix& mat) //оператор виводу матриці
{
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

int operator*(const vector<int> & row1, const vector<int> & row2)//оператор скалярного добутку двох рядків
{
    if (row1.size() != row2.size())//якщо довжина двох рядків не однакова, то кидаємо виняток
    {
        throw invalid_argument("invalid_argument");
    }

    int product = 0;//поле, яке буде результатом скалярного добутку

    for (int i = 0; i < row1.size(); i++)//проходимо по всіх елементах двох рядків, перемножаємо відповідні і додаємо
    {
        product += row1[i]*row2[i];
    }

    return product;
}

bool  CheckSameRow(Matrix mat)//перевіряємо чи всі рядки, при множенні на себе дають 1
{
    for(int i = 0; i < mat.GetNumRows(); i++)//проганяємось по всіх рядках і перевіряємо чи їх скалярний добуток = 1
    {
        if( mat.matrix[i] * mat.matrix[i] != 1)
            return 0;
    }
    return 1;
}

bool  CheckAllRow(Matrix mat)
{
    for(int i = 0; i < mat.GetNumRows(); i++)//перебираємо всі можливі пари скалярного добутку і перевіряємо чи він завжди 0
    {
        for(int j = 0; j < mat.GetNumRows(); j++)
        {
            if( i!=j && mat.matrix[i] * mat.matrix[j] != 0)
                return 0;
        }

    }
    return 1;
}
bool CheckOrto(Matrix mat)//об'єднуємо дві вимоги ортонормованості
{
    return CheckAllRow(mat) && CheckSameRow(mat);
}

int main()
{
    Matrix matrix;
    cout << "Enter the number of rows and the number of columns, and then the matrix " << endl;
    cin >> matrix;

    if ( CheckOrto(matrix) )
        cout <<endl<< "Orthonormal";
    else
        cout << endl<< "Not orthonormal";
    return 0;

    /*
     * Copy tests on command line
     1)
     1 0 0 0 0 0 0 0 0 0
     0 1 0 0 0 0 0 0 0 0
     0 0 1 0 0 0 0 0 0 0
     0 0 0 1 0 0 0 0 0 0
     0 0 0 0 1 0 0 0 0 0
     0 0 0 0 0 1 0 0 0 0
     0 0 0 0 0 0 1 0 0 0
     0 0 0 0 0 0 0 1 0 0
     0 0 0 0 0 0 0 0 1 0
     0 0 0 0 0 0 0 0 0 1
     resalt - orthonormal

     2)
     1 0 0 0 0 0 0 0 0 0
     0 1 0 0 0 0 0 0 0 0
     0 0 1 0 0 0 0 0 0 0
     0 0 0 1 0 0 0 0 0 0
     0 0 0 0 1 0 0 0 0 0
     0 0 0 0 0 1 0 0 0 0
     0 0 0 0 0 0 1 0 0 0
     0 0 0 0 0 0 0 1 0 0
     0 0 0 0 0 0 0 0 0 1
     0 0 0 0 0 0 0 0 0 1
     resalt - not orthonormal

     */
}
