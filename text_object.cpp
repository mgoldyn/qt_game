#include "text_object.h"
#include "QFont"

text::text(QGraphicsItem *parent,
                         const QString name,
                         const unsigned int colour,
                         const int font_size)
{
    this->name = name;
    if(name == "Life:")
    {
        this->setPos(this->x(), this->y() + 25);
        value = 2;
    }
    else
    {
        this->value = 0;
    }

    setPlainText(QString(name) + QString::number(value)); // Score: 0
    setDefaultTextColor(colour);
    setFont(QFont("times", font_size));

}

int text::get_value()
{
    return value;
}

int text::change_value(int change)
{
    value += change;
    setPlainText(QString(this->name) + QString::number(this->value));
    return this->value;
}
