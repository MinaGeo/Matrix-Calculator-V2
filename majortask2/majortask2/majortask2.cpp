#include <iostream>

#include <sstream>

#include <string>
#include <iomanip>
#include <vector>

#include <cstring>

using namespace std;

bool isNumber(const string& s) {

    if (s.empty()) {
        return false;
    }
    char c = s[0];
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c == '-') {
        return true;
    }
    else {
        return false;
    }

}

bool isMatrix(const string& s) {

    if (s.empty()) {
        return false;
    }
    if (s[0] == '[') {
        return true;
    }
    if (s[0] != '[') {
        return false;
    }

    return false;
}

bool isOperator(const string& s) {

    if (s.empty()) {
        return false;
    }
  
    if (s[0] == 'T' || s[0] == 'I' || s[0] == 'D') {
        return true;
    }
    return false;
}

double converttonumber(const string& s) {

    istringstream stream(s);

    double result;

    stream >> result;
    return result;
}

char ConvertToOperator(const string& s) {
    return s[0];

}

void ConvertToMatrix(string s, double C[100][100], int& rowCountC, int& colCountC) {
    int commaCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            commaCount++;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[6] == ',' && s[11] == ',') {
            cout << "ERROR!";
            exit(0);

        }
    }
    rowCountC = commaCount + 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',' || s[i] == '[' || s[i] == ']') {
            s[i] = ' ';
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[1] == ',' || s[1] == '[' || s[1] == ']') {
            cout << "ERROR!";
            exit(0);
        }
    }
    istringstream stream(s);
    int elementCount = 0;
    double element = 0;
    while (true) {
        stream >> element;
        if (stream) {
            elementCount++;
        }
        else {
            break;
        }
    }
    colCountC = elementCount / rowCountC;
    if (elementCount % rowCountC != 0) {
        cout << "ERROR!";
        exit(0);
    }

    stream = istringstream(s);
    for (int i = 0; i < rowCountC; i++) {

        for (int j = 0; j < colCountC; j++) {
            stream >> C[i][j];
        }
    }
}

bool Addition(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {


    int i, j;
    if (rowCountA == rowCountB && colCountA == colCountB) {
        rowCountC = rowCountA;
        colCountC = colCountA;
        for (i = 0; i < rowCountA; i++) {
            for (j = 0; j < colCountA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool Subtraction(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;
    if (rowCountA == rowCountB && colCountA == colCountB) {
        rowCountC = rowCountA;
        colCountC = colCountA;
        for (i = 0; i < rowCountA; i++) {
            for (j = 0; j < colCountA; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void MutliplyByScalar(double A[100][100], int rowCountA, int colCountA, double multiplier,
    double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;
    rowCountC = rowCountA;
    colCountC = colCountA;
    for (i = 0; i < rowCountA; i++) {
        for (j = 0; j < colCountA; j++) {
            C[i][j] = A[i][j] * multiplier;
        }
    }
}

bool Transpose(double A[100][100], int rowCountA, int colCountA, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;

    rowCountC = colCountA;
    colCountC = rowCountA;
    for (i = 0; i < colCountA; i++) {
        for (j = 0; j < rowCountA; j++) {
            C[i][j] = A[j][i];
        }
    }
    return true;
}

bool MultiplyMatrices(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {
    if (colCountA != rowCountB) {

        return false;
    }
    rowCountC = rowCountA;
    colCountC = colCountB;
    for (int i = 0; i < rowCountC; i++) {
        for (int j = 0; j < colCountC; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colCountA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

void PrintMatrices(double C[100][100], int rowCountC, int colCountC) {
    cout << "[";
    for (int i = 0; i < rowCountC; i++) {
        for (int j = 0; j < colCountC; j++) {

           trunc( C[i][j])*100;
           cout << C[i][j] / 100;
            if (j != colCountC - 1) {
                cout << " ";
            }
            if (j == colCountC - 1 && i != rowCountC - 1) {
                cout << ", ";
            }
        }
    }
    cout << "]";
}


bool Transpose(double A[100][100], int rowCountA, int colCountA, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;

    rowCountC = colCountA;
    colCountC = rowCountA;
    for (i = 0; i < colCountA; i++) {
        for (j = 0; j < rowCountA; j++) {
            C[i][j] = A[j][i];
        }
    }
    return true;
}



bool Inverse(double A[100][100], int rowCountA, int colCountA, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;
    float Deter = 0;
    float correction = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            Deter += (A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]))) - (A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])))
                + (A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));

        }
    }
    correction = Deter / 9.00;
    rowCountC = rowCountA;
    colCountC = colCountA;
    for (i = 0; i < rowCountA; i++) {
        for (j = 0; j < colCountA; j++) {
            C[0][0] = ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1])) / correction;
            C[0][1] = -1 * ((A[0][1] * A[2][2]) - (A[0][2] * A[2][1])) / correction;
            C[0][2] = ((A[0][1] * A[1][2]) - (A[0][2] * A[1][1])) / correction;
            C[1][0] = -1 * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])) / correction;
            C[1][1] = ((A[0][0] * A[2][2]) - (A[0][2] * A[2][0])) / correction;
            C[1][2] = -1 * ((A[0][0] * A[1][2]) - (A[0][2] * A[1][0])) / correction;
            C[2][0] = ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])) / correction;
            C[2][1] = -1 * ((A[0][0] * A[2][1]) - (A[0][1] * A[2][0])) / correction;
            C[2][2] = ((A[0][0] * A[1][1]) - (A[0][1] * A[1][0])) / correction;
        }
    }
    return true;
}


