/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *locationLabel;
    QComboBox *locationComboBox;
    QTimeEdit *lectureStartTimeEdit;
    QTimeEdit *lectureEndTimeEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *lectureEndLabel;
    QLabel *lectureStartLabel;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 663);
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 651, 611));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 651, 611));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(770, 310, 531, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(770, 0, 531, 271));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        locationLabel = new QLabel(formLayoutWidget);
        locationLabel->setObjectName("locationLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, locationLabel);

        locationComboBox = new QComboBox(formLayoutWidget);
        locationComboBox->setObjectName("locationComboBox");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, locationComboBox);

        lectureStartTimeEdit = new QTimeEdit(formLayoutWidget);
        lectureStartTimeEdit->setObjectName("lectureStartTimeEdit");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lectureStartTimeEdit);

        lectureEndTimeEdit = new QTimeEdit(formLayoutWidget);
        lectureEndTimeEdit->setObjectName("lectureEndTimeEdit");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lectureEndTimeEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout_2->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);

        lectureEndLabel = new QLabel(formLayoutWidget);
        lectureEndLabel->setObjectName("lectureEndLabel");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, lectureEndLabel);

        lectureStartLabel = new QLabel(formLayoutWidget);
        lectureStartLabel->setObjectName("lectureStartLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lectureStartLabel);

        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName("pushButton");

        formLayout_2->setWidget(4, QFormLayout::SpanningRole, pushButton);

        pushButton_4 = new QPushButton(formLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        formLayout_2->setWidget(5, QFormLayout::SpanningRole, pushButton_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "UC Mapper", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Remove location", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        locationLabel->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        lectureEndLabel->setText(QCoreApplication::translate("MainWindow", "Lecture End", nullptr));
        lectureStartLabel->setText(QCoreApplication::translate("MainWindow", "Lecture Start", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add location", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Route", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
