HexPrint
========

[![Build Status](https://img.shields.io/travis/macmade/HexPrint.svg?branch=master&style=flat)](https://travis-ci.org/macmade/HexPrint)
[![Issues](http://img.shields.io/github/issues/macmade/HexPrint.svg?style=flat)](https://github.com/macmade/HexPrint/issues)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)
![License](https://img.shields.io/badge/license-bsd-brightgreen.svg?style=flat)
[![Contact](https://img.shields.io/badge/contact-@macmade-blue.svg?style=flat)](https://twitter.com/macmade)  
[![Donate-Patreon](https://img.shields.io/badge/donate-patreon-yellow.svg?style=flat)](https://patreon.com/macmade)
[![Donate-Gratipay](https://img.shields.io/badge/donate-gratipay-yellow.svg?style=flat)](https://www.gratipay.com/macmade)
[![Donate-Paypal](https://img.shields.io/badge/donate-paypal-yellow.svg?style=flat)](https://paypal.me/xslabs)

About
-----

HexPrint is a command line tool to display files content as hexadecimal.

The command is interactive and fills the available terminal space with the hexadecimal dump, along with ASCII data.  
Scrolling can be achieved with the arrow keys, `ctrl-d` or `ctrl-u`.

Usage
-----

    Usage: hexprint [options] <file>

    Options:

        --help, -h     Prints this help message

Example
-------

    ---------------------------------------------------------------
    File: <hexprint>
    Size: 14.84 KB
    ---------------------------------------------------------------
    000000000000000: CF FA ED FE 07 00 00 01 03 00 00 | ...........
    00000000000000B: 80 02 00 00 00 11 00 00 00 38 06 | .........8.
    000000000000016: 00 00 85 00 20 00 00 00 00 00 19 | ...........
    000000000000021: 00 00 00 48 00 00 00 5F 5F 50 41 | ...H...__PA
    00000000000002C: 47 45 5A 45 52 4F 00 00 00 00 00 | GEZERO.....
    000000000000037: 00 00 00 00 00 00 00 00 00 00 00 | ...........
    ---------------------------------------------------------------
    Press <q> to quit or navigate with the arrow keys:

License
-------

HexPrint is released under the terms of the BSD License.

Repository Infos
----------------

    Owner:			Jean-David Gadina - XS-Labs
    Web:			www.xs-labs.com
    Blog:			www.noxeos.com
    Twitter:		@macmade
    GitHub:			github.com/macmade
    LinkedIn:		ch.linkedin.com/in/macmade/
    StackOverflow:	stackoverflow.com/users/182676/macmade
