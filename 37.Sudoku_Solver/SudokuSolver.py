import random
from typing import List, Tuple
from SudokuBoard import SudokuBoard
from utils import intersection

class SudokuSolver:
    def __init__(self, board: List[List[str]]) -> None:
        int_board = list()
        for row in board:
            int_row = list()
            for entry in row:
                if entry >= "1" and entry <= "9":
                    int_row.append(int(entry))
                else:
                    int_row.append(0)
            int_board.append(int_row)
        # Can't be bothered to play with strings 0 means empty field
        self.board = int_board
        self.board_reset = int_board
        self.VALID_INPUTS = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    def find_empty_cells(self) -> List[Tuple[int, int]]:
        result = list()
        for bix, row in enumerate(self.board):
            for rix, entry in enumerate(row):
                if entry == 0:
                    result.append(tuple([bix, rix]))
        return result

    def backtrack(self) -> bool:
        empty_cells = self.find_empty_cells()
        if len(empty_cells) == 0:
            return True
        current_cell = self.find_empty_cells()[0]
        for input in self.valid_inputs(current_cell):
            self.fill_cell(current_cell, input)
            if self.backtrack():
                return True
            self.fill_cell(current_cell, 0)
        return False

    def valid_inputs(self, cell: Tuple[int, int]) -> List[int]:
        row = cell[0]
        col = cell[1]
        return intersection(self.valid_input_row(row), self.valid_input_col(col), self.valid_input_box(cell))

    def valid_input_row(self, row: int) -> List[int]:
        result = self.VALID_INPUTS.copy()
        for entry in self.board[row]:
            if entry > 0:
                result.remove(entry)
        return result

    def valid_input_col(self, col: int) -> List[int]:
        result = self.VALID_INPUTS.copy()
        for i in range(9):
            entry = self.board[i][col]
            if entry > 0:
                result.remove(entry)
        return result

    def valid_input_box(self, cell: Tuple[int, int]) -> List[int]:
        BOX_START = [0, 3, 6]
        result = self.VALID_INPUTS.copy()

        box_row_index = cell[0] // 3
        box_col_index = cell[1] // 3

        box_row_start = BOX_START[box_row_index]
        box_col_start = BOX_START[box_col_index]

        for i in range(3):
            for j in range(3):
                entry = self.board[i + box_row_start][j + box_col_start]
                if entry > 0:
                    result.remove(entry)
        return result

    def fill_cell(self, cell: Tuple[int, int], value: int) -> bool:
        """
        Fills given cell on a board, returns true if cell was empty on fill, false if it had value

            Parameters:
                cell    (tuple[int, int]): coords of a cell (row, col)
                value   (int): value to which change the cell

            Returns:
                bool
        """
        for bix, row in enumerate(self.board):
            for rix, entry in enumerate(row):
                if bix == cell[0] and rix == cell[1]:
                    self.board[bix][rix] = value
                    return True
        return False

    def stringify_board(self) -> List[List[str]]:
        s_board = list()
        for row in self.board:
            s_row = list()
            for entry in row:
                if entry == 0:
                    s_row.append(".")
                else:
                    s_row.append(str(entry))
            s_board.append(s_row)
        return s_board

board =[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
solver = SudokuSolver(board)
solver.backtrack()
print(solver.stringify_board())