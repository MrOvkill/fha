#
#    * Author: Samuel "MrOverkill" Meyers
#    * License: GPL v3
#    * Version: 0.3.0
#    * Date: 06/18/2014
#

import fha, sys

argc = len(sys.argv)

if argc < 2:
    print "Usage: {} <file>".format(sys.argv[0])
else:
    f = open(sys.argv[1], "r")
    fh = fha.Fha(list(f.read()))
    f.close()
    hsh = fh.makeHash()
    string = ""
    for i in range(0, len(hsh)):
        string += hsh[i]
    print string
