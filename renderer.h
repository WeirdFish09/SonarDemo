#ifndef RENDERER_H
#define RENDERER_H

#include <Qt>
#include<QtGui/QBrush>
#include<QtGui/QPen>
#include<QtGui/QPaintEvent>
#include<QtGui/QPainter>
#include"fixeddatasource.h"

class Renderer
{
public:
    Renderer();
    explicit Renderer(DataSource* ds);
    void paint(QPainter *painter, QPaintEvent *event, int elapsed);
    void SetScale(float scale);

private:
    QBrush background;
    QBrush circleBrush;
    QPen circlePen;
    QLineF line;
    DataSource* ds;
    float scale;
    void PaintBackground(QPainter *painter, QPaintEvent *event);
    void DrawAfterImage(QPainter *painter,const QLineF& line);
    void DrawData(QPainter *painter, const QLineF& line);
};

#endif // RENDERER_H
