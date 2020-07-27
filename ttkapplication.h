#ifndef TTKAPPLICATION_H
#define TTKAPPLICATION_H

/* =================================================
 * This file is part of the TTKCalendar project
 * Copyright (C) 2017 - 2020 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QGroupBox>
#include <QGridLayout>
#include <QToolButton>
#include <QCalendarWidget>

class TTKButton : public QToolButton
{
    Q_OBJECT
public:
    explicit TTKButton(QWidget *parent = nullptr);

protected:
    virtual QSize sizeHint() const override;
};


class TTKApplication : public QWidget
{
    Q_OBJECT
public:
    explicit TTKApplication(QWidget *parent = nullptr);

protected Q_SLOTS:
    void today();

protected:
    void createPreviewGroupBox();

    QGroupBox *m_groupBox;
    QGridLayout *m_layout;
    QCalendarWidget *m_calendar;

    QDate m_today;
    TTKButton *m_timeZoneButton;
    TTKButton *m_todayButton;

};

#endif
