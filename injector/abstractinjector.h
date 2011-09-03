/*
  abstractinjector.h

  This file is part of Endoscope, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2011 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krauss@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ABSTRACTINJECTOR_H
#define ABSTRACTINJECTOR_H
#include <QtCore/qsharedpointer.h>

class QString;
class QStringList;

namespace Endoscope {

class AbstractInjector
{
  public:
    typedef QSharedPointer<AbstractInjector> Ptr;
    virtual ~AbstractInjector();

    /**
     * Launch the application @p program and inject @p probeDll and call @p probeFunc on it.
     */
    virtual int launch( const QStringList &programAndArgs, const QString &probeDll, const QString &probeFunc );

    /**
     * Attach to the running application with process id @p pid and inject @p probeDll and call @p probeFunc on it.
     */
    virtual bool attach( int pid, const QString &probeDll, const QString &probeFunc );
};

}

#endif // ABSTRACTINJECTOR_H