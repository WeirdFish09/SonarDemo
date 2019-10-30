#ifndef RENDERINGAREA_H
#define RENDERINGAREA_H

#include <QWidget>
#include "renderer.h"

class RenderingArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderingArea(QWidget *parent = 0);

signals:

public slots:
    void animate();
    void setRenderer(Renderer *renderer);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Renderer *renderer;
    int degrees;
};

#endif // RENDERINGAREA_H
