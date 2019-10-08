#include "flashinglabel.h"
#include <QPainter>

FlashingLabel::FlashingLabel(QWidget *parent)
    : QLabel(parent)
{
    m_pTimer = new QTimer();
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(onTimer()));
//    m_pTimer->start(500);

    m_color = Qt::blue;
}

void FlashingLabel::startFlashing()
{
    m_pTimer->start(500);
}

void FlashingLabel::stopFlashing()
{
    m_pTimer->stop();
}

void FlashingLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    painter.setBrush(QBrush(m_color,Qt::SolidPattern));
    QRadialGradient radialGradient(200,200,200,300,300); //辐射渐变 中心点 半径 焦点

    radialGradient.setColorAt(0, Qt::yellow);
    radialGradient.setColorAt(1, m_color);
    painter.setBrush(radialGradient);

    painter.drawRect(geometry());

    QLabel::paintEvent(event);
}

void FlashingLabel::onTimer()
{
    static bool bColorBlue = false;

    bColorBlue = !bColorBlue;

    if(bColorBlue)
        m_color = Qt::blue;
    else {
        m_color = Qt::red;
    }
    update();
}
