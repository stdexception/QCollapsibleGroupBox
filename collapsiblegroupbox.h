/*********************************************************************
 * \file   CollapsibleGroupBox.h
 * \brief  可折叠的分组框
 * 
 * \author heqingrui
 * \date   April 2025
 *********************************************************************/
#ifndef COLLAPSIBLEGROUPBOX_H
#define COLLAPSIBLEGROUPBOX_H

#include <QGroupBox>
#include <QIcon>
#include <QBoxLayout>

class QPushButton;
class QLabel;

class CollapsibleGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit CollapsibleGroupBox(const QString &title, QWidget *parent = nullptr);
    explicit CollapsibleGroupBox(QWidget *parent = nullptr);

    void setCornerWidget(QWidget *widget);

private slots:
    void toggleCollapse(bool collapsed);

private:
    QVBoxLayout *m_mainLayout;

    QHBoxLayout *m_titleLayout;
    QLabel *m_titleLabel;
    QPushButton *m_toggleButton;
    QWidget *m_contentWidget;

    bool m_isCollapsed;
    QIcon m_expandIcon;
    QIcon m_collapseIcon;
};

#endif // COLLAPSIBLEGROUPBOX_H
