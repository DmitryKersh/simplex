# Simplex-method

  Program allows you to solve optimization tasks using simplex method

## Sample input
    10x1 + 12x2 + 8x3 => max
    3
    3x1 + 4x2 + 2x3 <= 1020
    4x1 + 3x2 + 3x3 <= 940
    5x1 + 3x2 + 5x3 <= 1010

or

    6x1 + 6x2 + 6x3 => max
    3
    4x1 + x2 + x3 <= 5
    x1 + 2x2 <= 3
    x2 + 8x3 <= 16
    
or

    5x1 + 6x2 + x3 => max
    3
    2x1 + x2 + x3 <= 5
    x1 + 2x2 <= 3
    x2 + 2x3 <= 16
    
or

    8x1 + 6x2 + 2x3 => max
    3
    2x1 + x2 + x3 <= 4
    x1 + 4x2 <= 3
    x2 + 2x3 <= 12
    
    # output:
    Function = 116/7
    x1= 13/7; x2= 2/7; x3= 82/7;