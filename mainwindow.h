#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDoubleValidator>
#include <QString>

namespace Ui {
class MainWindow;
}

class Renderer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnToggleState_clicked();
    void on_btnUpdateConfig_clicked();

private:
    Ui::MainWindow *ui;
    Renderer *renderer;
    bool RadarIsActive;
    void btn_ToggleRadar_init();
    QTimer *timer;
    QDoubleValidator *validator;
};

#endif // MAINWINDOW_H
