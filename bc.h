#ifndef BC_H
#define BC_H

#include <QObject>

class bc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int current READ getcurrent WRITE setcurrent)
    Q_PROPERTY(QString act READ getact WRITE setact)
private:
    int current;
    QString act;
public:
    explicit bc(QObject *parent = nullptr);
    ~bc();
    int getcurrent()const;
    void setcurrent(const int &);
    QString getact() const;
    void setact(const QString &);
signals:
void senddigit();
void actChanged();
public slots:
void recdigit(int);
};


#endif // BC_H
