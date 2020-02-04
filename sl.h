#ifndef SL_H
#define SL_H

#include <QObject>

class sl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int sizeX READ getsizeX WRITE setsizeX)
    Q_PROPERTY(int sizeY READ getsizeY WRITE setsizeY)
private:
    int sizeX;
    int sizeY;
    int X;
    int Y;
public:
    explicit sl(QObject *parent = nullptr);
    ~sl();
    int getsizeX()const;
    int getsizeY()const;
    void setsizeX(const int&);
    void setsizeY(const int&);
signals:
   void swipeUp();
   void swipeDown();
   void swipeRight();
   void swipeLeft();
   void clicked0();
   void clicked1();
public slots:
   void touchStart(int x,int y);
   void touchEnd(int x,int y);
};

#endif // SL_H
