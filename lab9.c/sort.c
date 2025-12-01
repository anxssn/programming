//сортируем элементы матрицы по возрастанию
for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j ++){
        for(int k = j + 1; k < m; k ++){
            if(matrix[i][k] < matrix[i][j]){
                double temp = matrix[i][j];
                matrix[i][j] = matrix[i][k];
                matrix[i][k] = temp;
            }
        }
    }
}

