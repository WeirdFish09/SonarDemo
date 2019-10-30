#include "fixeddatasource.h"
#include <math.h>
#include <stdlib.h>

FixedDataSource::FixedDataSource()
{
    fixedData = new QHash<QPointF,MetaData>();
    fixedData->insert(QPointF(75,50), MetaData{Qt::red});
    fixedData->insert(QPointF(50,-25), MetaData{Qt::red});
    fixedData->insert(QPointF(-50,75), MetaData{Qt::red});
    fixedData->insert(QPointF(-50,-50), MetaData{Qt::red});
}

FixedDataSource::~FixedDataSource()
{
    delete fixedData;
}

QHash<QPointF, MetaData> *FixedDataSource::GetData(const QLineF& line)
{
    auto result = new QHash<QPointF,MetaData>();
    for(auto i = fixedData->keyBegin();i!=fixedData->keyEnd();i++){
        if(IsPointClose(*i,line)){
            result->insert(*i,fixedData->value(*i));
        }
    }
    return result;
}

bool FixedDataSource::IsPointClose(const QPointF& point,const QLineF& line)
{
    if(QLineF(point,line.p2()).length()>line.length()||
        QLineF(point,line.p1()).length()>line.length()) return false;

    QLineF perpendicLine(point,QPointF(point.x(),0.0));
    perpendicLine.setAngle(90+line.angle());
    QPointF intersectionPoint;
    line.intersect(perpendicLine,&intersectionPoint);

    if(QLineF(point,intersectionPoint).length()<=10){
        return true;
    }
    return false;
}