void makeSmallerMatrix(int A[100][100], int tempC[100][100], int dimensionmxm, int cols)//cancelled row is always 0
{
    //dim is dimension of starting matrix
    for (int i = 1; i < dimensionmxm; i++)
    {
        int col = 0;
        for (int j = 0; j < dimensionmxm; j++)
        {
            if (j == cols)
                continue;

            tempC[i - 1][col] = A[i][j];
            col++;
        }
    }
}

double Determinant(double A[100][100], int rowCountA) {
    double Deter = 0;
    double TempC[100][100];

    for (int i = 0; i < rowCountA; i++)
    {
        int TempCrowCount = 0;//
        for (int j = 0; j < rowCountA; j++)//
            //
        {
            int TempCcolCount = 0;//

            for (int k = 0; k < rowCountA; k++)//
            {
                if (k == i) {
                    continue;
                }
                TempC[TempCrowCount][TempCcolCount] = A[j][k];//
                TempCcolCount++;//
            }
            TempCrowCount++; //++
        }
        Deter = Deter + (pow(-1, i) * A[0][i] * Determinant(TempC, rowCountA - 1)); // 0+new Deter
    }

    return Deter;
}

int main() {

    double multiplier = 0;
    const int MAX_ROW_COUNT = 100;
    const int MAX_COLUMN_COUNT = 100;
    int rowCountA, colCountA, rowCountB, colCountB, rowCountC, colCountC, Det = 0;
    double a[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    double b[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    double c[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    char operation;

    string line1, line2, line3;
    getline(cin, line1);
    getline(cin, line2);
    if (line2 == "+" || line2 == "-" || line2 == "*") {
        getline(cin, line3);
    }

    if (isMatrix(line1) == true) {}
    else {
        cout << "ERROR!" << endl;
        return 0;
    }
    if (isOperator(line2)) {
        operation = ConvertToOperator(line2);
    }
    else {
        cout << "ERROR!" << endl;
        return 0;
    }
    if (operation == '*') {

        if (isNumber(line1) && isMatrix(line3)) {
            multiplier = converttonumber(line1);
            ConvertToMatrix(line3, a, rowCountA, colCountA);
            MutliplyByScalar(a, rowCountA, colCountA, multiplier, c, rowCountC, colCountC);
        }
        else if (isNumber(line3) && isMatrix(line1)) {
            multiplier = converttonumber(line3);
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            MutliplyByScalar(a, rowCountA, colCountA, multiplier, c, rowCountC, colCountC);
        }
        else if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);

            bool isinputvalid = MultiplyMatrices(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);
            if (isinputvalid == true) {

            }
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
        else {

            cout << "ERROR!" << endl;
            return 0;
        }

    }

    if (operation == '+') {
        if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);
            bool isinputvalid = Addition(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);
            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }


    if (operation == '-') {
        if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);
            bool isinputvalid = Subtraction(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);

            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
        else {
            cout << "ERROR!" << endl;
            return 0;
        }
    }
    if (operation == 'T') {

        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);

            bool isinputvalid = Transpose(a, rowCountA, colCountA, c, rowCountC, colCountC);
            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    if (operation == 'I') {
        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            bool isinputvalid = Inverse(a, rowCountA, colCountA, c, rowCountC, colCountC);

            if (isinputvalid == true) {
            }
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }

    }
    if (operation == 'D') {
        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);

           cout<< Determinant(a, rowCountA);
        }
        

    }
    else {
        PrintMatrices(c, rowCountC, colCountC);
    }
}
