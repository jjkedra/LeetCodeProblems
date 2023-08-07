from typing import List

class SudokuBoard:
    def __init__(self) -> None:
        pass

    @staticmethod
    def validate(board: List[List[str]]) -> bool:
        if (SudokuBoard.validate_size(board)
            and SudokuBoard.validate_row(board)
            and SudokuBoard.validate_col(board)
            and SudokuBoard.validate_box(board)):
            return True
        return False


    @staticmethod
    def validate_size(board: List[List[str]]) -> bool:
        if len(board) != 9:
            return False

        for row in board:
            if len(row) != 9:
                return False
        return True

    @staticmethod
    def validate_row(board: List[List[str]]) -> bool:
        for row in board:
            row_counter = dict()
            for entry in row:
                if entry != "." and entry in row_counter:
                    return False
                else:
                    row_counter[entry] = 1
        return True

    @staticmethod
    def validate_col(board: List[List[str]]) -> bool:
        for i in range(9):
            col_counter = dict()
            for j in range(9):
                entry = board[j][i]
                if entry != "." and entry in col_counter:
                    return False
                else:
                    col_counter[entry] = 1
        return True

    @staticmethod
    def validate_box(board: List[List[str]]) -> bool:
        BOX_START = [0, 3, 6]
        for i in BOX_START:
            for j in BOX_START:
                box_counter = dict()
                for a in range(3):
                    for b in range(3):
                        entry = board[a + i][b + j]
                        if entry != "." and entry in box_counter:
                            return False
                        else:
                            box_counter[entry] = 1
        return True

    @staticmethod
    def check_win(board: List[List[str]]) -> bool:
        if (SudokuBoard.validate(board) == False):
            return False

        for row in board:
            for entry in row:
                if entry < "1" or entry > "9":
                    return False
        return True
