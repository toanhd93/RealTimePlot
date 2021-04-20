#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPlot()
{

    ui->plot_dis->addGraph(); //blue line~reference distance
    ui->plot_dis->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_dis->graph(0)->setName("ref_dis");
    ui->plot_dis->addGraph(); //red line~lidar distance
    ui->plot_dis->graph(1)->setPen(QPen(Qt::red));
    ui->plot_dis->graph(1)->setName("Lidar_dis");
    ui->plot_dis->legend->setVisible(true);

//    ui->plot_dis->plotLayout()->addElement(1,0,ui->plot_dis->legend);0
//    ui->plot_dis->plotLayout()->setMargins(QMargins(5,0,5,5));
//    //ui->plot_dis->plotLayout()->setColumnStretchFactor(1,0.001);
//    ui->plot_dis->plotLayout()->setRowStretchFactor(1,0.001);


//    QCPLayoutGrid *sublayout = new QCPLayoutGrid;
//    ui->plot_dis->plotLayout()->addElement(1,0,sublayout);
//    sublayout->setMargins(QMargins(5,0,5,5));
//    sublayout->addElement(0,1,ui->plot_dis->legend);

//    ui->plot_dis->plotLayout()->setColumnStretchFactor(1,0.001);

    ui->plot_spd->addGraph(); //blue line~goal speed
    ui->plot_spd->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_spd->graph(0)->setName("goal speed");
    ui->plot_spd->addGraph(); //red line~leading car speed
    ui->plot_spd->graph(1)->setPen(QPen(Qt::red));
    ui->plot_spd->graph(1)->setName("lc speed");
    ui->plot_spd->addGraph(); //black line~our car speed
    ui->plot_spd->graph(2)->setPen(QPen(Qt::black));
    ui->plot_spd->graph(2)->setName("fc speed");
    //ui->plot_spd->addGraph(); //red line
    //ui->plot_spd->graph(3)->setPen(QPen(Qt::green));
    ui->plot_spd->legend->setVisible(true);

    ui->plot_g->addGraph(); //blue line~g_value
    ui->plot_g->graph(0)->setPen(QPen(Qt::blue));
    ui->plot_g->graph(0)->setName("g value");
    ui->plot_g->addGraph(); //blue line~g_value
    ui->plot_g->graph(1)->setPen(QPen(Qt::red));
    ui->plot_g->graph(1)->setName("aeb_g value");
    ui->plot_g->legend->setVisible(false);

    ui->plot_str->addGraph(); //red line~steer angle
    ui->plot_str->graph(0)->setPen(QPen(Qt::red));
    ui->plot_str->graph(0)->setName("steer angle");
    ui->plot_str->legend->setVisible(false);

    ui->plot_dis->axisRect()->setupFullAxesBox();
    ui->plot_spd->axisRect()->setupFullAxesBox();
    ui->plot_g->axisRect()->setupFullAxesBox();
    ui->plot_str->axisRect()->setupFullAxesBox();

    ui->plot_dis->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot_dis->xAxis->setDateTimeFormat("mm:ss");
    ui->plot_dis->xAxis->setAutoTickStep(false);
    ui->plot_dis->xAxis->setTickStep(5);
    ui->plot_dis->xAxis->setLabel("Time (min:second)");

    ui->plot_spd->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot_spd->xAxis->setDateTimeFormat("mm:ss");
    ui->plot_spd->xAxis->setAutoTickStep(false);
    ui->plot_spd->xAxis->setTickStep(5);
    ui->plot_spd->xAxis->setLabel("Time (min:second)");

    ui->plot_g->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot_g->xAxis->setDateTimeFormat("mm:ss");
    ui->plot_g->xAxis->setAutoTickStep(false);
    ui->plot_g->xAxis->setTickStep(5);
    ui->plot_g->xAxis->setLabel("Time (min:second)");

    ui->plot_str->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot_str->xAxis->setDateTimeFormat("mm:ss");
    ui->plot_str->xAxis->setAutoTickStep(false);
    ui->plot_str->xAxis->setTickStep(5);
    ui->plot_str->xAxis->setLabel("Time (min:second)");

    ui->plot_dis->yAxis->setRange(0, 70);
    ui->plot_dis->yAxis->setAutoTickStep(false);
    ui->plot_dis->yAxis->setTickStep(10);
    ui->plot_dis->yAxis->setLabel("Distance (m)");

    ui->plot_spd->yAxis->setRange(0, 60);
    ui->plot_spd->yAxis->setAutoTickStep(false);
    ui->plot_spd->yAxis->setTickStep(10);
    ui->plot_spd->yAxis->setLabel("Speed (km/h)");

    ui->plot_g->yAxis->setRange(-3, 3);
    ui->plot_g->yAxis->setAutoTickStep(false);
    ui->plot_g->yAxis->setTickStep(0.5);
    ui->plot_g->yAxis->setLabel("g value");

    ui->plot_str->yAxis->setRange(-10, 10);
    ui->plot_str->yAxis->setAutoTickStep(false);
    ui->plot_str->yAxis->setTickStep(2);
    ui->plot_str->yAxis->setLabel("Steer angle (Deg)");

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->plot_dis->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_dis->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot_dis->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_dis->yAxis2, SLOT(setRange(QCPRange)));

