#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <QMap>
#include <QObject>
#include <QKeyEvent>
#include <QStringList>

class Keyboard:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList keys READ keys CONSTANT)
public:
    Keyboard(QObject *parent = Q_NULLPTR);
    ~Keyboard();

    /**
     * @brief 事件投递
     * @param index 事件索引
     */
    Q_INVOKABLE void postEvent(int index);
private:
    QStringList keys();
private:
    QList<int> keyValues;
    QList<QString> keyTexts;
};

#endif
