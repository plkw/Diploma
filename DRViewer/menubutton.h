#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>

namespace Ui {
class MenuButton;
}

class MenuButton : public QWidget
{
    Q_OBJECT

public:
    explicit MenuButton(QWidget *parent = 0);
    ~MenuButton();

private:
    Ui::MenuButton *ui;
};

#endif // MENUBUTTON_H
