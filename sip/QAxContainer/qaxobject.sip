// This is the SIP interface definition for QAxObject.
//
// Copyright (c) 2013 Riverbank Computing Limited <info@riverbankcomputing.com>
// 
// This file is part of PyQt5.
// 
// This file may be used under the terms of the GNU General Public License
// version 3.0 as published by the Free Software Foundation and appearing in
// the file LICENSE included in the packaging of this file.  Please review the
// following information to ensure the GNU General Public License version 3.0
// requirements will be met: http://www.gnu.org/copyleft/gpl.html.
// 
// If you do not wish to use this file under the terms of the GPL version 3.0
// then you may purchase a commercial license.  For more information contact
// info@riverbankcomputing.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


%If (WS_WIN)

class QAxObject : QObject, QAxBase /PyQt4NoQMetaObject/
{
%TypeHeaderCode
#include <qaxobject.h>
%End

public:
    QAxObject(QObject *parent /TransferThis/ = 0);
    QAxObject(const QString &, QObject *parent /TransferThis/ = 0);
    //QAxObject(IUnknown *, QObject *parent /TransferThis/ = 0);
    ~QAxObject();

%ConvertToSubClassCode
    static struct class_graph {
        const char *name;
        sipWrapperType **type;
        int yes, no;
    } graph[] = {
        {sipName_QAxObject, &sipClass_QAxObject,    1, -1},
        {sipName_QAxWidget, &sipClass_QAxWidget,    -1, -1},
    };

    int i = 0;

    sipClass = NULL;

    do
    {
        struct class_graph *cg = &graph[i];

        if (cg->name != NULL && sipCpp->inherits(cg->name))
        {
            sipClass = *cg->type;
            i = cg->yes;
        }
        else
            i = cg->no;
    }
    while (i >= 0);
%End

    bool doVerb(const QString &);

protected:
    void connectNotify(const QMetaMethod &);
};

%End
