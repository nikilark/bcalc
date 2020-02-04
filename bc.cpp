#include "bc.h"
#include <cmath>
bc::bc(QObject *parent) : QObject(parent)
{
    this->current=0;
    this->act="+";
}
bc::~bc(){}
void bc::recdigit(int s){
    if(this->current!=0){
    if(this->act=="+")
        this->current+=s;
    else if(this->act=="-")
        this->current-=s;
    else if(this->act=="*")
        this->current*=s;
    else if(this->act=="/")
        this->current/=s;
    else if(this->act=="^")
        this->current=pow(this->current,s);
    }
    else
        this->current=s;
    emit senddigit();
}
int bc::getcurrent() const{
    return this->current;
}
void bc::setcurrent(const int & newC){
    this->current=newC;
}
QString bc::getact() const{
    return this->act;
}
void bc::setact(const QString & newa){
    this->act=newa;
    emit this->actChanged();
}
