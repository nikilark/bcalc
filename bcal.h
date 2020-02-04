#ifndef BCAL_H
#define BCAL_H

#include <QObject>

class bcal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int current READ getcurrent)
private:
    int current;
    char act;
public:
    explicit bcal(QObject *parent = nullptr);
    ~bcal();
    int getcurrent()const;
signals:
void senddigit();
public slots:
void recdigit(int);
};

#endif // BCAL_H
