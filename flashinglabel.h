#ifndef FLASHINGLABEL_H
#define FLASHINGLABEL_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QColor>

class FlashingLabel : public QLabel
{
    Q_OBJECT
public:
    explicit FlashingLabel(QWidget *parent = nullptr);

    void startFlashing();
    void stopFlashing();
signals:

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QTimer* m_pTimer;
    QColor m_color;

public slots:
    void onTimer();

};

#endif // FLASHINGLABEL_H
