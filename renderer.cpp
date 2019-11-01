#include "renderer.h"
#include <memory>
#include <cmath>
#include <QMessageBox>

Renderer::Renderer()
{
    background = QBrush(Qt::green);
    circleBrush = QBrush(Qt::black);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(2);
    line = QLineF(QPointF(0.0,0.0),QPointF(0.0,125.0));
}

Renderer::Renderer(DataSource *ds):Renderer(){
    this->ds = ds;
}

void Renderer::paint(QPainter *painter, QPaintEvent *event, int elapsed){
    PaintBackground(painter, event);
    painter->save();
    painter->translate(event->rect().width()/2,event->rect().height()/2);
    line.setAngle(-elapsed);
    painter->drawLine(line);
    DrawData(painter, line);
    DrawAfterImage(painter,line);
    painter->restore();
}

void Renderer::SetScale(float scale)
{
    this->scale = scale;
}

void Renderer::PaintBackground(QPainter *painter, QPaintEvent *event){
    painter->setBrush(background);
    painter->drawEllipse(event->rect());
    painter->setPen(circlePen);
}

void Renderer::DrawAfterImage(QPainter *painter, const QLineF& line)
{
    QRectF rect(-125,-125,250,250);
    painter->setBrush(Qt::blue);
    painter->setOpacity(0.2);
    painter->drawPie(rect,line.angle()*16,3*16);
}

void Renderer::DrawData(QPainter *painter, const QLineF& line)
{
    QPointF scaledPointOnCircle(line.p2().x()*scale,line.p2().y()*scale);
    QLineF scaledRadius(line.p1(),scaledPointOnCircle);
    painter->setBrush(Qt::red);
    auto data = ds->GetData(line);
    for(auto i=data->keyBegin();i!=data->keyEnd();i++){
        if(QLineF(QPointF(i->x()*scale,i->y()*scale),line.p1()).length()<line.length()){
            painter->drawRect((i->x()-1)*scale,
                                (i->y()-1)*scale,3,3);
        }
    }
}
