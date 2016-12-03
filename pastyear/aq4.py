#!/usr/bin/python

import sys

def magic(x, y):
    if (x >= y):
        return 
    else:
        sys.stdout.write(str(x) + ' ')
        magic(x + 3, y);
    pass

magic(0, 10)
magic(1, 11)
