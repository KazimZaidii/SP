import numpy as np

def find_subMatrix(input_matrix, r, c, matrix):
    for i in range(len(matrix) - r + 1):
        for j in range(len(matrix[0]) - c + 1):
            temp_mat = []
            for ki in range(i, r + i):
                temp_row = []
                for kj in range(j, c + j):
                    temp_row.append(matrix[ki][kj])
                temp_mat.append(temp_row)
            temp_mat = np.asanyarray(temp_mat)
            if np.array_equal(temp_mat,input_matrix):
                return True
    return False

array = np.asarray([[1,2,3,4,5,6,7,8], #1st row
                    [9,10,11,12,13,14,15,16],
                    [17,18,19,20,21,22,23,24],
                    [25,26,27,28,29,30,31,32],
                    [33,34,35,36,37,38,39,40],
                    [41,42,43,44,45,46,47,48],
                    [49,50,51,52,53,54,55,56],
                    [57,58,59,60,61,62,63,64],
              ])
def main():
    row = input("Enter first row of the square matrix(use space for separation): ")
    row = row.split(" ")
    row2 = input("Enter second row of the square matrix(use space for separation): ")
    row2 = row2.split(" ")
    tmp = []
    tmp.append(row)
    tmp.append(row2)
    input_matrix = np.asanyarray(tmp,dtype=int)
    print(input_matrix)

    if find_subMatrix(input_matrix,2,2,array):
        print("Input Matrix found in the Original Matrix")
    else:
        print("Matrix not found")

if __name__ == '__main__':
    main()
