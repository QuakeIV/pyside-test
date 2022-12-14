// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef __PYSIDEWTYPES__
#define __PYSIDEWTYPES__

typedef struct HWND__ *HWND;
typedef unsigned UINT;
typedef long LONG;
typedef unsigned long DWORD;
typedef UINT WPARAM;
typedef LONG LPARAM;

struct POINT
{
    LONG x;
    LONG y;
};

struct MSG
{
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

#endif
