#include "cursormodel.h"
#include "reflectogram.h"

CursorModel::CursorModel(Reflectogram *refl)
    : m_x(0), m_refl(refl)
{
}

double CursorModel::value() const
{
    return m_refl->value(m_x);
}

void CursorModel::setX(double value)
{
    m_x = value;
}

double CursorModel::x() const {
    return m_x;
}
