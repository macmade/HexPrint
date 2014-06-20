HexPrint
========

[![Build Status](https://travis-ci.org/macmade/HexPrint.svg?branch=master)](https://travis-ci.org/macmade/HexPrint)

About
-----

HexPrint is a command line tool that displays a file's content as an hexadecimal dump.

Documentation
-------------

### Features

HexPrint can be simply invoked by typing it's name, following by the path of the file to dump.  
For instance:

    hexprint /path/to/some/file

The result will look like this:

    0000000000: CF FA ED FE   07 00 00 01   03 00 00 00   01 00 00 00 | ................
    0000000016: 03 00 00 00   A0 01 00 00   00 20 00 00   00 00 00 00 | ......... ......
    0000000032: 19 00 00 00   38 01 00 00   00 00 00 00   00 00 00 00 | ....8...........
    0000000048: 00 00 00 00   00 00 00 00   00 00 00 00   00 00 00 00 | ................
    0000000064: E8 01 00 00   00 00 00 00   C0 01 00 00   00 00 00 00 | ................
    0000000080: E8 01 00 00   00 00 00 00   07 00 00 00   07 00 00 00 | ................
    0000000096: 03 00 00 00   00 00 00 00   5F 5F 74 65   78 74 00 00 | ........__text..
    0000000112: 00 00 00 00   00 00 00 00   5F 5F 54 45   58 54 00 00 | ........__TEXT..
    0000000128: 00 00 00 00   00 00 00 00   00 00 00 00   00 00 00 00 | ................
    0000000144: FA 00 00 00   00 00 00 00   C0 01 00 00   00 00 00 00 | ................
    0000000160: A8 03 00 00   10 00 00 00   00 04 00 80   00 00 00 00 | ................
    0000000176: 00 00 00 00   00 00 00 00   5F 5F 63 73   74 72 69 6E | ........__cstrin
    0000000192: 67 00 00 00   00 00 00 00   5F 5F 54 45   58 54 00 00 | g.......__TEXT..
    0000000208: 00 00 00 00   00 00 00 00   00 01 00 00   00 00 00 00 | ................
    0000000224: 91 00 00 00   00 00 00 00   C0 02 00 00   03 00 00 00 | ................
    0000000240: 00 00 00 00   00 00 00 00   02 00 00 00   00 00 00 00 | ................
    0000000256: 00 00 00 00   00 00 00 00   5F 5F 65 68   5F 66 72 61 | ........__eh_fra
    0000000272: 6D 65 00 00   00 00 00 00   5F 5F 54 45   58 54 00 00 | me......__TEXT..

You'll see the line offset, the hexadecimal data, and the ascii data.  
All of this can be configured. For the options, just see below.

### Usage

Here are the command line parameters that can be passed to HexPrint:

    -c [i] | --columns [i]
    The number of columns to display for the hexadecimal code (integer value)
    
    -g [i] | --group [i]
    Groups bytes by the given number (integer value)
    
    -a | --no-ascii
    Do not display the ASCII code
    
    -n | --no-lines
    Do not display the lines numbers
    
    -h | --help
    Print the help message
    
    -v | --version
    Print the version number
    
    -l | --license
    Print the license terms

License
-------

HexPrint is released under the terms of the Boost Software License - Version 1.0.

Repository Infos
----------------

    Owner:			Jean-David Gadina - XS-Labs
    Web:			www.xs-labs.com
    Blog:			www.noxeos.com
    Twitter:		@macmade
    GitHub:			github.com/macmade
    LinkedIn:		ch.linkedin.com/in/macmade/
    StackOverflow:	stackoverflow.com/users/182676/macmade
