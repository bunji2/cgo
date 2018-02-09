# -*- coding: utf-8 -*-

import foo

def main():
    foo.helloworld()
    x = 111
    print "square(%d) = %d" % (x, foo.square(x))
    x, y = 123, 654
    print "add(%d, %d) = %d" % (x, y, foo.myadd(x, y))
    name = "DARK STAR"
    print foo.make_greet(name)
    x, y = 1000, 17
    ans, rem = foo.mydiv(x, y)
    print "%d / %d = %d ... %d" % (x, y, ans, rem)

if __name__ == "__main__":
    main()
