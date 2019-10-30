#include "renderingarea.h"
#include <QTimer>
#include <QPainter>
#include <QMessageBox>

RenderingArea::RenderingArea(QWidget *parent)
    : QWidget(parent)
{
    degrees = 0;
    QPalette pal(palette());
    pal.setColor(QPalette::Background,Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void RenderingArea::setRenderer(Renderer *renderer)
{
    this->renderer = renderer;
}

void RenderingArea::animate(){
    degrees = (degrees+3)%360;
    update();
}

void RenderingArea::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    renderer->paint(&painter, event, degrees);
    painter.end();
}




