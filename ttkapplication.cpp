#include "ttkapplication.h"

TTKButton::TTKButton(QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    setAutoRaise(true);
}

QSize TTKButton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 6;
    return size;
}


TTKApplication::TTKApplication(QWidget *parent)
    : QWidget(parent)
{
    createPreviewGroupBox();
    setWindowTitle(tr("TTKApplication"));

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(m_groupBox, 0, 0);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    m_layout->setRowMinimumHeight(0, m_calendar->sizeHint().height());
    m_layout->setColumnMinimumWidth(0, m_calendar->sizeHint().width());
    m_today = QDate(m_calendar->selectedDate());

    setLayout(layout);
}

void TTKApplication::today()
{
    m_calendar->setSelectedDate(m_today);
}

void TTKApplication::createPreviewGroupBox()
{
    m_groupBox = new QGroupBox(tr("Calendar"), this);
    m_calendar = new QCalendarWidget(this);
    m_calendar->setMinimumDate(QDate(1900, 1, 1));
    m_calendar->setMaximumDate(QDate(3000, 1, 1));
    m_calendar->setGridVisible(true);

    m_todayButton = new TTKButton(this);
    m_todayButton->setIcon(QIcon(":/data/images/today.ico"));
    m_todayButton->setToolTip(tr("Today"));
    connect(m_todayButton, SIGNAL(clicked()), SLOT(today()));

    m_timeZoneButton = new TTKButton(this);
    m_timeZoneButton->setIcon(QIcon(":/data/images/flag-cn.ico"));

    m_layout = new QGridLayout;
    m_layout->addWidget(m_calendar, 0, 0, Qt::AlignCenter);

    QHBoxLayout* showLayout = new QHBoxLayout;
    showLayout->addWidget(m_timeZoneButton);
    showLayout->addStretch();
    showLayout->addWidget(m_todayButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(m_layout);
    mainLayout->addLayout(showLayout);
    m_groupBox->setLayout(mainLayout);
}
