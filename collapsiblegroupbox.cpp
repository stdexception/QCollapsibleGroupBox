#include "collapsiblegroupbox.h"
#include "clickablelabel.h"
#include <QTimer>
#include <QPushButton>
#include <QBoxLayout>

CollapsibleGroupBox::CollapsibleGroupBox(const QString &title, QWidget *parent)
    : QGroupBox(title, parent)
    , m_isCollapsed(false)
{
    m_collapseIcon = QIcon(":/images/down.png");
    m_expandIcon = QIcon(":/images/up.png");

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);

    QWidget *titleWidget = new QWidget(this);
    titleWidget->setObjectName("QGroupBoxTitleBar");

    m_titleLayout = new QHBoxLayout(titleWidget);
    m_titleLayout->setAlignment(Qt::AlignVCenter);

    m_toggleButton = new QPushButton(titleWidget);
    m_toggleButton->setCheckable(true);
    m_toggleButton->setChecked(m_isCollapsed);
    m_toggleButton->setStyleSheet("QPushButton { border: none; }");
    m_toggleButton->setIcon(m_isCollapsed ? m_collapseIcon : m_expandIcon);
    connect(m_toggleButton, &QPushButton::toggled, this, &CollapsibleGroupBox::toggleCollapse);

    m_titleLabel = new ClickableLabel(title, titleWidget);
    m_titleLabel->setObjectName("QGroupBoxTitle");
    connect(m_titleLabel, SIGNAL(clicked()), m_toggleButton, SLOT(click()));

    m_titleLayout->addWidget(m_toggleButton);
    m_titleLayout->addWidget(m_titleLabel);
    m_titleLayout->addStretch();

    m_contentWidget = new QWidget(this);
    m_contentWidget->setObjectName("QGroupBoxBody");
    m_mainLayout->addWidget(m_contentWidget);
    m_mainLayout->setMenuBar(titleWidget);

    QTimer::singleShot(0, this, [=]() {
        m_contentWidget->setLayout(this->layout());
        this->setLayout(m_mainLayout);
        m_titleLabel->setText(this->title());
        setTitle(QString());
    });
}

CollapsibleGroupBox::CollapsibleGroupBox(QWidget *parent)
    : CollapsibleGroupBox(QString(), parent)
{
}

void CollapsibleGroupBox::setCornerWidget(QWidget *widget)
{
    m_titleLayout->addWidget(widget);
}

void CollapsibleGroupBox::toggleCollapse(bool collapsed)
{
    m_isCollapsed = collapsed;
    m_toggleButton->setIcon(m_isCollapsed ? m_collapseIcon : m_expandIcon);
    m_contentWidget->setVisible(!m_isCollapsed);
}
