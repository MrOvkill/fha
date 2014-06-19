#
#    * Author: Samuel "MrOverkill" Meyers
#    * License: GPL v3
#    * Version: 0.3.0
#    * Date: 06/18/2014
#

import random

VERSION_MAJOR = 0
VERSION_MINOR = 3
REVISION = 0

thestr = {}

class Fha:
    def __init__(self, content):
        for i in range(0, len(content)):
            thestr[i] = content[i]
    def makeHash(self):
        hsh = {}
        stc = 0
        for i in range(0, len(thestr)):
            stc += ord(thestr[i])*i
        random.seed(stc+len(thestr))
        for i in range(0, len(thestr)):
            hsh[i] = chr(random.randint(33, 123))
        return hsh
