#ifndef SWIPELISTENER_H
#define SWIPELISTENER_H

#include <QObject>

class swipeListener : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int sizeX READ getsizeX)
    Q_PROPERTY(int sizeY READ getsizeY)
private:
    int sizeX;
    int sizeY;
    int X;
    int Y;
public:
    explicit swipeListener(QObject *parent = nullptr);
    ~swipeListener();
    int getsizeX()const;
    int getsizeY()const;
signals:
   void swipeUp();
   void clicked0();
   void clicked1();
public slots:
   void touchStart(int x,int y);
   void touchEnd(int x,int y);
};

#endif // SWIPELISTENER_H
