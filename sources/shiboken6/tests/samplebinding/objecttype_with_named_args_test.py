#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#############################################################################
##
## Copyright (C) 2016 The Qt Company Ltd.
## Contact: https://www.qt.io/licensing/
##
## This file is part of the test suite of Qt for Python.
##
## $QT_BEGIN_LICENSE:GPL-EXCEPT$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see https://www.qt.io/terms-conditions. For further
## information use the contact form at https://www.qt.io/contact-us.
##
## GNU General Public License Usage
## Alternatively, this file may be used under the terms of the GNU
## General Public License version 3 as published by the Free Software
## Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
## included in the packaging of this file. Please review the following
## information to ensure the GNU General Public License requirements will
## be met: https://www.gnu.org/licenses/gpl-3.0.html.
##
## $QT_END_LICENSE$
##
#############################################################################

import os
import sys
import unittest

from pathlib import Path
sys.path.append(os.fspath(Path(__file__).resolve().parents[1]))
from shiboken_paths import init_paths
init_paths()

from sample import ObjectType

class NamedArgsTest(unittest.TestCase):

    def testOneArgument(self):
        p = ObjectType()
        o = ObjectType(parent=p)
        self.assertEqual(o.parent(), p)

    def testMoreArguments(self):
        o = ObjectType()

        o.setObjectSplittedName("", prefix="pys", suffix="ide")
        self.assertEqual(o.objectName(), "pyside")

        o.setObjectSplittedName("", suffix="ide", prefix="pys")
        self.assertEqual(o.objectName(), "pyside")

        o.setObjectNameWithSize(name="pyside", size=6)
        self.assertEqual(o.objectName(), "pyside")

        o.setObjectNameWithSize(size=6, name="pyside")
        self.assertEqual(o.objectName(), "pyside")


    def testUseDefaultValues(self):
        o = ObjectType()

        o.setObjectNameWithSize(size=3)
        self.assertEqual(o.objectName(), "<un") # use name='unknown' default argument

        o.setObjectSplittedName("")
        self.assertEqual(o.objectName(), "<unknown>") # user prefix='<unk' and suffix='nown>'



if __name__ == '__main__':
    unittest.main()

