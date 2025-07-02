/*********************************************************************
 * \file   QGroupBoxCollapser.h
 * \brief  
 * 
 * \author heqingrui
 * \date   November 2024
 *********************************************************************/
#ifndef QGROUPBOXCOLLAPSER_H
#define QGROUPBOXCOLLAPSER_H

#include <QObject>

class QToolButton;
class QGroupBox;

class QGroupBoxCollapser : public QObject
{
    Q_OBJECT
public:
    static QGroupBoxCollapser *installIntoGroupBox(QGroupBox *groupBox, QWidget *cornerWidget = nullptr, bool expanded = true);

    void addWidget(QWidget *widget);

private:
    QGroupBoxCollapser(QGroupBox *groupBox, QWidget *cornerWidget = nullptr);
    void toggle(bool checked);

private:
    QWidget *m_titleWidget;
    QToolButton *m_toggleButton;
    QWidget *m_contentArea;
};

#endif // QGROUPBOXCOLLAPSER_H
