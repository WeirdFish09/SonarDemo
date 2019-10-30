#ifndef DATASOURCEINTEFACE_H
#define DATASOURCEINTEFACE_H
#include <QHash>
#include <QPoint>
#include <QColor>
#include <QLine>
struct MetaData{
    QColor color;
};

inline uint qHash(const QPointF &key)
{
    return (key.x() * 997) + key.y();
}

class DataSource{
public:
    virtual QHash<QPointF,MetaData>* GetData(const QLineF &line) =0;
};



#endif // DATASOURCEINTEFACE_H
