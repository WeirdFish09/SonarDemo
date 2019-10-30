#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderingarea.h"
#include "renderer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RadarIsActive = false;
    renderer = new Renderer(new FixedDataSource());
    renderer->SetScale(1);
    ui->Radar->setRenderer(renderer);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, ui->Radar, &RenderingArea::animate);

    validator = new QDoubleValidator(0.1,99.0,2);
    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->le_scale->setValidator(validator);

    btn_ToggleRadar_init();
}

void MainWindow::btn_ToggleRadar_init(){
    RadarIsActive = false;
    ui->btnToggleState->setText(tr("Start Radar"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnToggleState_clicked()
{
    if(!RadarIsActive){
        ui->btnToggleState->setText(tr("Stop Radar"));
        ui->btnToggleState->setPalette(Qt::red);
        ui->btnUpdateConfig->setEnabled(false);
        timer->start(50);
    } else {
        ui->btnToggleState->setText(tr("Start Radar"));
        ui->btnToggleState->setPalette(Qt::green);
        ui->btnUpdateConfig->setEnabled(true);
        timer->stop();
    }
    RadarIsActive = !RadarIsActive;
}

void MainWindow::on_btnUpdateConfig_clicked()
{
    renderer->SetScale(ui->le_scale->text().toFloat());
}
