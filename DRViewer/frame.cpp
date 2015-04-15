#include "frame.h"
#include "ui_frame.h"
#include "qcustomplot.h"
#include "reader.h"
#include "views/menudomainview.h"
#include "models/heterogenitymodel.h"
#include "views/firstinfodomainview.h"
#include "views/secondinfodomainview.h"
#include "views/thirdinfodomainview.h"
#include <models/domainmodel.h>
#include "plot.h"

Frame::Frame(QWidget *parent, ReaderInterface *reader)
    : QWidget(parent),
      ui(new Ui::Frame)
{
    ui->setupUi(this);

    ui->table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->table->horizontalHeader()->setMaximumHeight(20);
    ui->table->hide();

    QAbstractItemModel *model = new DomainModel;

    MenuDomainView *menu = new MenuDomainView(this);
    menu->setModel(model);
    createMenu(menu);

    AbstractDomainView *info = new FirstInfoDomainView(this);
    info->setModel(model);
    setFirstInfo(info);

    info = new SecondInfoDomainView(this);
    info->setModel(model);
    setSecondInfo(info);

    info = new ThirdInfoDomainView(this);
    info->setModel(model);
    setThirdInfo(info);

    readData();
    setup(ui->plot);
}

void Frame::createMenu(MenuDomainView *menu)
{
    QWidget *current = ui->menu->currentWidget();
    ui->menu->removeWidget(current);
    current->deleteLater();

    ui->menu->addWidget(menu);
    connect(menu, SIGNAL(clickToOne()), this, SLOT(oneClicked()));
    connect(menu, SIGNAL(clickToTwo()), this, SLOT(twoClicked()));
    connect(menu, SIGNAL(clickToThree()), this, SLOT(threeClicked()));
    connect(menu, SIGNAL(clickToFour()), this, SLOT(fourClicked()));
    connect(menu, SIGNAL(clickToFive()), this, SLOT(fiveClicked()));
    connect(menu, SIGNAL(clickToSix()), this, SLOT(sixClicked()));
}

void Frame::setFirstInfo(QWidget *widget)
{
    ui->info1th->addWidget(widget);
}

void Frame::setSecondInfo(QWidget *widget)
{
    ui->info2th->addWidget(widget);
}

void Frame::setThirdInfo(QWidget *widget)
{
    ui->info3th->addWidget(widget);
}

Frame::~Frame()
{
    delete ui;
}

void Frame::readData()
{
    QFile f("/home/ratuvog/input.txt");
    if (!f.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&f);
    int size = 0;
    stream >> size;
    for(int i = 0; i < size && !stream.atEnd(); i++)
    {
        double x, y;
        stream >> x >> y;
        data.first.push_back(x);
        data.second.push_back(y);
    }
}

void Frame::setup(Plot *customPlot)
{
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(data.first, data.second);

    customPlot->setup();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor(255,0,0));
    customPlot->graph(0)->setPen(pen);

    customPlot->graph(0)->rescaleAxes();
}

void Frame::oneClicked()
{

}

void Frame::twoClicked()
{

}

void Frame::threeClicked()
{

}

void Frame::fourClicked()
{

}

void Frame::fiveClicked()
{

}

void Frame::sixClicked()
{

}

void Frame::enterClicked()
{
    ui->plot->addCursor(ui->plot->cursorX());
}

void Frame::escClicked()
{
    ui->plot->removeCursor(ui->plot->currentCursor());
}

void Frame::leftClicked()
{
    ui->plot->prevCursor();
}

void Frame::rightClicked()
{
    ui->plot->nextCursor();
}

void Frame::scrollUp()
{
    ui->plot->moveUpCursor();
}

void Frame::scrollDown()
{
    ui->plot->moveDownCursor();
}

