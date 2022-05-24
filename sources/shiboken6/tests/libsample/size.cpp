// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0

#include <iostream>
#include "size.h"

using namespace std;

void
Size::show() const
{
    cout << "(width: " << m_width << ", height: " << m_height << ")";
}

