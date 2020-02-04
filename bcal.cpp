#include "bcal.h"

bcal::bcal(QObject *parent) : QObject(parent)
{
    this->current=0;
    this->act='+';
}
bcal::~bcal(){}
void bcal::recdigit(int s){
    this->current+=s;
    emit senddigit();
}
int bcal::getcurrent() const{
    return this->current;
}
