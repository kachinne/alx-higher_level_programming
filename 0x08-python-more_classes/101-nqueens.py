import sys

def is_safe(board, row, col):
    
    
    for i in range(row):
        if board[i][col] == 'Queen':
            return False

    
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Queen':
            return False

    
    for i, j in zip(range(row, -1, -1), range(col, N)):
        if board[i][j] == 'Queen':
            return False

    return True

def solve_nqueens(N):
    if N < 4:
        return []

    def backtrack(row):
        if row == N:
            solutions.append([''.join(row) for row in board])
            return

        for col in range(N):
            if is_safe(board, row, col, N):
                board[row][col] = 'Queen'
                backtrack(row + 1)
                board[row][col] = '.'

    solutions = []
    board = [['.' for _ in range(N)] for _ in range(N)]
    backtrack(0)
    return solutions

def print_solutions(N):
    solutions = solve_nqueens(N)
    for solution in solutions:
        for row in solution:
            print(row)
        print()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        if N < 4:
            print("N must be at least 4")
            sys.exit(1)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    print_solutions(N)
