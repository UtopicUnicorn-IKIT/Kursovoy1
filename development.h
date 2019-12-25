#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include "QString"
struct Develop
{
    QString UserName;
    QString Password;
    QString Name;
    QString Group;
};

QDataStream &operator <<(QDataStream &out, const Develop &any);
QDataStream &operator >>(QDataStream &out, Develop &any);
class Development
{
public:
    Development();
};

#endif // DEVELOPMENT_H
