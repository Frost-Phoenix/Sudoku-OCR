# take a txt file from https://github.com/grantm/sudoku-exchange-puzzle-bank
# and convert it to appropriate format. Output in boards directory.

import os
import sys


def print_board(board):
    for l in board:
        print(l)

def save(path, board):
    with open(path, "w+") as file:
        for l in board:
            file.writelines(l)

def convert(path: str, out: str, nb: int):
    file = open(path, "r")

    for l, line in enumerate(file.readlines()):
        if l >= nb: break
        board = line.split(" ")[1].replace("0", ".")
        new_format = []
        for i in range(9):
            j = i * 9
            new_format.append(board[j:j+3] + " " + board[j+3:j+6] + " " + board[j+6:j+9] + "\n")
            if i == 2 or i == 5: new_format.append("\n")
        save(f"{out}/grid_{l:03}", new_format)
    
    file.close()
    

if __name__ == "__main__":
    if len(sys.argv) < 4: 
        print("missing arguments...")
        sys.exit()
    path, out, nb = sys.argv[1], sys.argv[2], sys.argv[3]
    if not os.path.isfile(path): 
        print("file: " + path + " not found")
        sys.exit()
    convert(path, out, int(nb))
