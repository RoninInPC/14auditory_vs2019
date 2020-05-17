#include<random>
#include <iostream>
#include<ctime>
#include <fstream>
using namespace std;
void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col, int **newMatrix) {
  int offsetRow = 0; 
  int offsetCol = 0; 
  for(int i = 0; i < size-1; i++) {
    if(i == row) {
      offsetRow = 1; 
    }
 
    offsetCol = 0;
    for(int j = 0; j < size-1; j++) {
      if(j == col) {
        offsetCol = 1; 
      }
 
      newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
    }
  }
}
int matrixDet(int** matrix, int size) {
	int det = 0;
	int degree = 1;

	if (size == 1) {
		return matrix[0][0];
	}
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	int** newMatrix = new int* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		newMatrix[i] = new int[size - 1];
	}
	for (int j = 0; j < size; j++) {
		getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);
		det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
		degree = -degree;
	}
	for (int i = 0; i < size - 1; i++) {
		delete[] newMatrix[i];
	}
	delete[] newMatrix;

	return det;
}
class Matrix {
public:
	int NumberString = 0;
	int NumberColumn = 0;
	int determinant = 0;
	int** Arr;
	void input() {
		srand(time(NULL));
		NumberString = rand() % 29 + 1;
		NumberColumn = rand() % 29 + 1;
		Arr = new int* [NumberString];
		for (int i = 0; i < NumberString; i++) {
			Arr[i] = new int[NumberColumn];
			for (int j = 0; j < NumberColumn; j++) {
				std::cin >> Arr[i][j];
			}
		}
	}
	void input(int rows, int column) {
		NumberString = rows;
		NumberColumn = column;
		Arr = new int* [NumberString];
		for (int i = 0; i < NumberString; i++) {
			Arr[i] = new int[NumberColumn];
			for (int j = 0; j < NumberColumn; j++) {
				std::cin >> Arr[i][j];
			}
		}
	}
	void generateRandom(int rows, int column) {
		NumberString = rows;
		NumberColumn = column;
		Arr = new int* [NumberString];
		for (int i = 0; i < NumberString; i++) {
			Arr[i] = new int[NumberColumn];
			for (int j = 0; j < NumberColumn; j++) {
				Arr[i][j] = rand() % 20;
			}
		}
	}
	void output() {
		for (int i = 0; i < NumberString; i++) {
			for (int j = 0; j < NumberColumn; j++) {
				std::cout << Arr[i][j] << ' ';
			}
			std::cout << "\n";
		}
	}
	void output(std::string FileName) {
		ofstream fout;
		fout.open(FileName);
		for (int i = 0; i < NumberString; i++) {
			for (int j = 0; j < NumberColumn; j++) {
				fout << Arr[i][j] << ' ';
			}
			fout << "\n";
		}
		fout.close();
	}
	void Determinant() {
		if (NumberColumn == NumberString) {
			determinant = matrixDet(Arr, NumberString);
		}
	}
};
int main() {
	Matrix Now;
	Now.generateRandom(20,20);
	Now.output();
	return 0;
}