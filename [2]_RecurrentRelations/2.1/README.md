[ENG] A sequence of s matrices A1, A2, ..., As is given. It is necessary to determine in what order they should be multiplied so that the number of atomic multiplication operations is minimal. The matrices are assumed to be compatible with respect to matrix multiplication (i.e. the number of columns of the matrix Ai − 1 coincides with the number of rows of the matrix Ai).

We assume that the product of matrices is an operation that takes two matrices of size k × m and m × n as input and returns a matrix of size k × n, spending kmn atomic multiplication operations on it. (The base type allows you to store any element of the final and any possible intermediate matrix, so multiplying two elements requires one atomic operation.)

Since matrix multiplication is associative, the resulting matrix does not depend on the order of multiplication operations. In other words, there is no difference in which order the brackets are placed between the multipliers, the result will be the same.

Input data format
The first line contains the number s of matrices (2 ≤ s ≤ 100). In the following s rows, the sizes of the matrices are set: row i + 1 contains, separated by a space, the number of ni rows and the number of mi columns of the matrix Ai (1 ≤ ni, mi ≤ 100). It is guaranteed that mi coincides with ni + 1 for all indices i from 1 to s − 1.

Output data format
Print the minimum number of atomic multiplication operations required to multiply s matrices.

[РУС] Дана последовательность из s матриц A1, A2, …, As. Требуется определить, в каком порядке их следует перемножать, чтобы число атомарных операций умножения было минимальным. Матрицы предполагаются совместимыми по отношению к матричному умножению (т. е. число столбцов матрицы Ai − 1 совпадает с числом строк матрицы Ai).

Будем считать, что произведение матриц — операция, которая принимает на вход две матрицы размера k × m и m × n и возвращает матрицу размера k × n, затратив на это kmn атомарных операций умножения. (Базовый тип позволяет хранить любой элемент итоговой и любой возможной промежуточной матрицы, поэтому умножение двух элементов требует одной атомарной операции.)

Так как перемножение матриц ассоциативно, итоговая матрица не зависит от порядка выполнения операций умножения. Другими словами, нет разницы, в каком порядке расставляются скобки между множителями, результат будет один и тот же.

Формат входных данных
В первой строке задано число s матриц (2 ≤ s ≤ 100). В последующих s строках заданы размеры матриц: строка i + 1 содержит через пробел число ni строк и число mi столбцов матрицы Ai (1 ≤ ni, mi ≤ 100). Гарантируется, что mi совпадает с ni + 1 для всех индексов i от 1 до s − 1.

Формат выходных данных
Выведите минимальное число атомарных операций умножения, необходимое для перемножения s матриц.
