#include "clickablelabel.h"
#include <QMouseEvent>

ClickableLabel::ClickableLabel(QWidget *parent, Qt::WindowFlags f)
    : ClickableLabel(QString(), parent)
{
}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    : QLabel(text, parent)
{
    setMouseTracking(true);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}


