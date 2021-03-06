#include "AgentItem.hpp"

#include <QtGui/QPainter>

// FIXME : put an order to the constants used.
/*!
 * Paints the contents of an item in local coordinates.
 */
void AgentItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QPointF points[3] = {QPointF(0,0), QPointF(Size, -Size / 3), QPointF(Size + m_text.length() * 5.5, -Size / 3)};

    QPen pen(QBrush(Qt::blue, Qt::SolidPattern), 1, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
    painter->setPen(pen);
    painter->drawPolyline(points, 3);
    painter->setFont(QFont("Times", 9, QFont::Normal));

    if (!m_text.isEmpty())
        painter->drawText(Size, -Size / 3 - 2, m_text);
}

QRectF AgentItem::boundingRect() const
{
    return QRectF(0, -2 * Size, Size + m_text.length() * 5.5, 2 * Size);
}