//    connect(ui->plot_spd->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_spd->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->plot_spd->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_spd->yAxis2, SLOT(setRange(QCPRange)));

//    connect(ui->plot_g->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_g->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->plot_g->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_g->yAxis2, SLOT(setRange(QCPRange)));

//    connect(ui->plot_str->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_str->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->plot_str->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot_str->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:

    QTimer *dataTimer = new QTimer(this);
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer->start(10); // Interval 0 means to refesh as fast as possible
}

void MainWindow::realtimeDataSlot()
{
    static QTime time(QTime::currentTime());
    // calculate 2 new data points:
    double key = time.elapsed()/1000.0;     //time elapsed since start of demo, in second
    static double lastPointKey = 0;
    if (key - lastPointKey > 0.002)         // at most add point every 2 ms
    {
        // add data to line:
        ui->plot_dis->graph(0)->addData(key, 50*qSin(key));
        ui->plot_dis->graph(1)->addData(key, 50*qCos(key));

        ui->plot_spd->graph(0)->addData(key, 50*qSin(key));
        ui->plot_spd->graph(1)->addData(key, 50*qCos(key));
        ui->plot_spd->graph(2)->addData(key, 25*qSin(key));

        ui->plot_g->graph(0)->addData(key, 3*qSin(key));
        ui->plot_g->graph(1)->addData(key, 1*qCos(key));

        ui->plot_str->graph(0)->addData(key, 9*qCos(key));

        // rescale value vertical axis to fit the current data:
        ui->plot_dis->graph(0)->rescaleValueAxis();
        ui->plot_dis->graph(1)->rescaleValueAxis(true);

        ui->plot_spd->graph(0)->rescaleValueAxis();
        ui->plot_spd->graph(1)->rescaleValueAxis(true);
        ui->plot_spd->graph(2)->rescaleValueAxis(true);

        ui->plot_g->graph(0)->rescaleValueAxis();

        ui->plot_str->graph(0)->rescaleValueAxis();

        lastPointKey = key;
    }
    // make key axis range scroll with the data (at constant range size of 8):
    ui->plot_dis->xAxis->setRange(key+2, 60, Qt::AlignRight);
    ui->plot_dis->replot();

    ui->plot_spd->xAxis->setRange(key+2, 60, Qt::AlignRight);
    ui->plot_spd->replot();

    ui->plot_g->xAxis->setRange(key+2, 60, Qt::AlignRight);
    ui->plot_g->replot();
//    ui->plot_g->xAxis->setRange(0,60);
//    ui->plot_g->replot();

    ui->plot_str->xAxis->setRange(key+2, 60, Qt::AlignRight);
    ui->plot_str->replot();
#if 0
    // calculate frames per second"
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key - lastFpsKey > 2)   // average Fps over 2 seconds
    {
        ui->statusBar->showMessage(
                    QString("%1 FPS, Total Data points: %2")
                    .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                    .arg(ui->plot->graph(0)->data()->size()+ui->plot->graph(1)->data()->size())
                    , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
#endif
}

