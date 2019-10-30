#ifndef FIXEDDATASOURCE_H
#define FIXEDDATASOURCE_H
#include "datasourceinteface.h"

class FixedDataSource : public DataSource
{
public:
    FixedDataSource();
    ~FixedDataSource();
    QHash<QPointF, MetaData> *GetData(const QLineF& line) override;
private:
    QHash<QPointF,MetaData> *fixedData;
    bool IsPointClose(const QPointF& point,const QLineF& line);
};

#endif // FIXEDDATASOURCE_H
