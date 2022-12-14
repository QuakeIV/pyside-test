# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

'''Script to show the difference between PyQt5 and ours'''

import sys

from color import print_colored


def check_module_diff(module_name):
    '''Difference between PySide6 and PyQt5 versions of qt bindings.
    Returns a tuple with the members present only on PySide6 and only on PyQt5'''
    shiboken_module = getattr(__import__('PySide6.' + module_name), module_name)
    orig_module = getattr(__import__('PyQt5.' + module_name), module_name)

    shiboken_set = set(dir(shiboken_module))
    orig_set = set(dir(orig_module))

    return sorted(shiboken_set - orig_set), sorted(orig_set - shiboken_set)


def main(argv=None):
    if argv is None:
        argv = sys.argv

    module_name = argv[1] if len(argv) >= 2 else 'QtCore'

    only_shiboken, only_orig = check_module_diff(module_name)

    print_colored('Only on Shiboken version')
    print(only_shiboken)

    print_colored('Only on SIP version')
    print(only_orig)


if __name__ == '__main__':
    main()
