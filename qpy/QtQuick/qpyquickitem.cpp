// This is the implementation of the QPyQuickItem classes.
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


#include <Python.h>

#include <QQmlListProperty>

#include "qpyquickitem.h"

#include "sipAPIQtQuick.h"


// The maximum number of Python QQuickItem types.
const int NrOfQuickItemTypes = 20;

// The list of registered Python types.
static QList<PyTypeObject *> pyqt_types;

// The registration data for the canned types.
static QQmlPrivate::RegisterType canned_types[NrOfQuickItemTypes];


#define QPYQUICKITEM_INIT(n) \
    case n##U: \
        QPyQuickItem##n::staticMetaObject = *mo; \
        rt->typeId = qRegisterNormalizedMetaType<QPyQuickItem##n *>(ptr_name); \
        rt->listId = qRegisterNormalizedMetaType<QQmlListProperty<QPyQuickItem##n> >(list_name); \
        rt->objectSize = sizeof(QPyQuickItem##n); \
        rt->create = QQmlPrivate::createInto<QPyQuickItem##n>; \
        rt->metaObject = mo; \
        rt->attachedPropertiesFunction = QQmlPrivate::attachedPropertiesFunc<QPyQuickItem##n>(); \
        rt->attachedPropertiesMetaObject = QQmlPrivate::attachedPropertiesMetaObject<QPyQuickItem##n>(); \
        rt->parserStatusCast = QQmlPrivate::StaticCastSelector<QPyQuickItem##n,QQmlParserStatus>::cast(); \
        rt->valueSourceCast = QQmlPrivate::StaticCastSelector<QPyQuickItem##n,QQmlPropertyValueSource>::cast(); \
        rt->valueInterceptorCast = QQmlPrivate::StaticCastSelector<QPyQuickItem##n,QQmlPropertyValueInterceptor>::cast(); \
        break


// The ctor.
QPyQuickItem::QPyQuickItem(QQuickItem *parent) : sipQQuickItem(parent)
{
}


// Add a new Python type and return its number.
QQmlPrivate::RegisterType *QPyQuickItem::addType(PyTypeObject *type,
        const QMetaObject *mo, const QByteArray &ptr_name,
        const QByteArray &list_name)
{
    int type_nr = pyqt_types.size();

    // Check we have a spare canned type.
    if (type_nr >= NrOfQuickItemTypes)
    {
        PyErr_Format(PyExc_TypeError,
                "a maximum of %d QQuickItem types may be registered with QML",
                NrOfQuickItemTypes);
        return 0;
    }

    pyqt_types.append(type);

    QQmlPrivate::RegisterType *rt = &canned_types[type_nr];

    // Initialise those members that depend on the C++ type.
    switch (type_nr)
    {
        QPYQUICKITEM_INIT(0);
        QPYQUICKITEM_INIT(1);
        QPYQUICKITEM_INIT(2);
        QPYQUICKITEM_INIT(3);
        QPYQUICKITEM_INIT(4);
        QPYQUICKITEM_INIT(5);
        QPYQUICKITEM_INIT(6);
        QPYQUICKITEM_INIT(7);
        QPYQUICKITEM_INIT(8);
        QPYQUICKITEM_INIT(9);
        QPYQUICKITEM_INIT(10);
        QPYQUICKITEM_INIT(11);
        QPYQUICKITEM_INIT(12);
        QPYQUICKITEM_INIT(13);
        QPYQUICKITEM_INIT(14);
        QPYQUICKITEM_INIT(15);
        QPYQUICKITEM_INIT(16);
        QPYQUICKITEM_INIT(17);
        QPYQUICKITEM_INIT(18);
        QPYQUICKITEM_INIT(19);
    }

    return rt;
}


// Create the Python instance.
void QPyQuickItem::createPyObject(QQuickItem *parent)
{
    SIP_BLOCK_THREADS

    // Assume C++ owns everything.
    PyObject *obj = sipConvertFromNewPyType(this, pyqt_types.at(typeNr()),
            NULL, &sipPySelf, "D", parent, sipType_QQuickItem, NULL);

    if (!obj)
        PyErr_Print();

    SIP_UNBLOCK_THREADS
}


// The canned type implementations.
#define QPYQUICKITEM_IMPL(n) \
QPyQuickItem##n::QPyQuickItem##n(QQuickItem *parent) : QPyQuickItem(parent) \
{ \
    createPyObject(parent); \
} \
QMetaObject QPyQuickItem##n::staticMetaObject


QPYQUICKITEM_IMPL(0);
QPYQUICKITEM_IMPL(1);
QPYQUICKITEM_IMPL(2);
QPYQUICKITEM_IMPL(3);
QPYQUICKITEM_IMPL(4);
QPYQUICKITEM_IMPL(5);
QPYQUICKITEM_IMPL(6);
QPYQUICKITEM_IMPL(7);
QPYQUICKITEM_IMPL(8);
QPYQUICKITEM_IMPL(9);
QPYQUICKITEM_IMPL(10);
QPYQUICKITEM_IMPL(11);
QPYQUICKITEM_IMPL(12);
QPYQUICKITEM_IMPL(13);
QPYQUICKITEM_IMPL(14);
QPYQUICKITEM_IMPL(15);
QPYQUICKITEM_IMPL(16);
QPYQUICKITEM_IMPL(17);
QPYQUICKITEM_IMPL(18);
QPYQUICKITEM_IMPL(19);
