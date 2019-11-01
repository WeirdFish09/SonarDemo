#ifndef RENDERINGAREA_H
#define RENDERINGAREA_H

#include <QWidget>
#include "renderer.h"

class RenderingArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderingArea(QWidget *parent = 0);
    void setRenderer(Renderer *renderer);

signals:

public slots:
    void animate();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Renderer *renderer;
    int degrees;
};

#endif // RENDERINGAREA_H
