#include <QQmlEngine>
#include <QGuiApplication>

#include "Keyboard.hpp"

Keyboard::Keyboard(QObject* parent)
    :QObject (parent)
{
    QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

    keyValues << Qt::Key_7 << Qt::Key_8 << Qt::Key_9
              << Qt::Key_4 << Qt::Key_5 << Qt::Key_6
              << Qt::Key_1 << Qt::Key_2 << Qt::Key_3
              << Qt::Key_Backspace << Qt::Key_0 << Qt::Key_Enter;
    keyTexts << "7" << "8" << "9"
             << "4" << "5" << "6"
             << "1" << "2" << "3"
             << QString("") << "0" << QString("");
}

Keyboard::~Keyboard()
{

}

void Keyboard::postEvent(int index)
{
    QObject *obj = QGuiApplication::focusObject();
    if (obj){
        int key = keyValues.at(index);
        QString text = keyTexts.at(index);
        QKeyEvent* event = new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, text);
        qApp->postEvent(obj, event);
    }
}

QStringList Keyboard::keys()
{
    QStringList list;
    list << "7" << "8" << "9"
         << "4" << "5" << "6"
         << "1" << "2" << "3"
         << tr("删除") << "0" << tr("确定");
    return list;
}
