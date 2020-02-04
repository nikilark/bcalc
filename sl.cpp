#include "sl.h"

sl::sl(QObject *parent) : QObject(parent)
{
    this->X=0;
    this->Y=0;
}
sl::~sl(){}
void sl::touchStart(int x,int y){
    this->X=x;
    this->Y=y;
}
void sl::touchEnd(int x,int y){
    int diffX=this->X-x;
    int diffY=this->Y-y;
    if(diffY>=this->sizeY/5&&abs(diffX)<=this->sizeX/5){
        emit swipeUp();
    }
    else if(-diffY>=this->sizeY/5&&abs(diffX)<=this->sizeX/5){
        emit swipeDown();
    }
    else if(abs(diffY)<=this->sizeY/5&&diffX>=this->sizeX/5){
        emit swipeLeft();
    }
    else if(abs(diffY)<=this->sizeY/5&&-diffX>=this->sizeX/5){
        emit swipeRight();
    }
    else if(abs(diffX)<this->sizeX/10&&abs(diffY)<this->sizeY/10){
        if(X<this->sizeX/2)
            emit clicked0();
        else
            emit clicked1();
    }
}
int sl::getsizeX() const{
    return this->sizeX;
}
int sl::getsizeY() const{
    return this->sizeY;
}
void sl::setsizeX(const int & newX){
    this->sizeX=newX;
}
void sl::setsizeY(const int & newY){
    this->sizeY=newY;
}
