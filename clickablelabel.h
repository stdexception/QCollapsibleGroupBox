/*********************************************************************
 * \file   clickablelabel.h
 * \brief  
 * 
 * \author heqingrui
 * \date   July 2024
 *********************************************************************/
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ClickableLabel(const QString &text, QWidget *parent = nullptr);
    virtual ~ClickableLabel();

signals:
    void clicked();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
};

#endif // CLICKABLELABEL_H
