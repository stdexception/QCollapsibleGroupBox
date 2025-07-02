#include "groupboxcollapser.h"
#include <QBoxLayout>
#include <QGroupBox>
#include <QToolButton>
#include <QVariant>

QGroupBoxCollapser *QGroupBoxCollapser::installIntoGroupBox(QGroupBox *groupBox, QWidget *cornerWidget, bool expanded)
{
    auto *p = new QGroupBoxCollapser(groupBox, cornerWidget);

    if (!expanded) {
        QSignalBlocker sb(p->m_toggleButton);
        p->m_toggleButton->setChecked(false);
        p->m_toggleButton->setArrowType(Qt::ArrowType::RightArrow);
        p->m_contentArea->hide();
    }

    return p;
}

QGroupBoxCollapser::QGroupBoxCollapser(QGroupBox *groupBox, QWidget *cornerWidget)
    : QObject(groupBox)
{
    auto *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    m_contentArea = new QWidget(groupBox);
    m_contentArea->setObjectName("QGroupBoxBody");
    m_contentArea->setLayout(groupBox->layout());

    mainLayout->addWidget(m_contentArea);
    groupBox->setLayout(mainLayout);

    m_toggleButton = new QToolButton(groupBox);
    m_toggleButton->setStyleSheet("QToolButton { border: none; text-align: left; font-weight: bold; padding: 0; color: #E0EDEF;}");
    m_toggleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_toggleButton->setCheckable(true);
    m_toggleButton->setText(groupBox->title());
    m_toggleButton->setArrowType(Qt::ArrowType::DownArrow);
    m_toggleButton->setChecked(true);
    m_toggleButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

    auto *titleWidget = new QWidget(groupBox);
    titleWidget->setObjectName("QGroupBoxTitle");
    titleWidget->setAttribute(Qt::WA_StyledBackground, true);

    auto *titleLayout = new QHBoxLayout(titleWidget);
    titleLayout->setContentsMargins(14, 8, 14, 8);
    titleLayout->setSpacing(3);
    titleLayout->setAlignment(Qt::AlignVCenter);
    titleLayout->addWidget(m_toggleButton);
    titleLayout->addStretch();
    if (cornerWidget)
        titleLayout->addWidget(cornerWidget);

    groupBox->layout()->setMenuBar(titleWidget);
    groupBox->setTitle("");
    groupBox->setProperty("collapsible", true); // helps to distinguish GroupBoxes in stylesheets

    connect(m_toggleButton, &QAbstractButton::clicked, this, &QGroupBoxCollapser::toggle);
}

void QGroupBoxCollapser::toggle(bool checked)
{
    m_toggleButton->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);

    if (m_toggleButton->isChecked())
        m_contentArea->show();
    else
        m_contentArea->hide();
}
