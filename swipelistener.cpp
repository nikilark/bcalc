#include "swipelistener.h"

swipeListener::swipeListener(QObject *parent) : QObject(parent)
{
    this->X=0;
    this->Y=0;
}
swipeListener::~swipeListener(){}
void swipeListener::touchStart(int x,int y){
    this->X=x;
    this->Y=y;
}
void swipeListener::touchEnd(int x,int y){
    int diffX=x-this->X;
    int diffY=y-this->Y;
    if(diffY>=this->sizeY/5&&diffX<=this->sizeX/5){
        emit swipeUp();
    }
    else if(this->X==x&&this->Y==y){
        if(X<this->sizeX/2)
            emit clicked0();
        else
            emit clicked1();
    }
}
int swipeListener::getsizeX() const{
    return this->sizeX;
}
int swipeListener::getsizeY() const{
    return this->sizeY;
}
