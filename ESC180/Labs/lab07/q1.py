import numpy as np

def print_matrix(M_lol):
    M = np.array(M_lol)
    print(M)

def get_lead_ind(row):
    for i in range(len(row)-1):
        if row[i] != 0:
            return i
    return len(row)

def get_row_to_swap(M, start_i):
    min_i = get_lead_ind(M[start_i])
    for i in range(start_i, len(M)):
        if get_lead_ind(M[i]) < min_i:
            min_i = i
    return min_i

def add_rows_coefs(r1, c1, r2, c2):
    new = []
    for i in range(len(r1)):
        new.append(r1[i]*c1 + r2[i]*c2)
    return new

def eliminate(M, row_to_sub, best_lead_ind, is_backward):
    num = M[row_to_sub][best_lead_ind]
    if num != 0:
        if not is_backward:
            for i in range(row_to_sub + 1, len(M)):
                row = M[i]
                coeff = row[best_lead_ind] / num
                M[i] = add_rows_coefs(M[row_to_sub], -1*coeff, M[i], 1)
        else:
            for i in range(row_to_sub-1, -1, -1):
                row = M[i]
                coeff = row[best_lead_ind] / num
                M[i] = add_rows_coefs(M[row_to_sub], -1*coeff, M[i], 1)

def forward_step(M):
    for i in range(len(M)):
        ind = get_row_to_swap(M, i)
        M[i], M[ind] = M[ind], M[i]
        eliminate(M, i, get_lead_ind(M[i]), False)

def backward_step(M):
    for i in range(len(M)-1, -1, -1):
        eliminate(M, i, i, True)

def solve(M):
    initial = M[:]
    initial_without_b = []
    for i in M:
        initial_without_b.append(i[0:-1])

    forward_step(M)
    backward_step(M)
    for i in range(len(M)):
        if M[i][i] != 0:
            coeff = 1 / M[i][i]
            for j in range(len(M[i])):
                M[i][j] *= coeff
    print_matrix(M)

    x = []
    for i in M:
        x.append(i[-1])

    b = np.matmul(initial_without_b, x)
    print_matrix(b)


""" Problems 1-5
M = [[5, 6, 7, 8],
     [0, 0, 0, 1],
     [0, 0, 5, 2],
     [0, 1, 0, 0]]
print_matrix(M)
print(get_row_to_swap(M, 1))
print(add_rows_coefs(M[0], 2, M[2], 3))

M = [[5, 6, 7, 8],
     [0, 0, 1, 1],
     [0, 0, 5, 2],
     [0, 0, 7, 0]]

eliminate(M, 1, 2)
print_matrix(M)
"""
M = [[1,-2,3,22],
     [0,10,1,314],
     [1,5,3,92]]

solve(M)

