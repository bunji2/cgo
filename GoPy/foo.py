# -*- coding: utf-8 -*-

# void -> void
def helloworld():
    print "Hello, world."

# int -> int
def square(x):
    return x*x

# (int, int) -> int
def myadd(x, y):
    return x+y

# string -> string
def make_greet(x):
    return "Hello, %s!" % (x)

# (int,int) -> (int, int)
def mydiv(x, y):
    answer = x/y
    remainder = x%y
    return answer, remainder

def main():
    helloworld()
    x = 111
    print "square(%d) = %d" % (x, square(x))
    x, y = 123, 654
    print "add(%d, %d) = %d" % (x, y, myadd(x, y))
    name = "DARK STAR"
    print make_greet(name)
    x, y = 1000, 17
    ans, rem = mydiv(x, y)
    print "%d / %d = %d ... %d" % (x, y, ans, rem)

#if __name__ == "__main__":
#    main()