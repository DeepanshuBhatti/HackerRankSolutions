# Function to Print Rangoli


def print_rangoli(size):
    row_size = col_size = 2*size - 1
    alphabet_start = 97 + size - 1
    for i in range(0, col_size):
        line_string = ''
        alp = alphabet_start
        if i < col_size/2:
            for j in range(0, row_size):
                counter = int(row_size/2) - i
                if counter <= j and j + counter < row_size:
                    line_string += chr(alp)
                    if j >= int(row_size/2):
                        alp += 1
                    else:
                        alp -= 1
                else:
                    line_string += '-'
                if j < row_size - 1:
                    line_string += '-'
        else:
            for j in range(0, row_size):
                counter = i - size + 1
                if counter <= j and j + counter < row_size:
                    line_string += chr(alp)
                    if j >= int(row_size/2):
                        alp += 1
                    else:
                        alp -= 1
                else:
                    line_string += '-'
                if j < row_size - 1:
                    line_string += '-'
        print(line_string)


def main():
    print_rangoli(7)
    print_rangoli(4)


if __name__ == '__main__':
    main()
